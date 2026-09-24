#include<iostream>
#include<cmath>
using namespace std;

class DaThuc{
	private:
		int bac;
		float *heSo;
	public:
		DaThuc(int bac = 0);
		~DaThuc(){ delete[] heSo; }
		
		friend istream& operator>>(istream &is, DaThuc &dt);
		friend ostream& operator<<(ostream &os, const DaThuc &dt);
	
		DaThuc daoHam() const;
		float tinhGiaTri(float x) const;
		
		float heSoMax() const;
};

DaThuc::DaThuc(int bac){
	this->bac = bac;
	this->heSo = new float[bac+1];
	for(int i=0; i<=bac; i++){
		heSo[i] = 0;
	}
}

istream& operator>>(istream &is, DaThuc &dt){
	cout << "Nhap bac cua da thuc:";	is >> dt.bac;
	dt.heSo = new float[dt.bac+1];
	for(int i=0; i<=dt.bac; i++){
		cout << "Nhap he so bac " << i << ":";
		is >> dt.heSo[i];
	}
	return is;
}

ostream& operator<<(ostream& os, const DaThuc &dt){
	int soDaIn = 0;
	
	for(int i=0; i<=dt.bac; i++){
		if(dt.heSo[i] == 0)	continue;
		if(soDaIn == 0){
			if(dt.heSo[i] < 0)		os << "-";
		}
		else{
			if(dt.heSo[i] < 0) 		os << " - ";
			else					os << " + ";
		}
		
		float value = abs(dt.heSo[i]);
		
		if(value != 1 || i == 0)	os << value;
		if(i > 1)					os << "x^" << i;
		else if(i == 1)				os << "x";
		
		soDaIn++;
	}
	if(soDaIn == 0)		cout << 0;
	
	return os;
}

DaThuc DaThuc::daoHam() const{
	if(bac == 0)		return DaThuc(0);
	int bacDaoHam = bac - 1;
	DaThuc dh(bacDaoHam);
	
	for(int i=0; i<=bacDaoHam; i++){
		dh.heSo[i] = (i+1) * heSo[i+1];
	}
	return dh;
} 

float DaThuc::tinhGiaTri(float x) const{
	float kq = 0;
	for(int i=0; i<=bac; i++){
		kq += heSo[i] * pow(x, i);
	}
	
	return kq;
}

float DaThuc::heSoMax() const{
	float max = abs(heSo[0]);
	for(int i=0; i<=bac; i++){
		if(abs(heSo[i]) > max)	max = abs(heSo[i]);
	}
	return max;
}

int main(){
	DaThuc dt1;
	cin >> dt1;
	cout << "\nDa thuc vua nhap la:" << dt1;
	
	DaThuc dh1 = dt1.daoHam();
	cout << "\nDa thuc sau khi dao ham la:" << dh1;
	
	float x;
	cout << "\nNhap x:";	 cin >> x;
	cout << "\nGia tri da thuc dao ham tai x la:" << dh1.tinhGiaTri(x);
	
	cout << "\nHe so am lon nhat la:" << dt1.heSoMax();
	
	return 0;
}
