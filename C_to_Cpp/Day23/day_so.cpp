#include <iostream>

using namespace std;

class DaySo{
	private:
		int soPT = 0;
		int *mang = nullptr;
	public:
		DaySo(){}
		DaySo(int soPT, int *mang);
		
		int tongDuong();
		int maxChan();
		
		friend istream& operator>>(istream &is, DaySo &ds);
		friend ostream& operator<<(ostream &os, DaySo &ds);
		
		int& operator[](int i){ return mang[i]; }
};


DaySo::DaySo(int soPT, int *mang){
	this->soPT = soPT;
	this->mang = new int[soPT];
	for(int i=0; i<soPT; i++){
		this->mang[i] = mang[i];
	}
}

int DaySo::tongDuong(){
	int kq = 0;
	for(int i=0; i<soPT; i++){
		if(mang[i] > 0)		kq += mang[i];
	}
	return kq;
}

int DaySo::maxChan(){
	int max;
	bool coSoChan = false;
	
	for(int i=1; i<soPT; i++){
		if(mang[i] % 2 == 0){
			if(coSoChan == false){
				coSoChan = true;
				max = mang[i];
			}
			else if(mang[i] > max){
				max = mang[i];
			}
		}
	}
	
	if(coSoChan == false){
		cout << "\nKhong co phan tu chan trong day!";
		return -1;	
	}
	return max;
}

istream& operator>>(istream &is, DaySo &ds){
	cout << "Nhap so phan tu:";		is >> ds.soPT;
	ds.mang = new int[ds.soPT];
	for(int i=0; i<ds.soPT; i++){
		cout << "Nhap phan tu thu " << i+1 << ":";
		is >> ds.mang[i];
	}
	return is;
}

ostream& operator<<(ostream &os, DaySo &ds){
	for(int i=0; i<ds.soPT; i++){
		os << ds.mang[i] << "   " ;
	}
	return os;
}

int main(){
	DaySo ds1;
	cin >> ds1;
	cout << "Day vua nhap la: " << ds1 << endl;
	
	cout << "Tong duong la: " << ds1.tongDuong() << endl;
	cout << "Max chan cua day la:" << ds1.maxChan() << endl;
	
	int index;	cout << "Nhap index: ";		cin >> index;
	cout << "ds1[index] = " << ds1[index] << endl;
	
	return 0;
}
