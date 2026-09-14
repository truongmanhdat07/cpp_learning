#include<iostream>
#include<iomanip>
#include<fstream>
#include<vector>
using namespace std;


class NhanVien{
	protected:
		string maNV;
		string hoTen;
		int loaiHopDong;
	public:
		NhanVien() : maNV(""), hoTen(""), loaiHopDong(0){}
		NhanVien(string maNV, string hoTen, int loaiHopDong);
		virtual ~NhanVien(){}
		
		virtual double getLuong() = 0;
		string getMa();
		
		virtual void nhap();
		virtual void xuat(ostream &out);
		
};

class ThoiVu : public NhanVien{
	private:
		int soNgayCong;
		double donGia;
	public:
		ThoiVu() : NhanVien("", "", 1), soNgayCong(0), donGia(0.0f){};
		ThoiVu(string maNV, string hoTen, int loaiHopDong, int soNgayCong, double donGia);
		
		double getLuong() override;
		void nhap() override;
		void xuat(ostream &out) override;
};

class ChinhThuc : public NhanVien{
	private:
		int thamNien;
		float heSoLuong;
	public:
		ChinhThuc() : NhanVien("", "", 2), heSoLuong(0.0f), thamNien(0){}
		ChinhThuc(string maNV, string hoTen, int loaiHopDong,float heSoLuong, int thamNien);
		
		double getLuong() override;
		void nhap() override;
		void xuat(ostream &out) override;
};



void nhapDanhSachNhanVien(vector<NhanVien*> &danhSachNhanVien, int soLuongNhanVien);
void inTieuDe(ostream &out);
void xuatDanhSachNhanVien(ostream &out, const vector<NhanVien*> &danhSachNhanVien);
double thongKeLuong(const vector<NhanVien*> &danhSachNhanVien);
int timKiemTheoMa(const vector<NhanVien*> &danhSachNhanVien, const string maCanTim);
void timKiemNhanVienTheoMa(const vector<NhanVien*> &danhSachNhanVien);
vector<NhanVien*> locDanhSach(const vector<NhanVien*> &danhSachNhanVien, double luong);
void xuLyLocDanhSachTheoLuong(const vector<NhanVien*> &danhSachNhanVien);





NhanVien::NhanVien(string maNV, string hoTen, int loaiHopDong){
	this->maNV = maNV;
	this->hoTen = hoTen;
	this->loaiHopDong = loaiHopDong;
}

void NhanVien::nhap(){
	cout << "Nhap ma nhan vien:";	getline(cin, maNV);
	cout << "Nhap ho va ten:";		getline(cin, hoTen);
}

void NhanVien::xuat(ostream &out){
	out << left << fixed << setprecision(0)
		<< setw(15) << maNV
		<< setw(25) << hoTen
		<< setw(12) << loaiHopDong;
}

string NhanVien::getMa(){
	return maNV;
}




ThoiVu::ThoiVu(string maNV, string hoTen, int loaiHopDong, int soNgayCong, double donGia) 
	   : NhanVien(maNV, hoTen, loaiHopDong){
				
	this->soNgayCong = soNgayCong;
	this->donGia = donGia;
}

double ThoiVu::getLuong(){
	double luong = soNgayCong * donGia ;
	
	if(soNgayCong >= 25)	luong += 2500000;
	
	return luong;
}

void ThoiVu::nhap(){
	NhanVien::nhap();
	
	do{
		cout << "Nhap so ngay cong:";	cin >> soNgayCong;
		if(soNgayCong < 0 || soNgayCong > 31)	cout << "\nSo ngay cong khong hop le, vui long nhap lai!";
	}while(soNgayCong < 0 || soNgayCong > 31);

	cout << "Nhap don gia:";		cin >> donGia;	cin.ignore();
}

void ThoiVu::xuat(ostream &out){
	NhanVien::xuat(out);
	out << setw(12) << soNgayCong
		<< setw(12) << donGia 
		<< setw(15) << getLuong() << endl;
}



ChinhThuc::ChinhThuc(string maNV, string hoTen, int loaiHopDong, float heSoLuong, int thamNien) 
		  :NhanVien(maNV, hoTen, loaiHopDong){
		  	
	this->heSoLuong = heSoLuong;
	this->thamNien = thamNien;
}

double ChinhThuc::getLuong(){
	double luongCoBan = 1050000;
	double phuCap = (thamNien >= 3) ? (luongCoBan * 1.2) : (luongCoBan * 1.0);
	double luong = (luongCoBan * heSoLuong) + phuCap;
	
	return luong;
}

void ChinhThuc::nhap(){
	NhanVien::nhap();
	
	cout << "Nhap he so luong:";	cin >> heSoLuong;
	do{
		cout << "Nhap tham nien:";	cin >> thamNien;
		if(thamNien < 0)	cout << "\nTham nien khong hop le, vui long nhap lai!";
	}while(thamNien < 0);
	
	cin.ignore();
}

