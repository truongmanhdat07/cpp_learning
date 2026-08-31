#include<iostream>
#include<string>
#include<iomanip>
#include<fstream>
using namespace std;


class Nguoi{
	protected:
		string hoTen;
		string gioiTinh;
		int namSinh;
	public:
		Nguoi();
		string getHoTen();
		string getGioiTinh();
		int getNamSinh();
};


class SinhVien: public Nguoi{
	private:
		string maSinhVien;
		float diemToan, diemLy, diemHoa;
	public:
		SinhVien();
		void nhap(istream &in);
		void xuat(ostream &out);
		string getMaSinhVien();
		float getDiemToan();
		float getDiemLy();
		float getDiemHoa();
		float getGpa();
		string getXepLoai();
};


class ThongKe{
	public:
		int gioi = 0;
		int kha = 0;
		int trungBinh = 0;
		int yeu = 0;
};


void nhapDanhSach(istream &in, SinhVien *danhSachSinhVien, int soLuongSinhVien);
void xuatDanhSach(ostream &out, SinhVien *danhSachSinhVien, int soLuongSinhVien);
int timKiemTheoMaSinhVien(SinhVien *danhSachSinhVien, int soLuongSinhVien, string maSinhVienCanTim);
ThongKe thongKeHocLuc(SinhVien *danhSachSinhVien, int soLuongSinhVien);
void inBangThongKe(ostream &out, ThongKe &sinhVien);



Nguoi::Nguoi(){
	hoTen = "";
	gioiTinh = "";
	namSinh = 0;
}

string Nguoi::getHoTen(){
	return hoTen;
}

string Nguoi::getGioiTinh(){
	return gioiTinh;
}

int Nguoi::getNamSinh(){
	return namSinh;
}



SinhVien::SinhVien(){
	maSinhVien = "";
	diemToan = -1;	diemLy = -1; diemHoa = -1;
}

void SinhVien::nhap(istream &in) {
    getline(in, maSinhVien, ',');
    getline(in, hoTen, ',');
    getline(in, gioiTinh, ',');
    in >> namSinh >> diemToan >> diemLy >> diemHoa; 
    in.ignore();
}

void SinhVien::xuat(ostream &out) {
    out << left 
        << setw(14) << maSinhVien
        << setw(22) << hoTen
        << setw(10) << gioiTinh
        << setw(10) << namSinh
        << setw(8)  << fixed << setprecision(1) << diemToan
        << setw(8)  << fixed << setprecision(1) << diemLy
        << setw(8)  << fixed << setprecision(1) << diemHoa
        << setw(8)  << fixed << setprecision(2) << getGpa()
        << setw(12) << getXepLoai() 
        << endl;
}

string SinhVien::getMaSinhVien(){
	return maSinhVien;
}

float SinhVien::getDiemToan(){
	return diemToan;
}

float SinhVien::getDiemLy(){
	return diemLy;
}

float SinhVien::getDiemHoa(){
	return diemHoa;
}

float SinhVien::getGpa(){
	return (diemToan + diemLy + diemHoa) / 3;
}

string SinhVien::getXepLoai() {
    float gpa = getGpa();
    if (gpa >= 8.0) return "Gioi";
    if (gpa >= 6.5) return "Kha";
    if (gpa >= 5.0) return "Trung binh";
    return "Yeu";
}




int main(){
	int soLuongSinhVien;
	string tenFileInput;
	cout << "Nhap ten file de doc :";	getline(cin, tenFileInput);
	
	fstream fileIn(tenFileInput);
	if(!fileIn){
		cerr << "Khong the mo file " << tenFileInput;
		return 1;
	}
	
	fileIn >> soLuongSinhVien;	fileIn.ignore();
	
	SinhVien *danhSachSinhVien = new SinhVien[soLuongSinhVien];
	
	nhapDanhSach(fileIn, danhSachSinhVien, soLuongSinhVien);
	cout << "\nDanh sach sinh vien vua doc tu file " << tenFileInput << " la :\n";
	xuatDanhSach(cout, danhSachSinhVien, soLuongSinhVien);
	
	string maSinhVienCanTim;
	cout << "\nNhap ma sinh vien can tim :";
	getline(cin, maSinhVienCanTim);
	int viTri = timKiemTheoMaSinhVien(danhSachSinhVien, soLuongSinhVien, maSinhVienCanTim);
	if(viTri != -1){
		cout << "\nDa tim thay sinh vien co ma sinh vien la " << maSinhVienCanTim << endl ;
		xuatDanhSach(cout, &danhSachSinhVien[viTri], 1);
	}
	else 	cout << "\nKhong tim thay sinh vien co ma la " << maSinhVienCanTim;
	
	ThongKe sinhVien = thongKeHocLuc(danhSachSinhVien, soLuongSinhVien);
	cout << "\nBang thong ke sinh vien theo hoc luc la :\n";
	inBangThongKe(cout, sinhVien);
	
	
	
	
	
	delete[] danhSachSinhVien;
	return 0;
}


void nhapDanhSach(istream &in, SinhVien *danhSachSinhVien, int soLuongSinhVien){
	for(int i=0; i<soLuongSinhVien; i++){
		danhSachSinhVien[i].nhap(in);
	}
}

void xuatDanhSach(ostream &out, SinhVien *danhSachSinhVien, int soLuongSinhVien) {

    out << left 
        << setw(14) << "Ma SV"
        << setw(22) << "Ho va Ten"
        << setw(10) << "Gioi Tinh"
        << setw(10) << "Nam Sinh"
        << setw(8)  << "Toan"
        << setw(8)  << "Ly"
        << setw(8)  << "Hoa"
        << setw(8)  << "GPA"
        << setw(12) << "Xep Loai" 
        << endl;

    for (int i = 0; i < soLuongSinhVien; i++) {
        danhSachSinhVien[i].xuat(out);
    }
}

int timKiemTheoMaSinhVien(SinhVien *danhSachSinhVien, int soLuongSinhVien, string maSinhVienCanTim){
	for(int i=0; i<soLuongSinhVien; i++){
		if(danhSachSinhVien[i].getMaSinhVien() == maSinhVienCanTim)	return i;
	}
	return -1;
}

ThongKe thongKeHocLuc(SinhVien *danhSachSinhVien, int soLuongSinhVien){
	ThongKe ketQua;
	
	for(int i=0; i<soLuongSinhVien; i++){
		string loai = danhSachSinhVien[i].getXepLoai();
		if(loai == "Gioi")				ketQua.gioi++;
		else if(loai == "Kha")			ketQua.kha++;
		else if(loai == "Trung binh")	ketQua.trungBinh++;
		else if(loai == "Yeu")			ketQua.yeu++;
	}
	return ketQua;
}

void inBangThongKe(ostream &out, ThongKe &sinhVien){
    out << left << setw(15) << "Gioi"       << ": " << sinhVien.gioi       << " sinh vien\n"
    	<< left << setw(15) << "Kha"        << ": " << sinhVien.kha        << " sinh vien\n"
    	<< left << setw(15) << "Trung binh" << ": " << sinhVien.trungBinh  << " sinh vien\n"
    	<< left << setw(15) << "Yeu"        << ": " << sinhVien.yeu        << " sinh vien\n";

}
