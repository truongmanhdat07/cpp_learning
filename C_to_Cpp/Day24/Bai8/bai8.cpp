#include<iostream>
#include<iomanip>
#include<string>
#include<vector>
using namespace std;

class Nguoi{
	protected:
		string ten;
		int ns;
	public:
		Nguoi(){}
		
		virtual void nhap(){
			cout << "Ten:";			getline(cin, ten);
			cout << "Nam Sinh:";	cin >> ns;	
		}
		
		virtual void xuat(){
			cout << left << fixed << setprecision(0)
				 << setw(20) << ten
				 << setw(12) << ns;
		}
};

class SinhVien : public Nguoi{
	private:
		float diem;
	public:
		SinhVien(){}
		
		void nhap() override{
			Nguoi::nhap();
			cout << "Diem:";	cin >> diem;	cin.ignore();
		}
		
		void xuat() override{
			Nguoi::xuat();
			cout << setw(10) << diem << endl;
		}
		
		float getDiem(){
			return diem;
		}
		
		bool duocThuong(){
			return diem > 9;
		}
};

class GiangVien : public Nguoi{
	private:
		float soGio;
	public:
		GiangVien(){}
		
		void nhap() override{
			Nguoi::nhap();
			cout << "So Gio:";	cin >> soGio;	cin.ignore();
		}
		
		void xuat() override{
			Nguoi::xuat();
			cout << setw(12) << soGio << endl;
		}
		
		float getGio(){
			return soGio;
		}
		
		bool duocThuong(){
			return soGio > 300;
		}
};

template<typename T>
void nhapDanhSach(vector<T> &ds, int soLuong){
	for(int i=0; i<soLuong; i++){
		ds[i].nhap();
	}
}

template<typename T>
void xuatDanhSach(vector<T> &ds){
	for(int i=0; i<ds.size(); i++){
		ds[i].xuat();
	}
}

template<typename T>
vector<T> duocThuong(vector<T> &ds){
    vector<T> dsdt;
    for(size_t i = 0; i < ds.size(); i++){
        if(ds[i].duocThuong()) { 
            dsdt.push_back(ds[i]);
        }
    }
    return dsdt;
}

int main(){
	int soLuong;
	cout << "Nhap n:";		cin >> soLuong;		cin.ignore();
	
	vector<SinhVien> dssv(soLuong);
	vector<GiangVien> dsgv(soLuong);
	
	cout << "\nNhap danh sach sinh vien:" << endl;
	nhapDanhSach(dssv, soLuong);
	cout << "\nNhap danh sach sinh vien:" << endl;
	nhapDanhSach(dsgv, soLuong);
	
	
	cout << "\nDanh sach sinh vien vua nhap la:" << endl;
	xuatDanhSach(dssv);
	
	cout << "\nDanh sach giang vien vua nhap la:" << endl;
	xuatDanhSach(dsgv);
	
	vector<SinhVien> dssvdt = duocThuong(dssv);
	vector<GiangVien> dsgvdt = duocThuong(dsgv);
	
	cout << "\nDanh sach sinh vien duoc thuong la:" << endl;
	xuatDanhSach(dssvdt);
	
	cout << "\nDanh sach giang vien duoc thuong la:" << endl;
	xuatDanhSach(dsgvdt);
	
	return 0;
}
