#include <iostream>
#include "myVector.h"
#include <iomanip>
#include <fstream>

using namespace std;

class SinhVien{
	private:
		string sbd = "";
		string hoTen = "";
		int namSinh = 0;
		string gioiTinh = "";
		float diem = 0.0f;
	public:
		SinhVien(){};
		SinhVien(string sbd, string hoTen, int namSinh, string gioiTinh, float diem);
		
		string getSbd();
		
		friend istream& operator>>(istream &is, SinhVien &sv);
		friend ostream& operator<<(ostream &os, SinhVien &sv);
};


void nhapDanhSach(istream &is, Vector<SinhVien> &danhSach, int soLuong);
void inTieuDe(ostream &os);
void xuatDanhSach(ostream &os, Vector<SinhVien> &danhSach);
void boSungCuoi(Vector<SinhVien> &danhSach);
void xoaSinhVien(Vector<SinhVien> &danhSach, string soBaoDanh);
void xoaSinhVienTheoSBD(Vector<SinhVien> &danhSach);
void capNhapThongTin(Vector<SinhVien> &danhSach, string soBaoDanh);
void capNhapThongTinTheoSBD(Vector<SinhVien> &danhSach);
void hienThiThongTin(Vector<SinhVien> &danhSach, string soBaoDanh);
void hienThiThongTinTheoSBD(Vector<SinhVien> &danhSach);



SinhVien::SinhVien(string sbd, string hoTen, int namSinh, string gioiTinh, float diem){
	this->sbd = sbd;
	this->hoTen = hoTen;
	this->namSinh = namSinh;
	this->gioiTinh = gioiTinh;
	this->diem = diem;
}

string SinhVien::getSbd(){
	return sbd;
}

istream& operator>>(istream &is, SinhVien &sv){
	if(&is == &cin){
		cout << "Nhap so bao danh:";		getline(is, sv.sbd);
		cout << "Nhap ho ten:";				getline(is, sv.hoTen);
		cout << "Nhap nam sinh:";			is >> sv.namSinh;	is.ignore();
		cout << "Nhap gioi tinh:";			getline(is, sv.gioiTinh);
		cout << "Nhap diem:";				is >> sv.diem;		is.ignore();
	}
	else{
		getline(is, sv.sbd);
		getline(is, sv.hoTen);
		is >> sv.namSinh;	is.ignore();
		getline(is, sv.gioiTinh);
		is >> sv.diem;		is.ignore();		
	}
	
	return is;
}

ostream& operator<<(ostream &os, SinhVien &sv){
	os	<< left << fixed << setprecision(2)
		<< setw(12) << sv.sbd
		<< setw(25) << sv.hoTen
		<< setw(12) << sv.namSinh
		<< setw(12) << sv.gioiTinh
		<< setw(8)  << sv.diem << endl;
		
	return os;
}



int main(){
	int soLuong;
	ifstream fileIn("sinhvien.txt");
	fileIn >> soLuong;	fileIn.ignore();
	
	Vector<SinhVien> danhSach(soLuong);
	
	nhapDanhSach(fileIn, danhSach, soLuong);
	
	ofstream fileOut("ketqua.txt");
	xuatDanhSach(fileOut, danhSach);
	
	boSungCuoi(danhSach);
	
	xoaSinhVienTheoSBD(danhSach);
	
	capNhapThongTinTheoSBD(danhSach);
	
	hienThiThongTinTheoSBD(danhSach);
	
	cout << "\nDanh sach sinh vien hien tai:" << endl;
	xuatDanhSach(cout, danhSach);
	
	
	
	return 0;
}


void nhapDanhSach(istream &is, Vector<SinhVien> &danhSach, int soLuong){
	for(int i=0; i<soLuong; i++){
		if(&is == &cin)		cout << "Nhap thong tin sinh vien thu " << i+1 << ":";
		is >> danhSach[i];
	}
}


void inTieuDe(ostream &os){
	os	<< left 
		<< setw(12) << "So Bao Danh"
		<< setw(25) << "Ho Va Ten"
		<< setw(12) << "Nam Sinh"
		<< setw(12) << "Gioi tinh"
		<< setw(8)  << "Diem" << endl;
}

void xuatDanhSach(ostream &os, Vector<SinhVien> &danhSach){
	inTieuDe(os);
	for(auto it = danhSach.begin(); it != danhSach.end(); it++){
		os << *it ;
	}
}

void boSungCuoi(Vector<SinhVien> &danhSach){
	SinhVien sv;
	cout << "\nNhap thong tin sinh vien bo sung cuoi danh sach:" << endl;
	cin >> sv;
	danhSach.push_back(sv);
}

void xoaSinhVien(Vector<SinhVien> &danhSach, string soBaoDanh){
	bool timThay = false;
	
	for(auto it = danhSach.begin() ; it != danhSach.end(); it++){
		if(it->getSbd() == soBaoDanh){
			int viTri = it - danhSach.begin();
			danhSach.erase(viTri);
			timThay = true;
			break;
		}
	}
	if(timThay)	cout << "\nXoa thanh cong sinh vien co so bao danh:" << soBaoDanh << endl;
	else		cout << "\nKhong tim thay sinh vien co so bao danh:" << soBaoDanh << endl;
}

void xoaSinhVienTheoSBD(Vector<SinhVien> &danhSach){
	string soBaoDanh;
	cout << "\nNhap so bao danh can xoa:";		getline(cin, soBaoDanh);
	xoaSinhVien(danhSach, soBaoDanh);
}

void capNhapThongTin(Vector<SinhVien> &danhSach, string soBaoDanh){
	bool timThay = false;
	
	for(auto it = danhSach.begin() ; it != danhSach.end(); it++){
		if(it->getSbd() == soBaoDanh){
			cin >> *it;
			timThay = true;
			break;
		}
	}
	if(timThay)	cout << "\nCap nhap thanh cong sinh vien co so bao danh:" << soBaoDanh << endl;
	else		cout << "\nKhong tim thay sinh vien co so bao danh:" << soBaoDanh << endl;	
}

void capNhapThongTinTheoSBD(Vector<SinhVien> &danhSach){
	string soBaoDanh;
	cout << "\nNhap so bao danh can cap nhap:";		getline(cin, soBaoDanh);
	capNhapThongTin(danhSach, soBaoDanh);
}

void hienThiThongTin(Vector<SinhVien> &danhSach, string soBaoDanh){
    bool timThay = false;
    
    for(auto it = danhSach.begin(); it != danhSach.end(); it++){
        if(it->getSbd() == soBaoDanh){
            cout << "\nThong tin sinh vien can tim:" << endl;
            inTieuDe(cout);
            cout << *it;
            timThay = true;
            break;
        }
    }
    
    if(!timThay){
        cout << "\nKhong tim thay sinh vien co so bao danh: " << soBaoDanh << endl;
    }
}

void hienThiThongTinTheoSBD(Vector<SinhVien> &danhSach){
    string soBaoDanh;
    cout << "\nNhap so bao danh can tim de hien thi: ";
    getline(cin, soBaoDanh);
    hienThiThongTin(danhSach, soBaoDanh);
}
