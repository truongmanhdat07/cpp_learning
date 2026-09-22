#include<iostream>
#include<list>
#include<iomanip>
using namespace std;


class SinhVien{
	private:
		string maSV;
		string hoTen;
		int ngay, thang , nam;
		string gioiTinh;
		string queQuan;
	public:
		SinhVien(string maSV = "", string hoTen = "", int ngay = 0, int thang = 0, int nam = 0,
				 string gioiTinh = "", string queQuan = "");
				 
		void nhap();
		void xuat() const;
};


void nhapDanhSach(list<SinhVien> &danhSach, int soLuong);
void xuatDanhSach(list<SinhVien> &danhSach);
void solution(list<SinhVien> &danhSach);



SinhVien::SinhVien(string maSV, string hoTen, int ngay, int thang, int nam, string gioiTinh, string queQuan){
	this->maSV = maSV;
	this->hoTen = hoTen;
	this->ngay = ngay;
	this->thang = thang;
	this->nam = nam;
	this->gioiTinh = gioiTinh;
	this->queQuan = queQuan;
}

void SinhVien::nhap(){
	cout << "Nhap ma sinh vien:";	getline(cin, maSV);
	cout << "Nhap ho ten:";			getline(cin, hoTen);
	cout << "Nhap gioi tinh:";		getline(cin, gioiTinh);
	cout << "Nhap que quan:";		getline(cin, queQuan);
	cout << "Nhap ngay, thang, nam sinh:";		cin >> ngay >> thang >> nam ;	cin.ignore();
}

void SinhVien::xuat() const{
	cout << left 
		 << setw(15) << maSV
		 << setw(20) << hoTen
		 << setw(15) << gioiTinh
		 << setw(15) << queQuan
		 << setfill('0') << setw(2) << ngay << "|" << thang << "|" << nam << setfill(' ') << endl;
}



int main(){
	int soLuong;
	cout << "Nhap so luong sinh vien:";		cin >> soLuong;		cin.ignore();
	
	list<SinhVien> danhSach;
	
	nhapDanhSach(danhSach, soLuong);
	
	cout << "\nDanh sach sinh vien vua nhap la:" << endl;
	xuatDanhSach(danhSach);
	
	solution(danhSach);
	
	return 0;
}


void nhapDanhSach(list<SinhVien> &danhSach, int soLuong){
	for(int i=0; i<soLuong; i++){
		cout << "Nhap thong tin sinh vien thu " << i+1 << endl;
		SinhVien sv;
		sv.nhap();
		danhSach.push_back(sv);
	}
}

void xuatDanhSach(list<SinhVien> &danhSach){
	for(auto it = danhSach.begin(); it != danhSach.end(); it++){
		it->xuat();
	}
}

void solution(list<SinhVien> &danhSach){
	cout << "Nhap thong tin sinh vien them cuoi danh sach:" << endl;
	SinhVien sv1;
	sv1.nhap();
	danhSach.push_back(sv1);
	
	cout << "Nhap thong tin sinh vien them dau danh sach:" << endl;
	SinhVien sv2;
	sv2.nhap();
	danhSach.push_front(sv2);
	
	int viTriXoa;
	cout << "Nhap vi tri i can xoa:";	cin >> viTriXoa;	cin.ignore();

	auto itXoa = danhSach.begin();
	for(int i = 0; i < viTriXoa; i++){
		itXoa++;
	}
	danhSach.erase(itXoa);
	cout << "Xoa thanh cong sinh vien thu " << viTriXoa << " trong danh sach!" << endl;
	
	int viTriThayThe;
	cout << "Nhap vi tri i can thay the:";	cin >> viTriThayThe;	cin.ignore();

	auto itThayThe = danhSach.begin();
	for(int i = 0; i < viTriThayThe; i++){
		itThayThe++;
	}

	cout << "Nhap thong tin sinh vien thay the vao vi tri " << viTriThayThe << " cua danh sach:" << endl;
	SinhVien sv3;
	sv3.nhap();
	*itThayThe = sv3;
	
	cout << "\nDanh sach hien tai:" << endl;
	xuatDanhSach(danhSach);
}
