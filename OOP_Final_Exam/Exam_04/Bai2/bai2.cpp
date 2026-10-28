#include<iostream>
#include<vector>
#include<iomanip>

using namespace std;

class Nguoi{
	protected:
		string cccd;
		string hoTen;
	public:
		Nguoi(){}
		Nguoi(string cccd, string hoTen) : cccd(cccd), hoTen(hoTen){}
		
		string getHoTen(){
			return hoTen;
		}
		
		virtual void nhap(){
			cout << "\nNhap cccd:";		getline(cin, cccd);
			cout << "Nhap hoTen:";		getline(cin, hoTen);
		}
		
		virtual void xuat(){
			cout << left
				 << setw(20) << cccd
				 << setw(25) << hoTen;
		}
};

class NhanVien : public Nguoi{
	private:
		int namSinh;
		float heSoLuong;
	public:
		NhanVien(){}
		NhanVien(string cccd, string hoTen, int namSinh, float heSoLuong) : Nguoi(cccd, hoTen), namSinh(namSinh), heSoLuong(heSoLuong){}
		
		int getTuoi(){
			return 2026 - namSinh;
		}
		
		float getLuong(){
			return heSoLuong * 1.5;
		}
		
		void nhap() override{
			Nguoi::nhap();
			cout << "Nhap nam sinh:";		cin >> namSinh;
			cout << "Nhap he so luong:";	cin >> heSoLuong;		cin.ignore();
		}
		
		void xuat() override{
			Nguoi::xuat();
			cout << setw(12) << namSinh
				 << setw(15) << getLuong() << endl;
		}
		
};

class SinhVien : public Nguoi{
	private:
		int maLop;
		float diem;
	public:
		SinhVien(){}
		SinhVien(string cccd, string hoTen, int maLop, float diem) : Nguoi(cccd, hoTen), maLop(maLop), diem(diem){}
		
		float getDiem(){
			return diem;
		}
		
		int getMaLop(){
			return maLop;
		}
		
		void nhap() override{
			Nguoi::nhap();
			cout << "Nhap ma lop:";		cin >> maLop;
			cout << "Nhap diem:";		cin >> diem;		cin.ignore();
		}
		
		void xuat() override{
			Nguoi::xuat();
			cout << setw(12) << maLop
				 << setw(15) << diem << endl;
		}
};

template <typename T>
void nhapDanhSach(vector<T> &ds, int soLuong){
	for(int i=0; i<soLuong; i++){
		cout << "Nhap thong tin nguoi thu " << i+1 << ":";
		ds[i].nhap();
	}
}

template <typename T>
void xuatDanhSachNV(vector<T> &ds){
	for(int i=0; i<ds.size(); i++){
		ds[i].xuat();
	}
}

int maxTuoi(vector<NhanVien> &dsnv){
	int viTri = 0;
	int max = dsnv[0].getTuoi();
	for(int i=0; i<dsnv.size(); i++){
		if(dsnv[i].getTuoi() > max)	{
			max = dsnv[i].getTuoi();
			viTri = i;
		}
	}
	return viTri;
}

void timKiem(vector<NhanVien> &dsnv, string hoTenCanTim){
	for(int i=0; i<dsnv.size(); i++){
		if(dsnv[i].getHoTen() == hoTenCanTim){
			cout << "\nDa tim thay nhan vien co ten " << hoTenCanTim << endl;
			dsnv[i].xuat();
			return;
		}
	}
	cout << "\nKhong tim thay nhan vien co ten " << hoTenCanTim;
}

int demTruot(vector<SinhVien> &dssv, float diemChuan){
	int dem = 0;
	for(int i=0; i<dssv.size(); i++){
		if(dssv[i].getDiem() < diemChuan)	dem++;
	}
	return dem;
}

void thongKeSV(vector<SinhVien> &dssv){
	int lop1 = 0, lop2 = 0, lop3 = 0;
	for(int i=0; i<dssv.size(); i++){
		if(dssv[i].getMaLop() == 1)			lop1++;
		else if(dssv[i].getMaLop() == 2)	lop2++;
		else								lop3++;
	}
	
	cout << "\nSo Sv lop 1 la:" << lop1;
	cout << "\nSo Sv lop 2 la:" << lop2;
	cout << "\nSo Sv lop 3 la:" << lop3;
	
	int max = lop1;
	if(lop2 > max)	max = lop2;
	if(lop3 > max)	max = lop3;
	
	
	cout << "\nLop co nhieu sinh vien nhat la :";
	if(lop1 == max)			cout << "lop1";
	else if(lop2 == max)	cout << "lop2";
	else					cout << "lop3";
}

void truot(vector<SinhVien> &dssv, string hoTenSV, float diemChuan){
	bool timThay = false;
	for(int i=0; i<dssv.size(); i++){
		if(dssv[i].getHoTen() == hoTenSV)	timThay = true;
		if(timThay){
			if(dssv[i].getDiem() < diemChuan)	cout << "\nTruot";
			else								cout << "\nDo";
			return;
		}
	}
	cout << "\nKhong tim thay sinh vien " << hoTenSV << " trong danh sach!";
}

int minDiem(vector<SinhVien> &dssv){
	int viTri = 0 ;
	float min = dssv[0].getDiem();
	for(int i=0; i<dssv.size(); i++){
		if(dssv[i].getDiem() < min){
			min = dssv[i].getDiem();
			viTri = i;	
		}
	}
	return viTri;
}

int main(){
	int n, m;
	cout << "Nhap so luong nhan vien:";	cin >> n;	cin.ignore();
	
	vector<NhanVien> dsnv(n);
	
	nhapDanhSach(dsnv, n);
	
	cout << "\nDanh sach nhan vien vua nhap la:" << endl;
	xuatDanhSachNV(dsnv);
	
	cout << "\nNhan vien lon tuoi nhat la:" << endl;
	dsnv[maxTuoi(dsnv)].xuat();
	
	string hoTenCanTim;
	cout << "\nNhap ho ten nhan vien can tim:";		getline(cin, hoTenCanTim);
	timKiem(dsnv, hoTenCanTim);
	
	cout << "\nNhap so luong sinh vien:";	cin >> m;	cin.ignore();
	
	vector<SinhVien> dssv(m);
	
	nhapDanhSach(dssv, m);
	
	cout << "\nSinh vien co diem thap nhat la:" << endl;
	dssv[minDiem(dssv)].xuat();
	
	float diemChuan;	
	cout << "\nNhap diem chuan:";	cin >> diemChuan;	cin.ignore();
	
	cout << "\nSo luong sinh vien truot la:" << demTruot(dssv, diemChuan);
	
	cout << "\nThong ke so hoc sinh theo lop:";
	thongKeSV(dssv);
	
	string hoTenSV;
	cout << "\nNhap ho ten sinh vien:";		getline(cin, hoTenSV);
	truot(dssv, hoTenSV, diemChuan);
	
	return 0;
}
