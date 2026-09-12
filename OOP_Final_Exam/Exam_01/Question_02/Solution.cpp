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
		float heSoLuong;
		int thamNien;
	public:
		ChinhThuc() : NhanVien("", "", 2), heSoLuong(0.0f), thamNien(0){}
		ChinhThuc(string maNV, string hoTen, int loaiHopDong,float heSoLuong, int thamNien);
		
		double getLuong() override;
		void nhap() override;
		void xuat(ostream &out) override;
};



void nhapDanhSachNhanVien(vector<NhanVien*> &danhSachNhanVien, int soLuongNhanVien);




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
		<< setw(12) << maNV
		<< setw(25) << hoTen
		<< setw(12) << loaiHopDong;
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
		<< setw(12) << heSoLuong
		<< setw(15) << getLuong() << endl;
}













int main(){
	int soLuongNhanVien;
	cout << "Nhap so luong nhan vien:";		cin >> soLuongNhanVien;		cin.ignore();
	
	vector<NhanVien*> danhSachNhanVien;
	
	nhapDanhSachNhanVien(danhSachNhanVien, soLuongNhanVien);
	
	
	
	
	return 0;
}

void nhapDanhSachNhanVien(vector<NhanVien*> &danhSachNhanVien, int soLuongNhanVien){
	for(int i=0; i<soLuongNhanVien; i++){
		int chon ;
		
		do{
			cout << "\nNhap loai hop dong ( 1 = thoi vu, 2 = chinh thuc ) :";
			cin >> chon;	
			if(chon != 1 && chon != 2)	cout << "\nLua chon khong hop le, vui long chon lai!";
		}while(chon != 1 && chon != 2);

		NhanVien *nv;
		
		if(chon == 1)	nv = new ThoiVu();
		else			nv = new ChinhThuc();
		
		nv->nhap();
		danhSachNhanVien.push_back(nv);
	}
}
