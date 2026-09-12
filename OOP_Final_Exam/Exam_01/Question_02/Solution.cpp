#include<iostream>
#include<iomanip>
#include<fstream>

using namespace std;


class NhanVien{
	private:
		string maNV;
		string hoTen;
		int loaiHopDong;
	public:
		NhanVien() : maNV(""), hoTen(""), loaiHopDong(0){}
		NhanVien(string maNV, string hoTen, int loaiHopDong);
		~virtual ~NhanVien(){}
		
		virtual int getLuong() = 0;
		
};

class ThoiVu : public NhanVien{
	private:
		int soNgayCong;
		int donGia;
	public:
		ThoiVu() : NhanVien(), soNgayCong(0), donGia(0){};
		ThoiVu(string maNV, string hoTen, int loaiHopDong, int soNgayCong, int donGia);
		
		int getLuong() override;
};

class ChinhThuc : public NhanVien{
	private:
		float heSoLuong;
		int thamNien;
	public:
		ChinhThuc() : NhanVien(), heSoLuong(0.0f), thamNien(0){}
		ChinhThuc(string maNV, string hoTen, int loaiHopDong,float heSoLuong, int thamNien);
		
		int getLuong() override;
};




NhanVien::NhanVien(string maNV, string hoTen, int loaiHopDong){
	this->maNV = maNV;
	this->hoTen = hoTen;
	this->loaiHopDong = loaiHopDong;
}










ThoiVu::ThoiVu(string maNV, string hoTen, int loaiHopDong, int soNgayCong, int donGia) 
	   : NhanVien(maNV, hoTen, loaiHopDong){
				
	this->soNgayCong = soNgayCong;
	this->donGia = donGia;
}

int ThoiVu::getLuong(){
	int luong = soNgayCong * donGia ;
	
	if(soNgayCong >= 25)	thuong += 2500000;
	
	return luong;
}







ChinhThuc::ChinhThuc(string maNV, string hoTen, int loaiHopDong, float heSoLuong, int thamNien) 
		  :NhanVien(maNV, hoTen, loaiHopDong){
		  	
	this->heSoLuong = heSoLuong;
	this->thamNien = thamNien;
}

int ChinhThuc::getLuong(){
	int luongCoBan = 1050000;
	int luong = luongCoBan * heSoLuong;
	
	if(thamNien >= 3)	luong += luongCoBan * 1.2;
	
	return luong;
}
