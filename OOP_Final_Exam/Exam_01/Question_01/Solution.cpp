#include<iostream>
#include<fstream>
#include<iomanip>
#include<vector>

using namespace std;


class NhanVien{
	protected:
		string maNhanVien;
		string hoTen;
		int namSinh;
		float luongCoBan;
		int soNgayCong;
	public:
		NhanVien() : maNhanVien(""), hoTen(""), namSinh(0), luongCoBan(0.0), soNgayCong(0){};
		
		NhanVien(string maNhanVien, string hoTen, int namSinh, float luongCoBan, int soNgayCong);
		
		virtual ~NhanVien(){};
		
		virtual float getLuongThucTe() = 0;
		
		virtual void nhap();
		virtual void xuat(ostream &out);
		
};


class LapTrinhVien : public NhanVien{
	private:
		string capBac;
		float gioLamThem;
	public:
		LapTrinhVien() : NhanVien(), capBac("") , gioLamThem(0.0){};
		
		LapTrinhVien(string maNhanVien, string hoTen, int namSinh, float luongCoBan,
					 int soNgayCong, string capBac, float gioLamThem);
					 
		~LapTrinhVien() override{};
		
		float getLuongThucTe() override;
		
		void nhap() override;
		void xuat(ostream &out) override;
		
};


class KiemThuVien : public NhanVien{
	private:
		int soLoiPhatHien;
		string loaiKiemThu;
	public:
		KiemThuVien() : NhanVien(), loaiKiemThu(""), soLoiPhatHien(0){};
		
		KiemThuVien(string maNhanVien, string hoTen, int namSinh, float luongCoBan,
					 int soNgayCong, string loaiKiemThu, int soLoiPhatHien);
					 
		
		float getLuongThucTe() override;
		
		void nhap() override;
		void xuat(ostream &out) override;
					 
};


void nhapDanhSachNhanVien(vector<NhanVien*> &danhSachNhanVien, int soLuongNhanVien);
void inTieuDe(ostream &out);
void xuatDanhSachNhanVien(ostream &out, const vector<NhanVien*> &danhSachNhanVien);





NhanVien::NhanVien(string maNhanVien, string hoTen, int namSinh, float luongCoBan, int soNgayCong){
	this->maNhanVien = maNhanVien;
	this->hoTen = hoTen;
	this->namSinh = namSinh;
	this->luongCoBan = luongCoBan;
	this->soNgayCong = soNgayCong;
}

void NhanVien::nhap(){
	cout << "Nhap ma nhan vien:";		getline(cin, maNhanVien);
	cout << "Nhap ho ten:";				getline(cin, hoTen);
	do{
		cout << "Nhap nam sinh:";			cin >> namSinh;
		if(namSinh > 2026)	cout << "\nNam sinh khong hop le, vui long nhap lai!" << endl;
	}while(namSinh > 2026);
	
	cout << "Nhap luong co ban:";		cin >> luongCoBan;
	do{
		cout << "Nhap so ngay cong:";		cin >> soNgayCong;	cin.ignore();
		if(soNgayCong < 0 || soNgayCong > 31)	cout << "\nSo ngay cong khong hop le, vui long nhap lai!" << endl; 
	}while(soNgayCong < 0 || soNgayCong > 31);

}

void NhanVien::xuat(ostream &out){
	 out << left
	 	 << setw(10) << maNhanVien
		 << setw(20) << hoTen
		 << setw(12) << namSinh
		 << setw(18) << fixed << setprecision(0) << luongCoBan
		 << setw(15) << soNgayCong;
}










LapTrinhVien::LapTrinhVien(string maNhanVien, string hoTen, int namSinh, float luongCoBan,
					 int soNgayCong, string capBac, float gioLamThem)
					 : NhanVien(maNhanVien, hoTen, namSinh, luongCoBan, soNgayCong){
	
	this->capBac = capBac;
	this->gioLamThem = gioLamThem;		 	
}

