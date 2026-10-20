#include<iostream>
#include<vector>
#include<iomanip>
#include<string>
using namespace std;

class Xe{
	protected:
		string bienSo;
		float trongLuong;
	public:
		Xe(){}
		Xe(string bienSo, float trongLuong) : bienSo(bienSo), trongLuong(trongLuong){}
		
		virtual void nhap(){
			cout << "Nhap bien so:";		getline(cin, bienSo);
			cout << "Nhap trong luong";		cin >> trongLuong;
		}
		
		virtual void xuat(){
			cout << left 
				 << setw(12) << bienSo
				 << setw(16) << trongLuong;
		}
};

class XeCon : public Xe{
	private:
		int soChoNgoi;
	public:
		XeCon() : Xe(){}
		XeCon(string bienSo, float trongLuong, int soChoNgoi) : Xe(bienSo, trongLuong), soChoNgoi(soChoNgoi){}
		
		void nhap() override{
			Xe::nhap();
			cout << "Nhap so cho ngoi:";		cin >> soChoNgoi;	cin.ignore();
		}
		
		void xuat() override{
			Xe::xuat();
			cout << setw(16) << soChoNgoi << endl;
		}
		
		float getTrongLuong(){
			return trongLuong;
		}
		
		int getSoChoNgoi(){
			return soChoNgoi;
		}
};

void nhapDanhSach(vector<XeCon> &danhSach, int soLuong){
	for(int i=0; i<soLuong; i++){
		danhSach[i].nhap();
	}
}

void inTieuDe(){
	cout << left
		 << setw(12) << "Bien So"
		 << setw(16) << "Trong Luong"
		 << setw(16) << "So Cho Ngoi" << endl;
}

void xuatDanhSach(vector<XeCon> &danhSach){
	inTieuDe();
	for(int i=0; i<danhSach.size(); i++){
		danhSach[i].xuat();
	}
}

vector<XeCon> locDanhSach(vector<XeCon> &danhSach){
	vector<XeCon> danhSachLoc;
	for(int i=0; i<danhSach.size(); i++){
		if(danhSach[i].getTrongLuong() < 1 && danhSach[i].getSoChoNgoi() <= 5){
			danhSachLoc.push_back(danhSach[i]);
		}
	}
	return danhSachLoc;
}

int demSoLuongXe(vector<XeCon> &danhSach, float x){
	int dem = 0;
	for(int i=0; i<danhSach.size(); i++){
		if(danhSach[i].getTrongLuong() < x)	dem ++;
	}
	return dem;
}

void maxChoNgoi(vector<XeCon> &danhSach){
	int max = danhSach[0].getSoChoNgoi();
	for(int i=0; i<danhSach.size(); i++){
		if(danhSach[i].getSoChoNgoi() > max)	max = danhSach[i].getSoChoNgoi();
	}
	
	inTieuDe();
	for(int i=0; i<danhSach.size(); i++){
		if(danhSach[i].getSoChoNgoi() == max){
			danhSach[i].xuat();
		}
	}
}

int main(){
	int soLuong;
	cout << "Nhap so luong:";	cin >> soLuong;		cin.ignore();
	
	vector<XeCon> danhSach(soLuong);
	
	nhapDanhSach(danhSach, soLuong);
	
	vector<XeCon> danhSachLoc = locDanhSach(danhSach);
	cout << "\nDanh sach xe thoa man la:" << endl;
	xuatDanhSach(danhSachLoc);
	
	float x;	cout << "Nhap x:";	cin >> x;
	
	cout << "\nSo luong xe co trong luong nho hon " << x << " la:" << demSoLuongXe(danhSach,x);
	
	cout << "\nDanh sach xe co nhieu cho ngoi nhat la:" << endl;
	maxChoNgoi(danhSach);
	
	return 0;
}
