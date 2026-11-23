#include<iostream>
#include<iomanip>
#include<vector>

using namespace std;

class Phong{
	protected:
		string ma;
		string ten;
		int snt;
		long long dg;
	public:
		Phong(string ma = "", string ten = "", int snt = 0, long long dg = 0) : ma(ma), ten(ten), snt(snt), dg(dg){}
		
		string getTen(){
			return ten;
		}
		
		int getSoNgayThue(){
			return snt;
		}
		
		void nhap(){
			cout << "Nhap ma:";		getline(cin, ma);
			cout << "Nhap ten:";	getline(cin, ten);
			cout << "Nhap so ngay thue:";		cin >> snt;
			cout << "Nhap don gia 1 ngay :";	cin >> dg;
		}
		
		void xuat(){
			cout << left
				 << setw(12) << ma 
				 << setw(25) << ten
				 << setw(12) << snt
				 << setw(12) << dg;
		}
};

class PhongVip : public Phong{
	private:
		long long pdv;
		long long ptq;
	public:
		PhongVip(string ma = "", string ten = "", int snt = 0, long long dg = 0, long long pdv = 0, long long ptq = 0)
		: Phong(ma, ten, snt, dg) , pdv(pdv), ptq(ptq){}
		
		double getTienPhong(){
			return snt * dg * 1.2 + pdv + ptq;
		}
		
		void nhap(){
			Phong::nhap();
			cout << "Nhap phi dich vu:";		cin >> pdv;
			cout << "Nhap phi don tiep:";		cin >> ptq;		cin.ignore();
		}
		
		void xuat(){
			Phong::xuat();
			cout << setw(12) << pdv
				 << setw(12) << ptq << endl;
		}
};

class PhongStandard : public Phong{
	private:
		int lg;
		long long pt;
	public:
		PhongStandard(string ma = "", string ten = "", int snt = 0, long long dg = 0, int lg = 0, long long pt = 0)
			: Phong(ma, ten, snt, dg), lg(lg), pt(pt){}
		
		int getLoaiGiuong(){
			return lg;
		}
			
		void nhap(){
			Phong::nhap();
			cout << "Nhap loai giuong (1-don, 2-doi) :";		cin >> lg;
			cout << "Nhap phu thu:";		cin >> pt;		cin.ignore();
		}
		
		void xuat(){
			Phong::xuat();
			cout << setw(12) << lg
				 << setw(12) << pt << endl;
		}
};

template <typename T>
void nhapDanhSach(vector<T> &ds, int sl){
	for(int i=0; i<sl; i++){
		cout << "Nhap phong thu " << i+1 << ":" << endl;
		ds[i].nhap();
	}
}

int maxTienPhong(vector<PhongVip> &dspv){
	int vt = 0;
	double max = dspv[vt].getTienPhong();
	for(int i = 1; i < dspv.size(); i++){
		if(dspv[i].getTienPhong() > max){
			vt = i;
			max = dspv[i].getTienPhong();
		}
	}
	return vt;
}

void timKiemTheoTen(vector<PhongVip> &dspv){
	string t;
	cout << "\nNhap ten phong can tim:";		getline(cin >> ws, t);
	bool timThay = false;
	for(int i=0; i<dspv.size(); i++){
		if(dspv[i].getTen() == t){
			if(!timThay)	cout << "\nDa tim thay phong co ten " << t << endl;
			dspv[i].xuat();
			timThay = true;
		}
	}
	if(!timThay)		cout << "\nKhong tim thay phong co ten " << t;
}

int maxNgayThue(vector<PhongStandard> &dsptc){
	int vt = 0;
	int max = dsptc[vt].getSoNgayThue();
	for(int i=0; i<dsptc.size(); i++){
		if(dsptc[i].getSoNgayThue() > max){
			max = dsptc[i].getSoNgayThue();
			vt = i;
		}
	}
	return vt;
}

void thongKeTheoLoaiGiuong(vector<PhongStandard> &dsptc){
	int don = 0, doi = 0;
	for(int i=0; i<dsptc.size(); i++){
		if(dsptc[i].getLoaiGiuong() == 1)	don ++;
		else								doi ++;
	}
	
	cout << "\nSo phong don:" << don;
	cout << "\nSo phong doi:" << doi;
}

void ThongKeSoNgayThueLonHonNamNgay(vector<PhongStandard> &dsptc){
	int dem = 0;
	for(int i=0; i<dsptc.size(); i++){
		if(dsptc[i].getSoNgayThue() >= 5){
			if(dem==0)	cout << "\nDanh sach phong so so ngay thue tu 5 ngay tro len la:" << endl;
			dsptc[i].xuat();
			dem++;
		}
	}
	if(dem == 0)	cout << "\nKhong co phong nao co so ngay thue tu 5 ngay tro len";
}


int main(){
	int n;
	cout << "Nhap so luong phong vip:";		cin >> n;		cin.ignore();
	vector<PhongVip> dspv(n);
	
	nhapDanhSach(dspv, n);
	
	cout << "\nThong tin phong co tien phong cao nhat la:" << endl;		dspv[maxTienPhong(dspv)].xuat();
	
	timKiemTheoTen(dspv);
	
	
	int m;
	cout << "\nNhap so luong phong tieu chuan :";		cin >> m;		cin.ignore();
	vector<PhongStandard> dsptc(m);
	
	nhapDanhSach(dsptc, m);
	
	cout << "\nThong tin phong co so ngay thue cao nhat la:" << endl;	dsptc[maxNgayThue(dsptc)].xuat();
	
	thongKeTheoLoaiGiuong(dsptc);
	
	ThongKeSoNgayThueLonHonNamNgay(dsptc);
	return 0;
}