float LapTrinhVien::getLuongThucTe(){
	float luong = luongCoBan * (soNgayCong / 22.0) + (gioLamThem * 250000);
	
	if(this->capBac == "senior")	luong *= 1.2;
	
	return luong;
}

void LapTrinhVien::nhap(){
	NhanVien::nhap();
	cout << "Nhap cap bac:";			getline(cin, capBac);
	cout << "Nhap so gio lam them:";	cin >> gioLamThem;	cin.ignore();
}

void LapTrinhVien::xuat(ostream &out){
	NhanVien::xuat(out);
	 out << left
	 	 << setw(18) << capBac
		 << setw(18) << fixed << setprecision(1) << gioLamThem
		 << setw(18) << fixed << setprecision(0) << getLuongThucTe();
}






KiemThuVien::KiemThuVien(string maNhanVien, string hoTen, int namSinh, float luongCoBan,
					 int soNgayCong, string loaiKiemThu, int soLoiPhatHien)
					 : NhanVien(maNhanVien, hoTen, namSinh, luongCoBan, soNgayCong){
					 	
	this->loaiKiemThu = loaiKiemThu;
	this->soLoiPhatHien = soLoiPhatHien;				 	
}

float KiemThuVien::getLuongThucTe(){
	float luong = luongCoBan * (soNgayCong / 22.0) + soLoiPhatHien * 50000;
	
	if(this->loaiKiemThu == "automation")	luong *= 1.15;
	
	return luong;
}

void KiemThuVien::nhap(){
	NhanVien::nhap();
	cout << "Nhap loai kiem thu:";		getline(cin, loaiKiemThu);
	cout << "Nhap so loi phat hien:";	cin >> soLoiPhatHien;	cin.ignore();
}

void KiemThuVien::xuat(ostream &out){
	NhanVien::xuat(out);
	out  << left
		 << setw(18) << loaiKiemThu
		 << setw(18) << soLoiPhatHien
		 << setw(18) << fixed << setprecision(0) << getLuongThucTe();
}





















int main(){
	int soLuongNhanVien;
	cout << "Nhap so luong nhan vien:";		cin >> soLuongNhanVien;		cin.ignore();
	
	vector<NhanVien*> danhSachNhanVien;
	
	nhapDanhSachNhanVien(danhSachNhanVien, soLuongNhanVien);
	
	cout << "\nDanh sach nhan vien vua nhap la:\n";
	xuatDanhSachNhanVien(cout, danhSachNhanVien);
	
	return 0;
}


void nhapDanhSachNhanVien(vector<NhanVien*> &danhSachNhanVien, int soLuongNhanVien){
	for(int i=0; i<soLuongNhanVien; i++){
		int chon ;
		
		do{
			cout << "\nNhap vi tri cong viec(1 - lap trinh vien , 2 - kiem thu vien ): ";
			cin >> chon;	cin.ignore();
		}while(chon != 1 && chon !=2);
		
		NhanVien *nv;
		
		if(chon == 1)	nv = new LapTrinhVien();
		else 			nv = new KiemThuVien();
		
		nv->nhap();
		danhSachNhanVien.push_back(nv);
	}
}

void inTieuDe(ostream &out){
	out  << left
		 << setw(10)  << "Ma NV"
		 << setw(20) << "Ho Va Ten"
		 << setw(12) << "Nam Sinh"
		 << setw(18) << "Luong Co Ban"
		 << setw(15) << "Ngay Cong"
		 << setw(18) << "Thong So 1"
		 << setw(18) << "Thong So 2" 
		 << setw(18) << "Luong Thuc Te" << endl;
}

void xuatDanhSachNhanVien(ostream &out, const vector<NhanVien*> &danhSachNhanVien){
	inTieuDe(out);
	
	for(int i=0; i<danhSachNhanVien.size(); i++){
		danhSachNhanVien[i]->xuat(out);
		out << endl;
	}
}
