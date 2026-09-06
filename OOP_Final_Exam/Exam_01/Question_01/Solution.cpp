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
		//virtual void xuat(ostream &out);
		
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
		//void xuat(ostream &out) override;
		
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
		//void xuat(ostream &out) override;
					 
};


void nhapDanhSachNhanVien(vector<NhanVien*> &danhSachNhanVien, int soLuongNhanVien);






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
	cout << "Nhap nam sinh:";			cin >> namSinh;
	cout << "Nhap luong co ban:";		cin >> luongCoBan;
	cout << "Nhap so ngay cong:";		cin >> soNgayCong;	cin.ignore();
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
