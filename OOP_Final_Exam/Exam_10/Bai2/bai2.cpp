#include<iostream>
#include<vector>
#include<iomanip>

using namespace std;

class TrangBi{
	protected:
		string ma;
		string ten;
		int level;
	public:
		TrangBi(string ma = "", string ten = "", int level = 0) : ma(ma), ten(ten), level(level){}
		
		string getTen(){
			return ten;
		}
		
		int getLevel(){
			return level;
		}
		
		void nhap(){
			cout << "Nhap ma:";		getline(cin, ma);
			cout << "Nhap ten:";	getline(cin, ten);
			cout << "Nhap level requirement:";		cin >> level;
		}
		
		void xuat(){
			cout << left 
				 << setw(12) << ma
				 << setw(20) << ten
				 << setw(12) << level;
		}
};

class VuKhi : public TrangBi{
	private:
		float satThuong;
		float tocDoDanh;
	public:
		VuKhi(string ma = "", string ten = "", int level = 0, float satThuong = 0, float tocDoDanh = 0)
		: TrangBi(ma, ten, level), satThuong(satThuong), tocDoDanh(tocDoDanh){}
		
		float getDPS(){
			return satThuong * tocDoDanh;
		}
		
		void nhap(){
			TrangBi::nhap();
			cout << "Nhap sat thuong:";		cin >> satThuong;
			cout << "Nhap toc do danh:";	cin >> tocDoDanh;		cin.ignore();
		}
		
		void xuat(){
			TrangBi::xuat();
			cout << setw(12) << satThuong 
				 << setw(12) << tocDoDanh << endl;
		}
};

class AoGiap : public TrangBi{
	private:
		float giap;
		float khangPhep;
	public:
		AoGiap(string ma = "", string ten = "", int level = 0, float giap = 0, float khangPhep = 0)
		: TrangBi(ma, ten, level), giap(giap), khangPhep(khangPhep){}
		
		float getGiap(){
			return giap;
		}
		
		float getKhangPhep(){
			return khangPhep;
		}
		
		void nhap(){
			TrangBi::nhap();
			cout << "Nhap giap:";		cin >> giap;
			cout << "Nhap khang phep:";	cin >> khangPhep;		cin.ignore();
		}
		
		void xuat(){
			TrangBi::xuat();
			cout << setw(12) << giap 
				 << setw(12) << khangPhep << endl;
		}
};

template<typename T> 
void nhapDanhSach(vector<T> &ds, int sl){
	for(int i=0; i<sl; i++){
		cout << "Nhap thong tin trang bi thu " << i+1 << ":" << endl;
		ds[i].nhap();
	}
}

int maxDPS(vector<VuKhi> &dsvk){
	int viTri = 0;
	float max = dsvk[0].getDPS();
	for(int i=1; i<dsvk.size(); i++){
		if(dsvk[i].getDPS() > max){
			max = dsvk[i].getDPS();
			viTri = i;
		}
	}
	return viTri;
}

void timKiemTheoTen(vector<VuKhi> &dsvk, string ten){
	int dem = 0;
	for(int i=0; i<dsvk.size(); i++){
		if(dsvk[i].getTen() == ten){
			if(dem == 0)	cout << "\nDa tim thay vu khi " << ten << ":" << endl;	
			dsvk[i].xuat();
			dem++;
		}
	}
	if(dem == 0)	cout << "\nKhong tim thay vu khi " << ten;
}

int maxGiap(vector<AoGiap> &dsag){
	int viTri = 0;
	float max = dsag[0].getGiap();
	for(int i=1; i<dsag.size(); i++){
		if(dsag[i].getGiap() > max){
			max = dsag[i].getGiap();
			viTri = i;
		}
	}
	return viTri;
}

void thongKeAoGiap(vector<AoGiap> &dsag){
	int tanThu = 0, caoCap = 0;
	for(int i=0; i<dsag.size(); i++){
		if(dsag[i].getLevel() <= 30)		tanThu++;
		else								caoCap++;
	}
	
	cout << "\nSo luong cap bac ao giap la:" << endl;
	cout << "Ao giap tan thu:" << tanThu << endl ;
	cout << "Ao giap cao cap:" << caoCap << endl;
}

void thongKeGiapPhep(vector<AoGiap> &dsag){
	int dem = 0;
	for(int i=0; i<dsag.size(); i++){
		if(dsag[i].getKhangPhep() >= 100){
			if(dem == 0)	cout << "\nDanh sach giap co tren 100 khang phep la:" << endl;
			dsag[i].xuat();
			dem++;
		}
	}
	if(dem == 0)	cout << "\nKhong co giao nao co tren 100 khang phep";
}


int main(){
	int n;
	cout << "Nhap so luong vu khi:";		cin >> n; 	cin.ignore();
	vector<VuKhi> dsvk(n);
	
	nhapDanhSach(dsvk, n);
	
	cout << "\nVu khi co DPS cao nhat la:" << endl;
	dsvk[maxDPS(dsvk)].xuat();
	
	string ten;
	cout << "\nNhap ten vu khi can tim:";		getline(cin >> ws, ten);
	timKiemTheoTen(dsvk, ten);
	
	int m;
	cout << "\nNhap so luong ao giao:";		cin  >> m;		cin.ignore();
	
	vector<AoGiap> dsag(m);
	
	nhapDanhSach(dsag, m);
	
	cout << "\nGiap co diem  giap cao nhat la:" << endl;
	dsag[maxGiap(dsag)].xuat();
	
	thongKeAoGiap(dsag);
	
	thongKeGiapPhep(dsag);
	
	return 0;
}
