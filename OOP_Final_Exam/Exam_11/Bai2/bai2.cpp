#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;

class BatDongSan{
	protected:
		string ma;
		string diaChi;
		float dienTich;
		float donGia;
	public:
		BatDongSan(string ma = "", string diaChi = "", float dienTich = 0.0f, float donGia = 0.0f)
		: ma(ma), diaChi(diaChi), dienTich(dienTich), donGia(donGia){}
		
		float getDienTich(){
			return dienTich;
		}
		
		string getMa(){
			return ma;
		}
		
		void nhap(){
			cout << "Nhap ma:";			getline(cin, ma);
			cout << "Nhap dia chi:";	getline(cin, diaChi);
			cout << "Nhap dien tich:";	cin >> dienTich;
			cout << "Nhap don gia:";	cin >> donGia;
		}
		
		void xuat(){
			cout << left 
				 << setw(12) << ma
				 << setw(20) << diaChi
				 << setw(12) << dienTich
				 << setw(12) << donGia;
		}
};


class NhaO : public BatDongSan{
	private:
		int soTang;
		float phiSanVuon;
	public:
		NhaO(string ma = "", string diaChi = "", float dienTich = 0.0f, float donGia = 0.0f, int soTang = 0, float phiSanVuon = 0.0f)
		: BatDongSan(ma, diaChi, dienTich, donGia), soTang(soTang), phiSanVuon(phiSanVuon){}
		
		float getGia(){
			return dienTich * donGia * soTang * 0.9 + phiSanVuon;
		}
		
		int getSoTang(){
			return soTang;
		}
		
		void nhap(){
			BatDongSan::nhap();
			cout << "Nhap so tang:";		cin >> soTang;
			cout << "Nhap chi phi san vuon:";		cin >> phiSanVuon;		cin.ignore();
		}
		
		void xuat(){
			BatDongSan::xuat();
			cout << setw(12) << soTang
				 << setw(12) << phiSanVuon << endl;
		}
};

class DatTrong : public BatDongSan{
	private:
		string huongDat;
		string loaiDat;
	public:
		DatTrong(string ma = "", string diaChi = "", float dienTich = 0.0f, float donGia = 0.0f, string huongDat = "", string loaiDat = "")
		: BatDongSan(ma, diaChi, dienTich, donGia), huongDat(huongDat), loaiDat(loaiDat){}
		
		string getLoaiDat(){
			return loaiDat;
		}
		
		void nhap(){
			BatDongSan::nhap();
			cout << "Nhap loai dat:";		getline(cin >> ws, loaiDat);
			cout << "Nhap huong dat:";		getline(cin, huongDat);
		}
		
		void xuat(){
			BatDongSan::xuat();
			cout << setw(12) << loaiDat
				 << setw(12) << huongDat << endl;
		}
};

template <typename T>
void nhapDanhSach(vector<T> &ds, int sl){
	for(int i=0; i<sl; i++){
		cout << "\nNhap bat dong san thu " << i+1 << ":" << endl;
		ds[i].nhap();
	}
}

int maxGia(vector<NhaO> &dsno){
	int viTri = 0;
	float max = dsno[viTri].getGia();
	for(int i=0; i<dsno.size(); i++){
		if(dsno[i].getGia() > max){
			max = dsno[i].getGia();
			viTri = i;
		}
	}
	return viTri;
}

void thongKeTheoTang(vector<NhaO> &dsno, int tang){
	int dem = 0;
	for(int i=0; i<dsno.size(); i++){
		if(dsno[i].getSoTang() == tang){
			if(dem == 0)	cout << "\nDanh sach nha co " << tang << " tang la:" << endl;
			dsno[i].xuat();
			dem++;
		}
	}
	if(dem == 0)		cout << "\nKhong co nha nao co " << tang << " tang";
}

int maxDienTich(vector<DatTrong> &dsdt){
	int viTri = 0;
		float max = dsdt[viTri].getDienTich();
		for(int i=0; i<dsdt.size(); i++){
			if(dsdt[i].getDienTich() > max){
				max = dsdt[i].getDienTich();
				viTri = i;
			}
		}
		return viTri;	
}

void thongKeTheoLoai(vector<DatTrong> &dsdt){
	int thoCu = 0, nongNghiep = 0;
	for(int i=0; i<dsdt.size(); i++){
		if(dsdt[i].getLoaiDat() == "tho cu")	thoCu++;
		else									nongNghiep++;
	}
	
	cout << "\nSo manh dat tho cu la:" << thoCu;
	cout << "\nSo manh dat nong nghiep la:" << nongNghiep;
}

void timTheoMa(vector<DatTrong> &dsdt, string ma){
	for(int i=0; i<dsdt.size(); i++){
		if(dsdt[i].getMa() == ma){
			cout << "\nDa tim thay manh dat co ma " << ma << endl;
			dsdt[i].xuat();
			return;
		}
	}
	cout << "\nKhong tim thay manh dat co ma " << ma << endl;
}


int main(){
	int n;
	cout << "Nhap so nha o:";		cin >> n;		cin.ignore();
	vector<NhaO> dsno(n);
	
	nhapDanhSach(dsno, n);
	
	cout << "\nNha co gia cao nhat la: " << endl;		dsno[maxGia(dsno)].xuat();
	int tang;
	cout << "\nNhap so tang can thong ke:";		cin >> tang;
	
	
	thongKeTheoTang(dsno, tang);
	
	
	int m;
	cout << "\nNhap so luong manh dat:";		cin >> m;		cin.ignore();
	vector<DatTrong> dsdt(m);
	
	nhapDanhSach(dsdt, m);
	
	cout << "\nManh dat co dien tich lon nhat la:" << endl;		dsdt[maxDienTich(dsdt)].xuat();
	
	thongKeTheoLoai(dsdt);
	
	string ma;
	cout << "\nNhap ma dat can tim:";		getline(cin >> ws, ma);
	
	timTheoMa(dsdt, ma);
	
	return 0;
}
