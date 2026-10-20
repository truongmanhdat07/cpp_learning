#include<iostream>
#include<list>
#include<iomanip>
#include<string>
using namespace std;

class SinhVien{
	private:
		string hoTen = "";
		string ma = "";
		int namSinh = 0;
		float diem = 0.0f;
	public:
		SinhVien(){}
		SinhVien(string ma, string hoTen, int namSinh, float diem);
		
		friend istream& operator>>(istream &is, SinhVien &sv);
		friend ostream& operator<<(ostream &os, SinhVien &sv);
};


void nhapDanhSach(list<SinhVien> &danhSach, int soLuong);
void inTieuDe();
void xuatDanhSach(list<SinhVien> &danhSach);


SinhVien::SinhVien(string ma, string hoTen, int namSinh, float diem){
	this->ma = ma;
	this->hoTen = hoTen;
	this->namSinh = namSinh;
	this->diem = diem;
}


istream& operator>>(istream& is, SinhVien &sv){
	cout << "Nhap ma:";				getline(is, sv.ma);
	cout << "Nhap ho va ten:";		getline(is, sv.hoTen);
	cout << "Nhap nam sinh:";		cin >> sv.namSinh;
	cout << "Nhap diem:";			cin >> sv.diem;		cin.ignore();
	return is;
}

ostream& operator<<(ostream& os, SinhVien &sv){
	os << left 
	   << setw(15) << sv.ma
	   << setw(20) << sv.hoTen
	   << setw(15) << sv.namSinh
	   << fixed    << setprecision(2) << setw(10) << sv.diem << endl;
	   return os;
}






int main(){
	int soLuong;
	cout << "Nhap so luong sinh vien:";		cin >> soLuong;		cin.ignore();
	list<SinhVien> danhSach;
	
	nhapDanhSach(danhSach, soLuong);
	
	xuatDanhSach(danhSach);
	
	
	
}


void nhapDanhSach(list<SinhVien> &danhSach, int soLuong){
	for(int i=0; i<soLuong; i++){
		cout << "\nNhap sinh vien thu " << i+1 << ":" << endl;
		SinhVien sv;
		cin >> sv;
		danhSach.push_back(sv);
	}
}

void inTieuDe(ostream &os){
	os  << left 
   		<< setw(15) << "Ma Sinh Vien"
  		<< setw(20) << "Ho Va Ten"
   		<< setw(15) << "Nam Sinh"
  		<< fixed    << setprecision(2) << setw(10) << "Diem" << endl;
}

void xuatDanhSach(list<SinhVien> &danhSach){
	inTieuDe(cout);
	for(auto it = danhSach.begin(); it != danhSach.end(); it++){
		cout << *it;
	}
}
