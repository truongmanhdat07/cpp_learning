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
		
		float setGpa(float gpa);
		
		void nhap();
		void xuat() const;
};


void nhapDanhSach(list<SinhVien> &danhSach, int soLuong);


string SinhVien::getMaSV() const{
	return maSV;
}

float SinhVien::getGpa() const{
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
	
}


void nhapDanhSach(list<SinhVien> &danhSach, int soLuong){
	for(int i=0; i<soLuong; i++){
		SinhVien sv;
		sv.nhap();
		danhSach.push_back(sv);
	}
}

