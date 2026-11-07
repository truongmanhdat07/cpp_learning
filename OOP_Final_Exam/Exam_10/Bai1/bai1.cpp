#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;

class PhanSo{
	private:
		int tu;
		int mau;
		int UCLN(int a, int b){
			a = abs(a);
			b = abs(b);
			while(b != 0){
				int r = a % b;
				a = b;
				b = r;
			}
			return a;
		}
	public:
		PhanSo(int tu = 0, int mau = 1) : tu(tu), mau(mau){}
		
		void toiGian(){
			int ucln = UCLN(tu, mau);
			
			tu /= ucln;
			mau /= ucln;
			
			if(mau < 0){
				tu = -tu;
				mau = -mau;
			}
		}
		
		
		friend istream& operator>>(istream &is, PhanSo &ps){
			cout << "Nhap tu:";		is >> ps.tu;
			cout << "Nhap mau:";	is >> ps.mau;
			ps.toiGian();
			return is;
		}
		
		friend ostream& operator<<(ostream &os, const PhanSo &ps){
			if(ps.tu == 0)				os << 0;
			else if(ps.mau == 1)		os << ps.tu;
			else						os << ps.tu << "/" << ps.mau;
			return os;
		}
		
		PhanSo operator+(const PhanSo &other) const{
			return PhanSo( tu* other.mau + mau * other.tu, mau * other.mau);
		}
		
		PhanSo operator*(const PhanSo &other) const{
			return PhanSo(tu * other.tu, mau * other.mau);
		}
		
		bool operator>(const PhanSo &other) const{
			return (tu * other.mau > mau * other.tu);
		}
		
		bool operator<(const PhanSo &other) const{
			return (tu * other.mau < mau * other.tu);
		}
};

void nhapDanhSach(vector<PhanSo> &dsps, int sl){
	for(int i=0; i<sl; i++){
		cout << "Nhap phan so thu " << i+1 << ":" << endl;
		cin >> dsps[i];
	}
}

void xuatDanhSach(vector<PhanSo> &dsps){
	for(int i=0; i<dsps.size(); i++){
		cout << dsps[i] << " , ";
	}
}

PhanSo tongPhanSo(vector<PhanSo> &dsps){
	PhanSo tong;
	for(int i=0; i<dsps.size(); i++){
		tong = tong + dsps[i];
	}
	return tong;
}

int maxPhanSo(vector<PhanSo> &dsps){
	PhanSo max = dsps[0];
	int viTri = 0;
	for(int i=1; i<dsps.size(); i++){
		if(dsps[i] > max){
			max = dsps[i];
			viTri = i;
		}
	}
	return viTri;
}


int main(){
	PhanSo p, q;
	cout << "Nhap p:" << endl;		cin >> p;
	cout << "Nhap q:" << endl;		cin >> q;
	
	cout << "\np : " << p << " , q:" <<  q << endl;
	
	cout << "\np + q = " << p + q << endl;
	cout << "p * q = " << p * q << endl;
	
	int sl;
	cout << "\nNhap so luong phan so:";		cin >> sl;
	vector<PhanSo> dsps(sl);
	
	nhapDanhSach(dsps, sl);
	
	cout << "\nTong cac phan so vua nhap la:" << tongPhanSo(dsps);
	
	cout << "\nMax phan so trong danh sach la:" << dsps[maxPhanSo(dsps)];
	
	sort(dsps.begin(), dsps.end());
	
	cout << "\nDanh sach phan so sau khi sap xep theo tang dan la:" << endl;
	xuatDanhSach(dsps);
	
	return 0;
}
