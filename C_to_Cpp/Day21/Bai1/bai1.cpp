#include<iostream>
#include<cmath>
using namespace std;


class PhanSo{
	private:
		int tuSo;
		int mauSo;
		int UCLN(int a, int b);
	public:
		PhanSo(int tuSo = 0, int mauSo = 1);
		void toiGian();
		friend ostream& operator<<(ostream &out, const PhanSo &ps);
		friend istream& operator>>(istream &in,  PhanSo &ps);
		PhanSo nghichDao() const;
		
		PhanSo operator+(const PhanSo &psKhac) const;		// const PhanSo : bao ve psKhac , const cuoi ham bao ve psBanDau
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
		bool operator>=(const PhanSo &psKhac) 	const;
		bool operator<=(const PhanSo &psKhac)	const;

		
};




PhanSo::PhanSo(int tuSo, int mauSo){
	this->tuSo = tuSo;
	this->mauSo = mauSo;
}

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

PhanSo PhanSo::nghichDao() const{
	if(tuSo == 0){
		cout << "\nKhong the nghich dao phan so co tu so = 0";
		return *this;
	}
	
	PhanSo ketQua;
	ketQua.tuSo = mauSo;
	ketQua.mauSo = tuSo;
	ketQua.toiGian();
	
	return ketQua;
}

istream& operator>>(istream& in, PhanSo &ps){
	cout << "\nNhap tu so:";
	in >> ps.tuSo;
	do{
		cout << "Nhap mau so:";
		in >> ps.mauSo;
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
	if(psKhac.tuSo == 0){
		cout << "\nKhong the chia cho phan so bang 0";
		return *this;
	}
	
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

bool PhanSo::operator>(const PhanSo &psKhac) const{
	return (tuSo * psKhac.mauSo > psKhac.tuSo * mauSo);
}

bool PhanSo::operator<(const PhanSo &psKhac) const{
	return (tuSo * psKhac.mauSo < psKhac.tuSo * mauSo);
}

bool PhanSo::operator==(const PhanSo &psKhac) const{
	return (tuSo * psKhac.mauSo == psKhac.tuSo * mauSo);
}

bool PhanSo::operator!=(const PhanSo &psKhac) const{
	return (tuSo *psKhac.mauSo != psKhac.tuSo * mauSo);
}

bool PhanSo::operator>=(const PhanSo &psKhac) const{
	return (*this > psKhac || *this == psKhac);
}

bool PhanSo::operator<=(const PhanSo &psKhac) const{
	return (*this < psKhac || *this == psKhac);
}


int main(){
	PhanSo ps1;
	PhanSo ps2;
	cout << "Nhap 2 phan so :";
	cin >> ps1 >> ps2;
	
	cout << "\n2 phan so vua nhap la:" << ps1 << " va " << ps2;
	
	PhanSo psTong = ps1 + ps2;
	cout << "\nTong 2 phan so la:" 		<< psTong;
	cout << "\nHieu 2 phan so la:" 		<< ps1 - ps2;
	cout << "\nTich 2 phan so la:" 		<< ps1 * ps2;
	cout << "\nThuong 2 phan so la:" 	<< ps1 / ps2;
	
	cout << "\nPhan so 1 sau khi tang them 1 don vi la :" << ++ps1;
	
	if(ps1 > ps2)			cout << "\nPhan so thu nhat lon hon phan so thu hai";
	else if(ps1 == ps2)		cout << "\n2 phan so bang nhau";
	else					cout << "\nPhan so thu nhat nho hon phan so thu hai";
	
	if(psTong > 1)		cout << "\nTong 2 phan so lon hon 1";
	else if(psTong == 1)	cout << "\nTong 2 phan so bang 1";
	else 					cout << "\nTong 2 phan so nho hon 1";
	
	
	cout << "\nNghich dao cua phan so tong la:" << psTong.nghichDao() ;
	
	return 0;
}
