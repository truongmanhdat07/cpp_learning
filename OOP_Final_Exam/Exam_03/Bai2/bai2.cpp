#include<iostream>
#include<iomanip>
#include<vector>

using namespace std;

class Xe{
	protected:
		string bienSo;
		string mau;
	public:
		Xe(){}
		Xe(string bienSo, string mau) : bienSo(bienSo), mau(mau){}
		
		string getMau(){
			return mau;
		}
		
		virtual void nhap(){
			cout << "\nNhap bien so xe:";	getline(cin, bienSo);
			cout << "Nhap mau xe:";			getline(cin, mau);
		}
		
		virtual void xuat(){
			cout << left
				 << setw(15) << bienSo
				 << setw(10) << mau;
		}
};

class Oto : public Xe{
	private:
		float taiTrong;
		int soCho;
	public:
		Oto(){}
		Oto(string bienSo, string mau, float taiTrong, int soCho) : Xe(bienSo, mau), taiTrong(taiTrong), soCho(soCho){}
		
		float getTaiTrong(){
			return taiTrong;
		}
		
		int getSoCho(){
			return soCho;
		}
		
		void nhap() override{
			Xe::nhap();
			cout << "Nhap tai trong xe:";	cin >> taiTrong;
			cout << "Nhap so cho ngoi:";	cin >> soCho;	cin.ignore();
		}
		
		void xuat() override{
			Xe::xuat();
			cout << setw(15) << fixed << setprecision(2) << taiTrong
				 << setw(15) << soCho << endl;
		}
};

class XeMay : public Xe{
	private:
		int phanKhoi;
	private:
		XeMay(){}
		XeMay(string bienSo, string mau, int phanKhoi): Xe(bienSo, mau), phanKhoi(phanKhoi){};
		
		int getPhanKhoi(){
			return phanKhoi;
		}
		
		void nhap() override{
			Xe::nhap();
			cout << "Nhap phan khoi xe:";	cin >> phanKhoi;	cin.ignore();
		}
		
		void xuat() override{
			Xe::xuat();
			cout << setw(15) << phanKhoi << endl;
		}
};

template <typename T>
void nhapDanhSach(vector<T> &ds, int soLuong){
	for(int i=0; i<soLuong; i++){
		cout << "Nhap thong tin xe thu " << i+1 << ":";
		ds[i].nhap();
	}
}

void xuatDanhSachOto(vector<Oto> &danhSachOto){
	int dem = 0;
	for(int i=0; i<danhSachOto.size(); i++){
		if(danhSachOto[i].getSoCho() == 7){
			danhSachOto[i].xuat();
			dem++;
		}
	}
	if(dem == 0)	cout << "\nKhong co xe nao co 7 cho ";
}

float maxTaiTrong(vector<Oto> &danhSachOto){
	float max = danhSachOto[0].getTaiTrong();
	for(int i=1; i<danhSachOto.size(); i++){
		if(danhSachOto[i].getTaiTrong() > max)	max = danhSachOto[i].getTaiTrong();
	}
	return max;
}

float tongTaiTrong(vector<Oto> &danhSachOto){
	float tong = 0;
	for(int i=0; i<danhSachOto.size(); i++){
		if(danhSachOto[i].getSoCho() == 4)	tong += danhSachOto[i].getTaiTrong();
	}
	return tong;
}

float maxTaiTrongMauDo(vector<Oto> &danhSachOto){
	float max = -1;
	for(int i=0; i<danhSachOto.size(); i++){
		if(danhSachOto[i].getMau() == "do")		max = danhSachOto[i].getTaiTrong();
	}
	
	if(max == -1){
		cout << "\nKhong co xe mau do!";
		return -1;
	}
	
	for(int i=0; i<danhSachOto.size(); i++){
		if(danhSachOto[i].getMau() == "do"){
			if(danhSachOto[i].getTaiTrong() > max)	max = danhSachOto[i].getTaiTrong();
		}
	}
	return max;
}


int main(){
	int n,m;
	cout << "Nhap so luong xe oto:";	cin >> n;	cin.ignore();
	
	vector<Oto> danhSachOto(n);
	
	nhapDanhSach(danhSachOto, n);
	
	cout << "\nDanh sach oto:" << endl;
	xuatDanhSachOto(danhSachOto);
	
	cout << "\nMax tai trong:" << maxTaiTrong(danhSachOto);
	cout << "\nTong tai trong xe 4 cho ngoi = " << tongTaiTrong(danhSachOto);
	cout << "\nTai trong lon nhat cua xe mau do la:" << maxTaiTrongMauDo(danhSachOto);
	
	
	
	return 0;
}
