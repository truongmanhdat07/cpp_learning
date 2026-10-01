#include <iostream>
#include<vector>
using namespace std;

class CTY{
	private:
		string ten;
		int ntl;
	public:
		void nhap(){
			cout << "Nhap ten cty:";			getline(cin, ten);
			cout << "Nhap nam thanh lap:";		cin >> ntl;		cin.ignore();
		}
		void xuat(){
			cout << ten << " | " << ntl << " | ";
		}
		
		int getNTL(){	return ntl;}
		string getTen(){return ten;}
};


class CTYPM : public CTY{
	private:
		int sltv;
	public:
		void nhap(){
			CTY::nhap();
			cout << "Nhap so lap trinh vien:";		cin >> sltv;	cin.ignore();
		}
		void xuat(){
			CTY::xuat();
			cout << sltv << endl;
		}
		
		int getSLTV(){ return sltv; }
};


class CTYVT : public CTY{
	private:
		int soto;
	public:
		void nhap(){
			CTY::nhap();
			cout << "Nhap so oto:";		cin >> soto;			cin.ignore();
		}
		void xuat(){
			CTY::xuat();
			cout << soto << endl;
		}
		
		int getSoto(){ return soto; }
};

template <typename T>
void nhapDanhSach(vector<T> &ds, int soLuong){
	for(int i=0; i<soLuong; i++){
		cout << "\nNhap thong tin CTY thu " << i+1 <<":" << endl;
		ds[i].nhap();
	}
}

template <typename T>
void xuatDanhSach(vector<T> &ds){
	for(int i=0; i<ds.size(); i++){
		cout << "\nThong tin CTY thu " << i+1 << ":" << endl;
		ds[i].xuat();
	}
}

void ctypmThoaMan(vector<CTYPM> &ds){
	bool coCTY = false;
	
	for(int i=0; i<ds.size(); i++){
		if(ds[i].getNTL() > 2000 && ds[i].getSLTV() > 20){
			coCTY = true;
			ds[i].xuat();
		}
	}
	if(!coCTY)	cout << "\nKhong co CTYPM nao thoa man!";
}

void ctyvtThoaMan(vector<CTYVT> &ds){
	bool coCTY = false;
	
	for(int i=0; i<ds.size(); i++){
		if(ds[i].getNTL() < 2000 && ds[i].getSoto() < 10){
			coCTY = true;
			ds[i].xuat();
		}
	}
	if(!coCTY)	cout << "\nKhong co CTYVT nao thoa man!";
}

void timKiemChung(vector<CTYPM> &dsPM, vector<CTYVT> &dsVT, string tenCanTim){
	bool timThay = false;

	for(int i = 0; i < dsPM.size(); i++){
		if(dsPM[i].getTen() == tenCanTim){
			dsPM[i].xuat();
			timThay = true;
		}
	}

	for(int i = 0; i < dsVT.size(); i++){
		if(dsVT[i].getTen() == tenCanTim){
			dsVT[i].xuat();
			timThay = true;
		}
	}

	if(!timThay){
		cout << "Khong tim thay cty co ten " << tenCanTim << endl;
	}
}

int main(){
	int m,n;
	cout << "Nhap so cty phan mem: ";	cin >> n;	
	cout << "Nhap so cty van tai: ";	cin >> m;	cin.ignore();
	
	vector<CTYPM> ctypm(n);
	vector<CTYVT> ctyvt(m);
	
	cout << "\nNhap DS CTYPM:";
	nhapDanhSach(ctypm, n);
	cout << "\nDS CTYPM vua nhap:" << endl;
	xuatDanhSach(ctypm);
	
	cout << "\nNhap DS CTYVT:";
	nhapDanhSach(ctyvt, m);
	cout << "\nDS CTYVT vua nhap:" << endl;
	xuatDanhSach(ctyvt);
	
	cout << "\nDS CTYPM thoa man la:" << endl;
	ctypmThoaMan(ctypm);
	
	cout << "\nDS CTYVT thoa man la:" << endl;
	ctyvtThoaMan(ctyvt);
	
	string tenCanTim;
	cout << "\nNhap ten cty can tim:";		getline(cin, tenCanTim);
	
	timKiemChung(ctypm, ctyvt, tenCanTim);
	
	return 0;
}
