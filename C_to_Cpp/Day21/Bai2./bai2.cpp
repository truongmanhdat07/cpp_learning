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
}

ostream& operator<<(ostream &out, const DaThuc &dt){
	int soDaIn = 0;
	
	for(int i=0; i<=dt.bac; i++){
		if(dt.heSo[i] == 0)	continue;
		
		if(soDaIn == 0){
			if(dt.heSo[i] < 0)	cout << "-";
		}
		else{
			if(dt.heSo[i] < 0)	cout << " - ";
			else				cout << " + ";
		}
		
		if(dt.heSo[i] != 1 || i == 0)	cout << fixed << setprecision(2) << abs(dt.heSo[i]);
		if(i > 1)						cout << "x^" << i;
		else if(i == 1)					cout << "x";
		
		soDaIn++;
	}
	if(soDaIn == 0)		cout << 0;
}





















int main(){
	DaThuc dt;
	cin >> dt;
	cout << "\nDa thuc vua nhap:" << dt;
}
