#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
using namespace std;


class NV{
	protected:
		string ma = "";
		string ten = "";
		int namSinh = 0;
		double luongCB = 0.0f;
		int loaiHopDong = 0;
	public:
		NV(){}
		NV(string ma, string ten, int namSinh, double luongCB, int loaiHopDong) :
		   ma(ma), ten(ten), namSinh(namSinh), luongCB(luongCB), loaiHopDong(loaiHopDong){}
		
		virtual ~NV(){};
		
		virtual double getLuong() = 0;
		string getMa();
		
		virtual void nhap();
		virtual void xuat(ostream &os);
		
};


class NVKD : public NV {
	private:
		int doanhSo = 0;
		string capBac = "";
	public:
		NVKD(){}
		NVKD(string ma, string ten, int namSinh, double luongCB, int loaiHopDong, int doanhSo, string capBac)
            : NV(ma, ten, namSinh, luongCB, loaiHopDong), doanhSo(doanhSo), capBac(capBac){}
		
		double getLuong() override;
		void nhap() override;
		void xuat(ostream &os) override;
};


class NVGV : public NV{
	private:
		int soDon = 0;
		double donGia = 0.0f;
	public:
		NVGV(){}
		NVGV(string ma, string ten, int namSinh, double luongCB, int loaiHopDong, int soDon, double donGia)
            : NV(ma, ten, namSinh, luongCB, loaiHopDong), soDon(soDon), donGia(donGia){}
		
		double getLuong() override;
		void nhap() override;
		void xuat(ostream &os) override;
};



void inTieuDe(ostream &os);
void nhapDanhSach(vector<NV*> &danhSach, int soLuong);
void xuatDanhSach(ostream &os, vector<NV*> &danhSach);
double tongLuong(vector<NV*> &danhSach);

int timKiemTheoMa(vector<NV*> &danhSach, string ma);
void xuLyTimKiemTheoMa(vector<NV*> &danhSach);




// NV
string NV::getMa(){
	return ma;
}


void NV::nhap(){
	cout << "Nhap ma nhan vien:";	getline(cin, ma);
	cout << "Nhap ho va ten:";		getline(cin, ten);
	cout << "Nhap nam sinh:";		cin >> namSinh;		
	cout << "Nhap luong co ban:";	cin >> luongCB;		cin.ignore();
}

void NV::xuat(ostream &os){
    os << left << fixed << setprecision(0)
        << setw(12) << ma
        << setw(25) << ten
        << setw(12) << namSinh
        << setw(15) << luongCB;
}






// NVKD

double NVKD::getLuong(){
	double luongTL = luongCB + doanhSo * 0.05 ;
	
	if(capBac == "xuat sac" || capBac == "Xuat sac" ) return luongTL + 2000000;
	
	return luongTL;
}

void NVKD::nhap(){
	NV::nhap();
	cout << "Nhap doanh so ban hang:";		cin >> doanhSo;		cin.ignore();
	cout << "Nhap cap bac:";				getline(cin, capBac);
}

void NVKD::xuat(ostream &os){
    NV::xuat(os);
    os << setw(18) << doanhSo
        << setw(15) << capBac
        << setw(18) << getLuong() << endl;
}






//NVGV

double NVGV::getLuong(){
	double luongTL = luongCB + soDon * donGia;
	
	if(soDon >= 250)	return luongTL * 1.1;
	
	return luongTL;
}

void NVGV::nhap(){
	NV::nhap();
	cout << "Nhap so don thanh cong:";		cin >> soDon;
	cout << "Nhap don gia:";				cin >> donGia;		cin.ignore();
}

void NVGV::xuat(ostream &os){
    NV::xuat(os);
    os << setw(18) << soDon
        << setw(15) << donGia
        << setw(18) << getLuong() << endl;
}







int main(){
	int soLuong;	cout << "Nhap so luong nhan vien:";		cin >> soLuong;
	vector<NV*> danhSach;

	nhapDanhSach(danhSach, soLuong);
	
	cout << "\nDanh sach nhan vien vua nhap la:" << endl;
	xuatDanhSach(cout, danhSach);
	
	cout << "\nTong luong cong ty can phan chi tra cho nhan su la: " << tongLuong(danhSach);
	
	xuLyTimKiemTheoMa(danhSach);
	
	return 0;
}


void inTieuDe(ostream &os){
    os << left
        << setw(12) << "Ma NV"
        << setw(25) << "Ho Ten"
        << setw(12) << "Nam Sinh"
        << setw(15) << "Luong CB"
        << setw(18) << "Thong So 1"
        << setw(15) << "Thong So 2"
        << setw(18) << "Luong TL" << endl;
}

void nhapDanhSach(vector<NV*> &danhSach, int soLuong){
	for(int i=0; i<soLuong; i++){
		int chon;
		cout << "Nhap loai hop dong:";	cin >> chon;	cin.ignore();
		if(chon == 1){
			NV* nv = new NVKD;
			nv->nhap();
			danhSach.push_back(nv);
		}
		else{
			NV* nv = new NVGV;
			nv->nhap();
			danhSach.push_back(nv);
		}

	}
}

void xuatDanhSach(ostream &os, vector<NV*> &danhSach){
	inTieuDe(os);
	for(int i=0; i<danhSach.size(); i++){
		danhSach[i]->xuat(os);
	}
}

double tongLuong(vector<NV*> &danhSach){
	double tong = 0;
	
	for (size_t i = 0; i < danhSach.size(); i++) {
    tong += danhSach[i]->getLuong();
	}
	
	return tong;
}

int timKiemTheoMa(vector<NV*> &danhSach, string ma){
	for(int i=0; i<danhSach.size(); i++){
		if(danhSach[i]->getMa() == ma)	return i;
	}
	return -1;
}

void xuLyTimKiemTheoMa(vector<NV*> &danhSach){
	string ma;
	cout << "\nNhap ma nhan vien can tim:";		getline(cin, ma);
	
	int viTri = timKiemTheoMa(danhSach, ma);
	
	if(viTri = -1)	cout << "\nKhong tim thay nhan vien co ma " << ma;
	else{
		cout << "\nTim thay nhan vien co ma " << ma << ":" << endl;
		inTieuDe(cout);
		danhSach[viTri]->xuat(cout);
	}
}
