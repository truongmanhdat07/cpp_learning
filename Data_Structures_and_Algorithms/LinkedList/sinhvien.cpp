#include<iostream>
#include<list>
#include<iomanip>

using namespace std;

class SinhVien{
	private:
		string maSV;
		string hoTen;
		float gpa;
	public:
		SinhVien(string maSV = "", string hoTen = "", float gpa = 0.0f) : maSV(maSV), hoTen(hoTen), gpa(gpa){}
		
		string getMaSV() const;
		float getGpa() const;
		
		void setGpa(float gpa);
		
		void nhap();
		void xuat() const;
};


void nhapDanhSach(list<SinhVien> &danhSach, int soLuong);
void inTieuDe();
void xuatDanhSach(list<SinhVien> &danhSach);
void congDiem(list<SinhVien> &danhSach, string maSVCanCong);
void congDiemChoSinhVien(list<SinhVien> &danhSach);
void xoaSinhVien(list<SinhVien> &danhSach, float nguongGpa);
void giaiPhongBoNho(list<SinhVien> &danhSach);



string SinhVien::getMaSV() const{
	return maSV;
}

void SinhVien::getGpa() const{
	return gpa;
}

float SinhVien::setGpa(float gpa){
	if(gpa < 0)			this->gpa = 0;
	else if(gpa > 4.0)	this->gpa = 4.0;
	else				this->gpa = gpa;
}

void SinhVien::nhap(){
	cout << "Nhap ma sinh vien:";	getline(cin, maSV);
	cout << "Nhap ho va ten:";		getline(cin, hoTen);
	cout << "Nhap gpa:";			cin >> gpa;		cin.ignore();
}

void SinhVien::xuat() const{
	cout << left
		 << setw(15) << maSV 
		 << setw(25) << hoTen
		 << setw(10) << fixed << setprecision(2) << gpa << endl;
}




int main(){
	int soLuong;
	cout << "Nhap so luong sinh vien:";		cin >> soLuong; 	cin.ignore();
	
	list<SinhVien> danhSach;
	
	nhapDanhSach(danhSach, soLuong);
	
	cout << "\nDanh sach vua nhap la:" << endl;
	xuatDanhSach(danhSach);
	
	congDiemChoSinhVien(danhSach);
	
	xoaSinhVien(danhSach, 2.5);
	
	cout << "\nDanh sach sinh vien hien tai:" << endl;
	xuatDanhSach(danhSach);
	
	giaiPhongBoNho(danhSach);
	
	return 0;
}


void nhapDanhSach(list<SinhVien> &danhSach, int soLuong){
	for(int i=0; i<soLuong; i++){
		SinhVien sv;
		sv.nhap();
		danhSach.push_back(sv);
	}
}

void inTieuDe(){
	cout << left 
		 << setw(15) << "Ma Sinh Vien"
		 << setw(25) << "Ho Va Ten"
		 << setw(10) << "Gpa" << endl;
}

void xuatDanhSach(list<SinhVien> &danhSach){
	inTieuDe();
	
	for(auto it = danhSach.begin(); it != danhSach.end(); it++){
		it->xuat();
	}
}

void congDiem(list<SinhVien> &danhSach, string maSVCanCong){
	for(auto it = danhSach.begin(); it != danhSach.end(); it++){
		if(it->getMaSV() == maSVCanCong){
			cout << "\nDa tim thay sinh vien co ma " << maSVCanCong << endl;
			it->setGpa( it->getGpa() + 0.5);
			cout << "Cong diem thanh cong!";
			return;
		}
	}
	cout << "\nKhong tim thay sinh vien co ma sinh vien la "  << maSVCanCong;	
}

void congDiemChoSinhVien(list<SinhVien> &danhSach){
	string maSVCanCong;
	cout << "\nNhap ma sinh vien can cong diem:";	getline(cin, maSVCanCong);
	
	congDiem(danhSach, maSVCanCong);
}

void xoaSinhVien(list<SinhVien> &danhSach, float nguongGpa){
	for(auto it = danhSach.begin(); it != danhSach.end(); ){
		if(it->getGpa() < nguongGpa){
			it = danhSach.erase(it);
		}
		else{
			it++;
		}
	}
	cout << "\nXoa thanh cong sinh vien co gpa < " << nguongGpa;
}

void giaiPhongBoNho(list<SinhVien> &danhSach){
	danhSach.clear();
	cout << "\nGiai phong bo nho thanh cong!";
}
