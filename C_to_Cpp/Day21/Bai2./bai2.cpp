#include<iostream>
#include<iomanip>
#include<cmath>

using namespace std;

class DaThuc{
	private:
		int bac;
		float *heSo;
	public:
		DaThuc() : bac(0), heSo(nullptr){};
		DaThuc(int bac);
		
		friend istream& operator>>(istream &in, DaThuc &dt);
		friend ostream& operator<<(ostream &out, const DaThuc &dt);
		
		DaThuc operator+(const DaThuc &dtk) const;
		DaThuc operator*(const DaThuc &dtk)	const;
};



DaThuc::DaThuc(int bac){
	this->bac = bac;
	this->heSo = new float[bac+1];
	
	for(int i=0; i<=bac; i++){
		heSo[i] = 0;
	}
}

istream& operator>>(istream &in, DaThuc &dt){
	cout << "\nNhap bac:";		in >> dt.bac;
	dt.heSo = new float[dt.bac+1];
	
	for(int i=0; i<=dt.bac; i++){
		cout << "Nhap he so bac " << i << ":";
		in >> dt.heSo[i];
	}
	
	return in;
}

ostream& operator<<(ostream &out, const DaThuc &dt){
	int soDaIn = 0;
	
	for(int i=0; i<=dt.bac; i++){
		if(dt.heSo[i] == 0)	continue;
		
		if(soDaIn == 0){
			if(dt.heSo[i] < 0)	out << "-";
		}
		else{
			if(dt.heSo[i] < 0)	out << " - ";
			else				out << " + ";
		}
		
		if(dt.heSo[i] != 1 || i == 0)	out << fixed << setprecision(2) << abs(dt.heSo[i]);
		if(i > 1)						out << "x^" << i;
		else if(i == 1)					out << "x";
		
		soDaIn++;
	}
	if(soDaIn == 0)		out << 0;
	
	return out;
}

DaThuc DaThuc::operator+(const DaThuc &dtk) const{
	int bacTong = (this->bac > dtk.bac) ? this->bac : dtk.bac;
	
	DaThuc kq(bacTong);
	
	for(int i=0; i<=kq.bac; i++){
		float hs1 = (i <= this->bac) ? this->heSo[i] : 0;
		float hs2 = (i <= dtk.bac)   ? dtk.heSo[i]   : 0;
		
		kq.heSo[i] = hs1 + hs2;
	}
	
	while(kq.heSo[kq.bac] == 0)	kq.bac--;
	
	return kq;
}

DaThuc DaThuc::operator*(const DaThuc &dtk) const{
	int bacTich = bac * dtk.bac;
	DaThuc kq(bacTich);
	
	for(int i=0 ; i<=bac; i++){
		for(int j=0; j<=dtk.bac; j++){
			kq.heSo[i+j] += heSo[i] * dtk.heSo[j];	
		}
	}
	
	return kq;
}

















int main(){
	DaThuc dt1, dt2;
	cin >> dt1 >> dt2;
	
	cout << dt1 + dt2 << endl;
	cout << dt1 * dt2 << endl;
	
}
