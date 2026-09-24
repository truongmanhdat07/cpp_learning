#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

class Diem{
	private:
		float x, y;
	public:
		Diem(float x = 0, float y = 0) : x(x) , y(y){}
		
		void nhap();
		void xuat();
		
		friend istream& operator>>(istream &is, Diem &d);
		friend ostream& operator<<(ostream &os, Diem &d);
		float kc();
};


void nhapDanhSach(vector<Diem> &danhSach, int soLuongDiem);
void xuatDanhSach(vector<Diem> &danhSach);
float tongKC(vector<Diem> &danhSach);
int minKC(vector<Diem> &danhSach);


void Diem::nhap(){
	cout << "x, y = ";
	cin >> x >> y;
}

void Diem::xuat(){
	cout << "(" << x << ", " << y << ")" ;
}

istream& operator>>(istream &is, Diem &d){
	cout << "x, y = ";
	is >> d.x >> d.y;
	return is;
}

ostream& operator<<(ostream &os, Diem &d){
	os << "(" << d.x << ", " << d.y << ")" ;	
	return os;
}

float Diem::kc(){
	return sqrt( x * x + y * y);
}




int main(){
	int soLuongDiem;
	cout << "Nhap so luong diem:";	cin >> soLuongDiem;
	vector<Diem> danhSach(soLuongDiem);
	
	nhapDanhSach(danhSach, soLuongDiem);
	xuatDanhSach(danhSach);
	
	cout << "\nTong kc cua tat ca cac diem den goc toa do la:" << tongKC(danhSach);
	
	int viTri = minKC(danhSach);
	cout << "\nDiem gan goc toa do nhat la:" << danhSach[viTri];
	
	return 0;
}

void nhapDanhSach(vector<Diem> &danhSach, int soLuongDiem){
	for(int i=0; i<soLuongDiem; i++){
		cout << "Nhap diem thu " << i+1 << ":";
		cin >> danhSach[i];
	}
}

void xuatDanhSach(vector<Diem> &danhSach){
	for(int i=0; i<danhSach.size(); i++){
		cout << "\nDiem thu " << i+1 << ":" << danhSach[i];
	}
}

float tongKC(vector<Diem> &danhSach){
	float tong = 0;
	for(int i=0; i<danhSach.size(); i++){
		tong += danhSach[i].kc();
	}
	return tong;
}

int minKC(vector<Diem> &danhSach){
	int viTri = 0;
	float min = danhSach[0].kc();
	
	for(int i=1; i<danhSach.size(); i++){
		if(danhSach[i].kc() < min){
			min = danhSach[i].kc();
			viTri = i;
		}
	}
	return viTri;
}
