#include<iostream>
#include<list>
#include<iomanip>
#include<string>
#include<algorithm>
using namespace std;

class SinhVien{
	private:
		string hoTen = "";
		string ma = "";
		int namSinh = 0;
		float diem = 0.0f;
	public:
		SinhVien(){}
		SinhVien(string ma, string hoTen, int namSinh, float diem){
			this->ma = ma;
			this->hoTen = hoTen;
			this->namSinh = namSinh;
			this->diem = diem;
		}
		
		float getDiem(){
			return diem;
		}
		
		string getMa(){
			return ma;
		}

		friend istream& operator>>(istream& is, SinhVien &sv){
			cout << "Nhap ma:";				getline(is, sv.ma);
			cout << "Nhap ho va ten:";		getline(is, sv.hoTen);
			cout << "Nhap nam sinh:";		is >> sv.namSinh;
			cout << "Nhap diem:";			is >> sv.diem;		cin.ignore();
			return is;
		}
		
		friend ostream& operator<<(ostream& os, SinhVien &sv){
			os << left 
			   << setw(15) << sv.ma
			   << setw(20) << sv.hoTen
			   << setw(15) << sv.namSinh
			   << fixed    << setprecision(2) << setw(10) << sv.diem << endl;
			   return os;
		}		
		
		bool operator<(SinhVien &other){
			return this->getDiem() < other.getDiem();
		}		

};

class DanhSachSinhVien{
	private:
		list<SinhVien> danhSach;
	public:
		void nhapDanhSach(){
			int soLuong;
			cout << "Nhap so luong sinh vien:";		cin >> soLuong; 	cin.ignore();
			for(int i=0; i<soLuong; i++){
				cout << "\nNhap sinh vien thu " << i+1 << ":" << endl;
				SinhVien sv;
				cin >> sv;
				danhSach.push_back(sv);
			}
		}
		
		void inTieuDe(){
			cout << left 
		   		 << setw(15) << "Ma Sinh Vien"
		  		 << setw(20) << "Ho Va Ten"
		   		 << setw(15) << "Nam Sinh"
		  		 << fixed    << setprecision(2) << setw(10) << "Diem" << endl;
		}
		
		void xuatDanhSach(){
			if(danhSach.empty()){
				cout << "\nDanh sach dang rong!";
				return;
			}
			
			inTieuDe();
			for(auto it = danhSach.begin(); it != danhSach.end(); it++){
				cout << *it;
			}
		}
		
		void themSinhVien(){
			if(danhSach.empty()){
				cout << "\nDanh sach dang rong!";
				return;
			}
			
			cout << "\nNhap thong tin sinh vien can them:" << endl;
			SinhVien sv;
			cin >> sv;
			danhSach.push_back(sv);
			cout << "\nThem sinh vien thanh cong" << endl;
		}
		
		void timKiemTheoMa(){
			if(danhSach.empty()){
				cout << "\nDanh sach dang rong!";
				return;
			}
			
			string maCanTim;
			cout << "\nNhap ma sinh vien can tim:";		getline(cin, maCanTim);
			bool timThay = false;
			
			for(auto it = danhSach.begin(); it != danhSach.end(); it++){
				if(it->getMa() == maCanTim){
					timThay = true;
					cout << "\nDa tim thay sinh vien co ma " << maCanTim << ":" << endl;
					inTieuDe();
					cout << *it;
					break;
				}
			}
			if(timThay == false)		cout << "\nKhong tim thay sinh vien co ma " << maCanTim << endl;
		}
		
		void xoaTheoMa(){
			if(danhSach.empty()){
				cout << "\nDanh sach dang rong!";
				return;
			}
			
			string maCanXoa;
			cout << "\nNhap ma sinh vien can xoa:";		getline(cin, maCanXoa);
			bool timThay = false;
			
			for(auto it = danhSach.begin(); it != danhSach.end(); ){
				if(it->getMa() == maCanXoa){
					timThay = true;
					it = danhSach.erase(it);
					cout << "\nXoa thanh cong sinh vien co ma " << maCanXoa << endl;
					break;
				}
				else{
					it++;
				}
			}
			
			if(timThay == false)	cout << "\nKhong tim thay sinh vien co ma " << maCanXoa << endl;
		}
		
		void sapXepTheoDiem(){
			danhSach.sort();
			cout << "\nSap xep thanh cong danh sach theo diem tang dan" << endl;
		}
};

class App {
	private:
	    DanhSachSinhVien ds;
	public:
	    void run(){
	        int chon;
	        do{
	            cout << "\nCHUONG TRINH QUAN LY SINH VIEN" << endl;
	            cout << "1.Nhap danh sach sinh vien" << endl;
	            cout << "2.Xuat danh sach sinh vien" << endl;
	            cout << "3.Them 1 sinh vien moi" << endl;
	            cout << "4.Tim kiem sinh vien theo ma" << endl;
	            cout << "5.Xoa sinh vien theo ma" << endl;
	            cout << "6.Sap xep danh sach theo diem tang dan" << endl;
	            cout << "0.Thoat chuong trinh" << endl;
	            cout << "Nhap lua chon:";
	            cin >> chon;	cin.ignore();
	
	            switch (chon){
	                case 1:
	                    ds.nhapDanhSach();
	                    break;
	                case 2:
	                    cout << "\nDanh Sach Sinh Vien" << endl;
	                    ds.xuatDanhSach();
	                    break;
	                case 3:
	                    ds.themSinhVien();
	                    break;
	                case 4:
	                    ds.timKiemTheoMa();
	                    break;
	                case 5:
	                    ds.xoaTheoMa();
	                    break;
	                case 6:
	                    ds.sapXepTheoDiem();
	                    break;
	                case 0:
	                    cout << "\nKet thuc chuong trinh";
	                    break;
	                default:
	                    cout << "\nLua chon khong hop le, vui long chon lai!" << endl;
	                    break;
	            }
	        } while(chon != 0);
	    }
};


int main(){
	App app;
	app.run();
	return 0;
}
