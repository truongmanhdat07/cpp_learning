#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <algorithm>
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
		int getNamSinh();
		
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

vector<NV*> locDanhSachTheoLuong(vector<NV*> &danhSach, double luong);
void xuLyLocDanhSachTheoLuong(vector<NV*> &danhSach);

void sapXepGiamDanTheoLuong(vector<NV*> &danhSach);

void xuatFile(vector<NV*> &danhSach, string tenFileOutput);

void giaiPhongBoNho(vector<NV*> &ds);


// NV
string NV::getMa(){
	return ma;
}

int NV::getNamSinh(){
	return namSinh;
}

void NV::nhap(){
    cout << "Nhap ma nhan vien: ";    getline(cin, ma);
    cout << "Nhap ho va ten: ";       getline(cin, ten);
    do {
        cout << "Nhap nam sinh (<= 2006): "; cin >> namSinh;
        if(namSinh > 2006) cout << "Nam sinh khong hop le! Vui long nhap lai.\n";
    } while(namSinh > 2006);
    
    cout << "Nhap luong co ban: ";    cin >> luongCB;    cin.ignore();
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
    do {
        cout << "Nhap doanh so ban hang (>= 0): "; cin >> doanhSo; cin.ignore();
        if(doanhSo < 0) cout << "Doanh so phai >= 0! Vui long nhap lai.\n";
    } while(doanhSo < 0);
    
    cout << "Nhap cap bac: "; getline(cin, capBac);
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
    do {
        cout << "Nhap so don thanh cong (>= 0): "; cin >> soDon;
        if(soDon < 0) cout << "So don phai >= 0! Vui long nhap lai.\n";
    } while(soDon < 0);
    
    cout << "Nhap don gia: "; cin >> donGia; cin.ignore();
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
	
	xuLyLocDanhSachTheoLuong(danhSach);
	
	sapXepGiamDanTheoLuong(danhSach);
	
	xuatFile(danhSach, "nhansu.txt");
	
	giaiPhongBoNho(danhSach);
	
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
	
	
	if(viTri != -1){
		cout << "\nTim thay nhan vien co ma " << ma << ":" << endl;
		inTieuDe(cout);
		danhSach[viTri]->xuat(cout);
	}
	else	cout << "\nKhong tim thay nhan vien co ma " << ma;
}

vector<NV*> locDanhSachTheoLuong(vector<NV*> &danhSach, double luong){
	vector<NV*> danhSachLoc;
	for(int i=0; i<danhSach.size(); i++){
		if(danhSach[i]->getLuong() >= luong ){
			danhSachLoc.push_back(danhSach[i]);
		}
	}
	return danhSachLoc;
}

void xuLyLocDanhSachTheoLuong(vector<NV*> &danhSach){
	double luong;
	cout << "\nNhap muc luong can loc: ";	cin >> luong;	cin.ignore();
	
	vector<NV*> danhSachLoc = locDanhSachTheoLuong(danhSach, luong);
	
	if(danhSachLoc.empty())	cout << "\nKhong co nhan vien nao co luong >= " << luong;
	else{
		cout << "\nDanh sach nhan vien co luong >= " << luong << " la: " << endl;
		xuatDanhSach(cout, danhSachLoc);
	}
}

bool cmp(NV* nv1, NV* nv2) {
    if (nv1->getLuong() != nv2->getLuong()) {
        return nv1->getLuong() > nv2->getLuong(); // luong giam dan = true
    }
    return nv1->getNamSinh() < nv2->getNamSinh();
}

void sapXepGiamDanTheoLuong(vector<NV*> &danhSach){
	sort(danhSach.begin(), danhSach.end(), cmp);
}

void xuatFile(vector<NV*> &danhSach, string tenFileOutput){
	ofstream fileOut(tenFileOutput);
	if(!fileOut){
		cerr << "\nKhong the mo file " << tenFileOutput;
		return;
	}
	
	fileOut << "\nDanh sach nhan vien sau khi sap xep la:" << endl;
	xuatDanhSach(fileOut, danhSach);
}

void giaiPhongBoNho(vector<NV*> &ds){
	for(int i=0; i<ds.size(); i++)		delete ds[i];
}