void ChinhThuc::xuat(ostream &out){
	NhanVien::xuat(out);
	out << setw(12) << thamNien
		<< setw(12) << fixed << setprecision(2) << heSoLuong
		<< setw(15) << fixed << setprecision(0) << getLuong() << endl;
}













int main(){
	int soLuongNhanVien;
	cout << "Nhap so luong nhan vien:";		cin >> soLuongNhanVien;		cin.ignore();
	
	vector<NhanVien*> danhSachNhanVien;
	
	nhapDanhSachNhanVien(danhSachNhanVien, soLuongNhanVien);
	
	cout << "\nDanh sach nhan vien vua nhap la:" << endl;
	xuatDanhSachNhanVien(cout, danhSachNhanVien);
	
	cout << "\nTong luong ma cong ty TOTO phai tra cho nhan vien trong 1 thang la:" << thongKeLuong(danhSachNhanVien);
	
	timKiemNhanVienTheoMa(danhSachNhanVien);
	
	xuLyLocDanhSachTheoLuong(danhSachNhanVien);
	
	return 0;
}

void nhapDanhSachNhanVien(vector<NhanVien*> &danhSachNhanVien, int soLuongNhanVien){
	for(int i=0; i<soLuongNhanVien; i++){
		int chon ;
		
		cout << "\nNhap thong tin cho nhan vien thu " << i+1 << ":";
				
		do{
			cout << "\nNhap loai hop dong ( 1 = thoi vu, 2 = chinh thuc ) :";
			cin >> chon;	cin.ignore();
			if(chon != 1 && chon != 2)	cout << "\nLua chon khong hop le, vui long chon lai!";
		}while(chon != 1 && chon != 2);

		NhanVien *nv;
		
		if(chon == 1)	nv = new ThoiVu();
		else			nv = new ChinhThuc();
		
		nv->nhap();
		danhSachNhanVien.push_back(nv);
	}
}

void inTieuDe(ostream &out){
	out << left
		<< setw(15) << "Ma Nhan Vien"
		<< setw(25) << "Ho Va Ten"
		<< setw(12) << "Hop Dong"
		<< setw(12) << "Thong So 1"
		<< setw(12) << "Thong So 2"
		<< setw(15) << "Luong" << endl;
}

void xuatDanhSachNhanVien(ostream &out, const vector<NhanVien*> &danhSachNhanVien){
	inTieuDe(out);
	for(int i=0; i<danhSachNhanVien.size(); i++){
		danhSachNhanVien[i]->xuat(out);
	}
}

double thongKeLuong(const vector<NhanVien*> &danhSachNhanVien){
	double tong = 0;
	
	for(int i=0; i<danhSachNhanVien.size(); i++){
		tong += danhSachNhanVien[i]->getLuong();
	}
	
	return tong;
}

int timKiemTheoMa(const vector<NhanVien*> &danhSachNhanVien, const string maCanTim){
	for(int i=0; i<danhSachNhanVien.size(); i++){
		if(danhSachNhanVien[i]->getMa() == maCanTim)	return i;
	}
	
	return -1;
}

void timKiemNhanVienTheoMa(const vector<NhanVien*> &danhSachNhanVien){
	string maCanTim;
	cout << "\nNhap ma nhan vien can tim:";
	cin >> ws;
	getline(cin, maCanTim);
	
	int viTri = timKiemTheoMa(danhSachNhanVien, maCanTim);
	
	if(viTri != -1){
		cout << "\nDa tim thay nhan vien co ma " << maCanTim << ":" << endl;
		inTieuDe(cout);
		danhSachNhanVien[viTri]->xuat(cout);
	}
	else	cout << "\nKhong tim thay nhan vien co ma la " << maCanTim << endl;
}

vector<NhanVien*> locDanhSach(const vector<NhanVien*> &danhSachNhanVien, double luong){
	vector<NhanVien*> danhSach;
	
	for(int i=0; i<danhSachNhanVien.size(); i++){
		if(danhSachNhanVien[i]->getLuong() >= luong){
			danhSach.push_back(danhSachNhanVien[i]);
		}
	}
	
	return danhSach;
}

void xuLyLocDanhSachTheoLuong(const vector<NhanVien*> &danhSachNhanVien){
	double luong;
	cout << "\nNhap luong toi thieu de loc:";
	cin >> luong;	cin.ignore();
	
	vector<NhanVien*> danhSach = locDanhSach(danhSachNhanVien, luong);
	
	cout << "\nDanh sach nhan vien co luong cao hon " << luong << " la:" << endl;
	xuatDanhSachNhanVien(cout, danhSach);
}
