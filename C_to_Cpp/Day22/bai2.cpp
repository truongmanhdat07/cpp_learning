#include<iostream>

using namespace std;

class Day{
	private:
		int soPhanTu;
		int *heSo;
	public:
		Day(int soPhanTu = 0, int *heSo = nullptr){}
		Day(int soPhanTu);
		
		friend istream& operator>>(istream &is, Day &day);
		friend ostream& operator<<(ostream &os, const Day &day);
		
		int maxDay() const;
		int tongDay() const;
		
		float trungBinhCongLonHonX(float x) const;
};


Day::Day(int soPhanTu){
	this->soPhanTu = soPhanTu;
	this->heSo = new int[soPhanTu];
	
	for(int i=0; i<soPhanTu; i++){
		heSo[i] = 0;
	}
}

istream& operator>>(istream &is, Day &day){
	cout << "Nhap so phan tu:";		is >> day.soPhanTu;
	day.heSo = new int[day.soPhanTu];
	
	for(int i=0; i<day.soPhanTu; i++){
		cout << "Nhap he so thu " << i+1 << ":";
		is >> day.heSo[i];
	}
	return is;
}

ostream& operator<<(ostream &os, const Day &day){
	for(int i=0; i<day.soPhanTu; i++){
		os<< day.heSo[i] << " " ;
	}
	return os;
}

int Day::maxDay() const{
	int max = heSo[0];
	for(int i=1; i<soPhanTu; i++){
		if(heSo[i] > max)	max = heSo[i];
	}
	return max;
}

int Day::tongDay() const{
	int tong = 0;
	for(int i=0; i<soPhanTu; i++){
		tong += heSo[i];
	}
	return tong;
}

float Day::trungBinhCongLonHonX(float x) const{
	float tong = 0;
	int dem = 0;
	for(int i=0; i<soPhanTu; i++){
		if(heSo[i] > x){
			tong += heSo[i];
			dem++;
		}
	}
	if(dem == 0)	return 0;
	else			return tong/dem;
}


int main(){
	Day d1;
	cin >> d1;
	cout << "\nDay vua nhap la:" << d1;
	
	cout << "\nMax cua day la:" << d1.maxDay();
	cout << "\nTong cua day la:" << d1.tongDay();
	
	float x;
	cout << "\nNhap x:";	cin >> x;
	cout << "\nTrung binh cong cac so lon hon x cua day la:" << d1.trungBinhCongLonHonX(x);
	
	return 0;
}
