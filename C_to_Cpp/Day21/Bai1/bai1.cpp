#include<iostream>
#include<cmath>
using namespace std;


class PhanSo{
	private:
		int tuSo;
		int mauSo;
		int UCLN(int a, int b);
	public:
		void toiGian();
		friend ostream& operator<<(ostream &out, const PhanSo &ps);
		friend istream& operator>>(istream &in,  PhanSo &ps);
		
		PhanSo operator+(const PhanSo &psKhac) const;
		PhanSo operator-(const PhanSo &psKhac) const;
		PhanSo operator*(const PhanSo &psKhac) const;
		PhanSo operator/(const PhanSo &psKhac) const;
		PhanSo& operator++();
		PhanSo operator++(int);
		PhanSo& operator--();
		PhanSo operator--(int);
		bool operator>(const PhanSo &psKhac)	const;
		bool operator<(const PhanSo &psKhac) 	const;
		bool operator==(const PhanSo &psKhac) 	const;
		bool operator!=(const PhanSo &psKhac)	const;

		
};






int PhanSo::UCLN(int a, int b){			// lay a % b lien tuc , b = 0 thi a la UCLN
	a=abs(a);
	b=abs(b);
	while(b !=0 ){
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}

void PhanSo::toiGian(){
	int ucln = UCLN(tuSo,mauSo);
	tuSo /= ucln;
	mauSo /= ucln;
	
	if(mauSo < 0){
		tuSo = -tuSo;
		mauSo = -mauSo;
	}
}

istream& operator>>(istream& in, PhanSo &ps){
	cout << "\nNhap tu so:";
	in >> ps.tuSo;
	do{
		cout << "Nhap mau so:";
		cin >> ps.mauSo;
	}while(ps.mauSo<=0);
	ps.toiGian(); // == this -> toigian();
	
	return in;
}

ostream& operator<<(ostream& out, const PhanSo &ps){
	if(ps.mauSo == 1)		cout << ps.tuSo;
	else if(ps.tuSo == 0)	cout << 0;
	else 					cout << ps.tuSo << "/" << ps.mauSo;
	
	return out;
}

PhanSo PhanSo::operator+(const PhanSo &psKhac) const{
	PhanSo ketQua;
	ketQua.tuSo = tuSo * psKhac.mauSo + psKhac.tuSo * mauSo; 
	ketQua.mauSo = mauSo * psKhac.mauSo;
	ketQua.toiGian();
	
	return ketQua;
}

PhanSo PhanSo::operator-(const PhanSo &psKhac) const{
	PhanSo ketQua;
	ketQua.tuSo = tuSo * psKhac.mauSo - psKhac.tuSo * mauSo;
	ketQua.mauSo = mauSo * psKhac.mauSo;
	ketQua.toiGian();
	
	return ketQua;
}

PhanSo PhanSo::operator*(const PhanSo &psKhac) const{
	PhanSo ketQua;
	ketQua.tuSo = tuSo * psKhac.tuSo;
	ketQua.mauSo = mauSo * psKhac.mauSo;
	ketQua.toiGian();
	
	return ketQua;
}

PhanSo PhanSo::operator/(const PhanSo &psKhac) const{
	PhanSo ketQua;
	ketQua.tuSo = tuSo * psKhac.mauSo;
	ketQua.mauSo = mauSo * psKhac.tuSo;
	ketQua.toiGian();
	
	return ketQua;
}

PhanSo& PhanSo::operator++(){
	tuSo += mauSo;
	return *this;
}

PhanSo PhanSo::operator++(int){
	PhanSo tam = *this;
	++(*this);
	
	return tam;
}

PhanSo& PhanSo::operator--(){
	tuSo -= mauSo;
	return *this;
}

PhanSo PhanSo::operator--(int){
	PhanSo tam = *this;
	--(*this);
	
	return tam;
}

int main(){
	PhanSo ps1;
	PhanSo ps2;
	cout << "Nhap 2 phan so :";
	cin >> ps1 >> ps2;
	
	cout << "\n2 phan so vua nhap la:" << ps1 << " va " << ps2;
	
	cout << "\nTong 2 phan so la:" 		<< ps1 + ps2;
	cout << "\nHieu 2 phan so la:" 		<< ps1 - ps2;
	cout << "\nTich 2 phan so la:" 		<< ps1 * ps2;
	cout << "\nThuong 2 phan so la:" 	<< ps1/ps2;
	
	cout << "\nPhan so 1 sau khi tang them 1 don vi la :" << ++ps1;
	
	return 0;
}
