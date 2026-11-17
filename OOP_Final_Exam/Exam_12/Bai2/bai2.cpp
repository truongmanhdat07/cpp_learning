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
			cout << "Nhap phi bao quan:";			cin >> phiBaoQuan;		cin.ignore();
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
		GiaDung(string maHang = "", string tenHang = "", int soLuong = 0, long long giaNhap = 0.0f, int congSuat = 0, int thoiGianBaoHanh = 0)
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

template<typename T>
void nhapDanhSach(list<T> &ds, int sl){
	for(int i=0; i<sl; i++){
		cout << "Nhap hang hoa thu " << i+1 << ":" << endl;
		T x;
		x.nhap();
		ds.push_back(x);
	}
}

void maxGiaBan(list<ThucPham> &dstp){
	long long max = dstp.begin()->getGiaBan();
	for(auto it = dstp.begin(); it != dstp.end(); it++){
		if(it->getGiaBan() > max)	max = it->getGiaBan();
	}
	
	cout << "\nThuc pham co gia ban cao nhat la:" << endl;
	for(auto it = dstp.begin(); it != dstp.end(); it++){
		if(it->getGiaBan() == max)		it->xuat();
	}
}

void thongKeHetHan(list<ThucPham> &dstp){
	int dem = 0;
	for(auto it = dstp.begin(); it != dstp.end(); it++){
		if(it->getHanSuDung() <= 3){
			if(dem == 0)		cout << "\nDanh sach thuc pham sap het han la:" << endl;
			it->xuat();
			dem++;
		}
	}
	if(dem == 0) cout << "\nKhong co thuc pham nao sap het han";
}

void maxCongSuat(list<GiaDung> &dsgd){
	int max = dsgd.begin()->getCongSuat();
	for(auto it = dsgd.begin(); it != dsgd.end(); it++){
		if(it->getCongSuat() > max)	max = it->getCongSuat();
	}
	
	cout << "\nGia dung co cong suat cao nhat la:" << endl;
	for(auto it = dsgd.begin(); it != dsgd.end(); it++){
		if(it->getCongSuat() == max)		it->xuat();
	}
}

void thongKeBaoHanh(list<GiaDung> &dsgd){
	int bhn = 0, kbhn = 0;
	for(auto it = dsgd.begin(); it != dsgd.end(); it++){
		if(it->getThoiGianBaoHanh() >= 12)		bhn++;
		else									kbhn++;
	}
	
	cout << "\nThong ke so luong san pham:" << endl;
	cout << "TGBH >= 12 :" << bhn << endl;
	cout << "TGBBH < 12 :" << kbhn << endl;
}

void timKiemTheoMa(list<GiaDung> &dsgd){
	string ma;
	cout << "\nNhap ma can tim:";		getline(cin >> ws, ma);
	
	bool timThay = false;
	for(auto it = dsgd.begin(); it != dsgd.end(); it++){
		if(it->getMaHang() == ma){
			if(!timThay)	cout << "\nDa tim thay do gia dung co ma " << ma << ":" << endl;
			it->xuat();
			timThay = true;
		}
	}
	if(!timThay)	cout << "\nKhong tim thay do gia dung co ma "  << ma << endl;
}

int main(){
	int n;
	cout << "Nhap so luong thuc pham:";		cin >> n;		cin.ignore();
	list<ThucPham> dstp;
	
	nhapDanhSach(dstp, n);
	
	maxGiaBan(dstp);
	
	thongKeHetHan(dstp);
	
	
	int m;
	cout << "\nNhap so luong gia dung:";	cin >> m;		cin.ignore();
	list<GiaDung> dsgd;
	
	nhapDanhSach(dsgd, m);
	
	maxCongSuat(dsgd);
	
	thongKeBaoHanh(dsgd);
	
	timKiemTheoMa(dsgd);
	
	return 0;
}
