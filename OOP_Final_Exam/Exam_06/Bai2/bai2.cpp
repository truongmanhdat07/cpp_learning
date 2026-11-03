#include<iostream>
#include<string>
#include<iomanip>
#include<vector>
using namespace std;

class QLH{
	private:
		string maHang = "";
		string tenHang = "";
		string xuatXu = "";
		int loaiHang = 0;
		int soLuong = 0;
	public:
		QLH(){}
		QLH(string maHang, string tenHang, string xuatXu, int loaiHang, int soLuong){
			this->maHang = maHang;
			this->tenHang = tenHang;
			this->xuatXu = xuatXu;
			this->loaiHang = loaiHang;
			this->soLuong = soLuong;
		}
		
		~QLH(){}
		
		int getLoai(){
			return loaiHang;
		}
		
		string getTen(){
			return tenHang;
		}
		
		int getSoLuong(){
			return soLuong;
		}
		
		virtual void nhap(){
			cout << "\nNhap ma hang:";		getline(cin, maHang);
			cout << "Nhap ten hang:";		getline(cin, tenHang);
			cout << "Nhap xuat xu:";		getline(cin , xuatXu);
			cout << "Nhap loai hang:";		cin >> loaiHang;
			cout << "Nhap so luong:";		cin >> soLuong;
		}
		
		virtual void xuat(){
			cout << left 
				 << setw(12) << maHang
				 << setw(25) << tenHang
				 << setw(20) << xuatXu
				 << setw(12) << loaiHang
				 << setw(12) << soLuong;
		}
};


class DIENTU : public QLH{
	private:
		int tgbh = 0;
	public:
		DIENTU(){}
		DIENTU(string maHang, string tenHang, string xuatXu, int loaiHang, int soLuong, int tgbh)
		: QLH(maHang, tenHang, xuatXu, loaiHang, soLuong), tgbh(tgbh){}
		
		int getTgbh(){
			return tgbh;
		}
		
		void nhap() override{
			QLH::nhap();
			cout << "Nhap thoi gian bao hanh:";		cin >> tgbh;		cin.ignore();
		}
		
		void xuat() override{
			QLH::xuat();
			cout << setw(12) << tgbh << endl;
		}
};

void nhapDanhSach(vector<DIENTU> &danhSach, int soLuong){
	for(int i=0; i<soLuong; i++){
		cout << "Nhap thong tin mat hang dien tu thu " << i+1 << ":";
		danhSach[i].nhap();
	}
}

void thongKe(vector<DIENTU> &danhSach){
	int loai1 = 0, loai2 = 0, loai3 = 0;
	for(int i=0; i<danhSach.size(); i++){
		if(danhSach[i].getTgbh() >= 12){
			if(danhSach[i].getLoai() == 1)			loai1 += danhSach[i].getSoLuong();
			else if(danhSach[i].getLoai() == 2)		loai2 += danhSach[i].getSoLuong();
			else									loai3 += danhSach[i].getSoLuong();
		}
	}
	
	cout << "\nSo luong mat hang co tgbh >= 12 la:";
	cout << "\nLoai 1:" << loai1;
	cout << "\nLoai 2:" << loai2;
	cout << "\nLoai 3:" << loai3;
}

void timMatHangTheoTen(vector<DIENTU> &danhSach, string ten){
	bool timThay = false;
	for(int i=0; i<danhSach.size(); i++){
		if(danhSach[i].getTen() == ten){
			cout << "\nDa tim thay mat hang " << ten << ":" << endl;
			danhSach[i].xuat();
			timThay = true;
		}
	}
	if(timThay == false){
		cout << "\nKhong tim thay mat hang " << ten << "!";
	}
}

int main(){
	int soLuong;
	cout << "Nhap so luong mat hang dien tu:";		cin >> soLuong;		cin.ignore();
	
	vector<DIENTU> danhSach(soLuong);
	
	nhapDanhSach(danhSach, soLuong);
	
	thongKe(danhSach);
	
	string ten;		cout << "\nNhap ten mat hang can tim:";		getline(cin, ten);
	timMatHangTheoTen(danhSach, ten);
	
	return 0;
}
