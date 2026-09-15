#include<iostream>
#include<iomanip>
#include<cmath>
#include<vector>
using namespace std;

class DaThuc{
	private:
		int bac;
		float *heSo;
	public:
		DaThuc() : bac(0), heSo(nullptr){};
		DaThuc(int bac);
		~DaThuc(){delete[] heSo;};
		
		friend istream& operator>>(istream &in, DaThuc &dt);
		friend ostream& operator<<(ostream &out, const DaThuc &dt);
		
		DaThuc operator+(const DaThuc &dtk) const;
		DaThuc operator*(const DaThuc &dtk)	const;
		float& operator[](int i);
		const float& operator[](int i) const;
		
		DaThuc daoHam() const;
};


void nhapDanhSach(vector<DaThuc> &danhSach, int soLuong);
void xuatDanhSach(vector<DaThuc> &danhSach);




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
	int bacTich = bac + dtk.bac;
	DaThuc kq(bacTich);
	
	for(int i=0 ; i<=bac; i++){
		for(int j=0; j<=dtk.bac; j++){
			kq.heSo[i+j] += heSo[i] * dtk.heSo[j];	
		}
	}
	
	return kq;
}


float& DaThuc::operator[](int i){
	return heSo[i];
}

const float& DaThuc::operator[](int i) const{
	return heSo[i];
}

DaThuc DaThuc::daoHam() const{
	if(bac==0)	return DaThuc(0);
	
	DaThuc kq(bac-1);
	
	for(int i=0; i<=kq.bac; i++){
		kq[i] = (i+1) * (*this)[i+1];
	}
	
	return kq;
}











int main(){
	int soLuong;
	cout << "Nhap so luong da thuc:";	cin >> soLuong;
	
	vector<DaThuc> danhSach(soLuong);
	
	nhapDanhSach(danhSach, soLuong);
	
	cout << "\nDanh sach da thuc vua nhap la:" << endl;
	xuatDanhSach(danhSach);
	
	
	
	return 0;
}

void nhapDanhSach(vector<DaThuc> &danhSach, int soLuong){
	for(int i=0; i<soLuong; i++){
		cout << "Nhap da thuc thu " << i+1 << ":";
		cin >> danhSach[i];
	}
}

void xuatDanhSach(vector<DaThuc> &danhSach){
	for(int i=0; i<danhSach.size(); i++){
		cout << "\nDa thuc thu " << i+1 << ":";
		cout << danhSach[i];
	}
}
