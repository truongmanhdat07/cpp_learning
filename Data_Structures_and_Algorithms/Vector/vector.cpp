#include<iostream>
#include<iomanip>
#include<vector>
using namespace std;

class SinhVien{
	private:
		string maSV;
		string hoTen;
		float gpa;
	public:
		SinhVien(string maSV = "", string hoTen = "", float gpa = 0.0f) : maSV(maSV) , hoTen(hoTen), gpa(gpa){}
		
		void nhap();
		void xuat() const;
};


void nhapDanhSach(vector<SinhVien> &danhSach, int soLuong);
void inTieuDe();
void xuatDanhSach(const vector<SinhVien> &danhSach);



void SinhVien::nhap(){
	cout << "Nhap ma sinh vien:";	getline(cin, maSV);
	cout << "Nhap ho va ten:";		getline(cin, hoTen);
	cout << "Nhap gpa:";			cin >> gpa;		cin.ignore();
}

void SinhVien::xuat() const{
	cout << left
		 << setw(12) << maSV 
		 << setw(25) << hoTen
		 << setw(10) << fixed << setprecision(2) << gpa << endl;
}




int main(){
	int soLuong;
	cout << "Nhap so luong sinh vien:";		cin >> soLuong; 	cin.ignore();
	
	vector<SinhVien> danhSach;
	
	nhapDanhSach(danhSach, soLuong);
	
	cout << "\nDanh sach vua nhap la:" << endl;
	xuatDanhSach(danhSach);
	
	
	
	
	return 0;
}

void nhapDanhSach(vector<SinhVien> &danhSach, int soLuong){
	for(int i=0; i<soLuong; i++){
		SinhVien sv;
		sv.nhap();
		danhSach.push_back(sv);
	}
}

void inTieuDe(){
	cout << left 
		 << setw(12) << "Ma Sinh Vien"
		 << setw(25) << "Ho Va Ten"
		 << setw(10) << "GPA" << endl;
}

void xuatDanhSach(const vector<SinhVien> &danhSach){
	inTieuDe();
	
	for(auto it=danhSach.begin(); it!=danhSach.end(); it++){
		it->xuat();
	}	
}
