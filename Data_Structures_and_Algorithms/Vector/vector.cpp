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
		
		string getMaSV() const;
		void setGpa(float gpa);
		float getGpa() const;
};


void nhapDanhSach(vector<SinhVien> &danhSach, int soLuong);
void inTieuDe();
void xuatDanhSach(const vector<SinhVien> &danhSach);
void congDiem(vector<SinhVien> &danhSach, string maSVCanCong);
void congDiemChoSinhVien(vector<SinhVien> &danhSach);
void xoaSinhVien(vector<SinhVien> &danhSach, float nguongGpa);
void xuatDanhSachNguoc(const vector<SinhVien> &danhSach);



string SinhVien::getMaSV() const{
	return maSV;
}

void SinhVien::setGpa(float gpa){
	if(gpa < 0)			this->gpa = 0;
	else if(gpa > 4.0)	this->gpa = 4.0;
	else 				this->gpa = gpa;
}

float SinhVien::getGpa() const{
	return gpa;
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
	
	vector<SinhVien> danhSach;
	
	nhapDanhSach(danhSach, soLuong);
	
	cout << "\nDanh sach vua nhap la:" << endl;
	xuatDanhSach(danhSach);
	
	congDiemChoSinhVien(danhSach);
	
	xoaSinhVien(danhSach, 2.5);
	
	cout << "\nDanh sach sau khi chinh sua la ( duyet nguoc ):" << endl;
	xuatDanhSachNguoc(danhSach);
	
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
		 << setw(15) << "Ma Sinh Vien"
		 << setw(25) << "Ho Va Ten"
		 << setw(10) << "Gpa" << endl;
}

void xuatDanhSach(const vector<SinhVien> &danhSach){
	inTieuDe();
	
	for(auto it=danhSach.begin(); it!=danhSach.end(); it++){
		it->xuat();
	}	
}

void congDiem(vector<SinhVien> &danhSach, string maSVCanCong){
	for(auto it = danhSach.begin(); it != danhSach.end(); it++){
		if(it->getMaSV() == maSVCanCong){
			cout << "\nDa tim thay sinh vien co ma sinh vien la " << maSVCanCong;
			it->setGpa( it->getGpa() + 0.5);
			cout << "\nCong diem thanh cong!";
			return;
		}
	}
	cout << "\nKhong tim thay sinh vien co ma sinh vien la "  << maSVCanCong;
}

void congDiemChoSinhVien(vector<SinhVien> &danhSach){
	string maSVCanCong;
	cout << "\nNhap ma sinh vien can cong diem:";	getline(cin, maSVCanCong);
	
	congDiem(danhSach, maSVCanCong);
}

void xoaSinhVien(vector<SinhVien> &danhSach, float nguongGpa){
	for(auto it = danhSach.begin(); it != danhSach.end();){
		if(it->getGpa() < nguongGpa){
			it = danhSach.erase(it);
		}
		else{
			++it;
		}
	}
}

void xuatDanhSachNguoc(const vector<SinhVien> &danhSach){
	inTieuDe();
	for(auto it = danhSach.rbegin(); it != danhSach.rend(); ++it){
		it->xuat();
	}
}
