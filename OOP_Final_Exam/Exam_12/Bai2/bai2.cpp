#include<iostream>
#include<list>
#include<iomanip>

using namespace std;

class HangHoa{
	protected:
		string maHang;
		string tenHang;
		int soLuong;
		long long giaNhap;
	public:
		HangHoa(string maHang = "", string tenHang = "", int soLuong = 0, long long giaNhap = 0.0f)
		: maHang(maHang), tenHang(tenHang), soLuong(soLuong), giaNhap(giaNhap){}
		
		string getMaHang(){
			return maHang;
		}
		
		void nhap(){
			cout << "Nhap ma hang:";		getline(cin, maHang);
			cout << "Nhap ten hang:";		getline(cin, tenHang);
			cout << "Nhap so luong:";		cin >> soLuong;
			cout << "Nhap gia nhap:";		cin >> giaNhap;
		}
		
		void xuat(){
			cout << left
				 << setw(12) << maHang
				 << setw(20) << tenHang
				 << setw(12) << soLuong
				 << setw(12) << giaNhap;
		}
};

class ThucPham : public HangHoa{
	private:
		int hanSuDung;
		long long phiBaoQuan;
	public:
		ThucPham(string maHang = "", string tenHang = "", int soLuong = 0, long long giaNhap = 0.0f, int hanSuDung = 0, long long phiBaoQuan = 0)
		: HangHoa(maHang, tenHang, soLuong, giaNhap), hanSuDung(hanSuDung), phiBaoQuan(phiBaoQuan){}
		
		long long getGiaBan(){
			return giaNhap * 1.15 + phiBaoQuan;
		}
		
		int getHanSuDung(){
			return hanSuDung;
		}
		
		void nhap(){
			HangHoa::nhap();
			cout << "Nhap hang su dung:";		cin >> hanSuDung;
			cout << "Nhap phiBaoQuan:";			cin >> phiBaoQuan;		cin.ignore();
		}
		
		void xuat(){
			HangHoa::xuat();
			cout << setw(12) << hanSuDung
				 << setw(12) << phiBaoQuan << endl;
		}
};

class GiaDung : public HangHoa{
	private:
		int congSuat;
		int thoiGianBaoHanh;
	public:
		GiaDung(string maHang = "", string tenHang = "", int soLuong = 0, long long giaNhap = 0.0f, int congSuat, int thoiGianBaoHanh)
		: HangHoa(maHang, tenHang, soLuong, giaNhap), congSuat(congSuat), thoiGianBaoHanh(thoiGianBaoHanh){}
		
		int getCongSuat(){
			return congSuat;
		}
		
		int getThoiGianBaoHanh(){
			return thoiGianBaoHanh;
		}
		
		void nhap(){
			HangHoa::nhap();
			cout << "Nhap cong suat:";		cin >> congSuat;
			cout << "Nhap thoi gian bao hanh:";		cin >> thoiGianBaoHanh; 		cin.ignore();
		}
		
		void xuat(){
			HangHoa::xuat();
			cout << setw(12) << congSuat
				 << setw(12) << thoiGianBaoHanh << endl;
		}
};
