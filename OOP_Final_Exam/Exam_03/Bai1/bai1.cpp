#include<iostream>
#include<iomanip>
#include<cmath>
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
		}
		
		friend istream& operator>>(istream &is, PhanSo &ps){
			cout << "\nNhap tu:";		is >> ps.tu;
			cout << "Nhap mau:";	is >> ps.mau;
			ps.toiGian();
			return is;
		}
		
		friend ostream& operator<<(ostream &os, const PhanSo &ps){
			if(ps.tu == 0)			os << 0;
			else if(ps.mau == 1)		os << ps.tu;
			else					os << ps.tu << "/" << ps.mau;
			
			return os;
		}
		
		bool operator>(const PhanSo &other) const{
			return (tu * other.mau > other.tu * mau);
		}
		
		PhanSo operator+(const PhanSo &other) const{
			PhanSo kq;
			
			kq.tu = tu * other.mau + other.tu * mau;
			kq.mau = mau * other.mau;
			kq.toiGian();
			
			return kq;
		}
		
		PhanSo operator-(const PhanSo &other) const{
			PhanSo kq;
			
			kq.tu = tu * other.mau - other.tu * mau;
			kq.mau = mau * other.mau;
			kq.toiGian();
			
			return kq;
		}
		
		PhanSo operator*(const PhanSo &other) const{
			PhanSo kq;
			
			kq.tu = tu * other.tu;
			kq.mau = mau * other.mau;
			kq.toiGian();
			
			return kq;
		}
};


int main(){
	PhanSo ps1(3,4), ps2;
	cout << "Nhap phan so thu 2:" << endl;	cin >> ps2;
	PhanSo ps3;
	cout << "\nNhap phan so thu 3:";	cin >> ps3;
	cout << "\nps1 = " << ps1 << endl << "ps2 = " << ps2 << endl << "ps3 = " << ps3 << endl;
	cout << "\nps1 + ps2 = " << ps1 + ps2 ;
	if(ps1 > ps2)	cout  << "\nps1 > ps2";
	else			cout  << "\nps1 < ps2";
	PhanSo psTong = ps1 - ps2 * ps3;
	cout << "\nps1 - ps2 * ps3 = " << psTong;
	
	return 0;
}
