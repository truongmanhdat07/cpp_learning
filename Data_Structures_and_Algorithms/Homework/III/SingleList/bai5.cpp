#include <iostream>
#include "SingleList.h"
#include <iomanip>
#include <fstream>

using namespace std;

class SinhVien {
	private:
	    string maSv = "";
	    string hoTen = "";
	    int namSinh = 0;
	    string gioiTinh = "";
	    string queQuan = "";
	
	public:
	    SinhVien() {}
	    SinhVien(string maSv, string hoTen, int namSinh, string gioiTinh, string queQuan);
	
	    string getMaSv();
	
	    friend istream& operator>>(istream &is, SinhVien &sv);
	    friend ostream& operator<<(ostream &os, SinhVien &sv);
};


void nhapDanhSach(istream &is, SingleList<SinhVien> &danhSach, int soLuong);
void inTieuDe(ostream &os);
void xuatDanhSach(ostream &os, SingleList<SinhVien> &danhSach);
void boSungCuoi(SingleList<SinhVien> &danhSach);
void xoaSinhVien(SingleList<SinhVien> &danhSach, string maSv);
void xoaSinhVienTheoMa(SingleList<SinhVien> &danhSach);
void capNhapThongTin(SingleList<SinhVien> &danhSach, string maSv);
void capNhapThongTinTheoMa(SingleList<SinhVien> &danhSach);
void hienThiThongTin(SingleList<SinhVien> &danhSach, string maSv);
void hienThiThongTinTheoMa(SingleList<SinhVien> &danhSach);


SinhVien::SinhVien(string maSv, string hoTen, int namSinh, string gioiTinh, string queQuan) {
    this->maSv = maSv;
    this->hoTen = hoTen;
    this->namSinh = namSinh;
    this->gioiTinh = gioiTinh;
    this->queQuan = queQuan;
}

string SinhVien::getMaSv() {
    return maSv;
}

istream& operator>>(istream &is, SinhVien &sv) {
    if (&is == &cin) {
        cout << "Nhap ma sinh vien:"; getline(is, sv.maSv);
        cout << "Nhap ho ten:";       getline(is, sv.hoTen);
        cout << "Nhap nam sinh:";     is >> sv.namSinh;   is.ignore();
        cout << "Nhap gioi tinh:";    getline(is, sv.gioiTinh);
        cout << "Nhap que quan:";     getline(is, sv.queQuan);
    } 
	else {
        getline(is, sv.maSv);
        getline(is, sv.hoTen);
        is >> sv.namSinh;             is.ignore();
        getline(is, sv.gioiTinh);
        getline(is, sv.queQuan);
    }
    return is;
}

ostream& operator<<(ostream &os, SinhVien &sv) {
    os << left
       << setw(15) << sv.maSv
       << setw(25) << sv.hoTen
       << setw(12) << sv.namSinh
       << setw(12) << sv.gioiTinh
       << setw(20) << sv.queQuan << endl;
    return os;
}


int main() {
    int soLuong;
    ifstream fileIn("sinhvien.txt");
    fileIn >> soLuong; 
    fileIn.ignore();

    SingleList<SinhVien> danhSach;

    nhapDanhSach(fileIn, danhSach, soLuong);

    ofstream fileOut("ketqua.txt");
    xuatDanhSach(fileOut, danhSach);

    boSungCuoi(danhSach);

    xoaSinhVienTheoMa(danhSach);

    capNhapThongTinTheoMa(danhSach);

    hienThiThongTinTheoMa(danhSach);

    cout << "\nDanh sach sinh vien hien tai:" << endl;
    xuatDanhSach(cout, danhSach);

    return 0;
}


void nhapDanhSach(istream &is, SingleList<SinhVien> &danhSach, int soLuong) {
    for (int i = 0; i < soLuong; i++) {
        if (&is == &cin) cout << "Nhap thong tin sinh vien thu " << i + 1 << ":\n";
        SinhVien sv;
        is >> sv;
        danhSach.push_back(sv);
    }
}

void inTieuDe(ostream &os) {
    os << left 
       << setw(15) << "Ma Sinh Vien"
       << setw(25) << "Ho Va Ten"
       << setw(12) << "Nam Sinh"
       << setw(12) << "Gioi tinh"
       << setw(20) << "Que quan" << endl;
}

void xuatDanhSach(ostream &os, SingleList<SinhVien> &danhSach) {
    inTieuDe(os);
    for (auto it = danhSach.begin(); it != danhSach.end(); it++) {
        os << *it;
    }
}

void boSungCuoi(SingleList<SinhVien> &danhSach) {
    SinhVien sv;
    cout << "\nNhap thong tin sinh vien bo sung cuoi danh sach:" << endl;
    cin >> sv;
    danhSach.push_back(sv);
}

void xoaSinhVien(SingleList<SinhVien> &danhSach, string maSv) {
    bool timThay = false;
    int viTri = 1;

    for (auto it = danhSach.begin(); it != danhSach.end(); it++, viTri++) {
        if (it->getMaSv() == maSv) {
            danhSach.erase(viTri);
            timThay = true;
            break;
        }
    }
    if (timThay) cout << "\nXoa thanh cong sinh vien co ma: " << maSv << endl;
    else        cout << "\nKhong tim thay sinh vien co ma: " << maSv << endl;
}

void xoaSinhVienTheoMa(SingleList<SinhVien> &danhSach) {
    string maSv;
    cout << "\nNhap ma sinh vien can xoa: ";
    getline(cin, maSv);
    xoaSinhVien(danhSach, maSv);
}

void capNhapThongTin(SingleList<SinhVien> &danhSach, string maSv) {
    bool timThay = false;

    for (auto it = danhSach.begin(); it != danhSach.end(); it++) {
        if (it->getMaSv() == maSv) {
            cin >> *it;
            timThay = true;
            break;
        }
    }
    if (timThay) cout << "\nCap nhap thanh cong sinh vien co ma: " << maSv << endl;
    else        cout << "\nKhong tim thay sinh vien co ma: " << maSv << endl;
}

void capNhapThongTinTheoMa(SingleList<SinhVien> &danhSach) {
    string maSv;
    cout << "\nNhap ma sinh vien can cap nhap: ";
    getline(cin, maSv);
    capNhapThongTin(danhSach, maSv);
}

void hienThiThongTin(SingleList<SinhVien> &danhSach, string maSv) {
    bool timThay = false;

    for (auto it = danhSach.begin(); it != danhSach.end(); it++) {
        if (it->getMaSv() == maSv) {
            cout << "\nThong tin sinh vien can tim:" << endl;
            inTieuDe(cout);
            cout << *it;
            timThay = true;
            break;
        }
    }

    if (!timThay) {
        cout << "\nKhong tim thay sinh vien co ma: " << maSv << endl;
    }
}

void hienThiThongTinTheoMa(SingleList<SinhVien> &danhSach) {
    string maSv;
    cout << "\nNhap ma sinh vien can tim de hien thi: ";
    getline(cin, maSv);
    hienThiThongTin(danhSach, maSv);
}
