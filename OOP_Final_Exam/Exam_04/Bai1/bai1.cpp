#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

class DaySo{
	private:
		int n = 0;
		int *a = nullptr;
	public:
		DaySo(){}
		DaySo(int n, int *a){
			this->n = n;
			this->a = new int[n];
			for(int i=0; i<n; i++){
				this->a[i] = a[i];
			}
		}
		
		~DaySo(){ delete[] a; }
		
		friend istream& operator>>(istream &is, DaySo &ds){
			cout << "Nhap so phan tu:";		is >> ds.n;
			ds.a = new int[ds.n];
			for(int i=0; i<ds.n; i++){
				cout << "Nhap phan tu thu " << i+1 << ":";
				is >> ds.a[i];
			}
			return is;
		}
		
		friend ostream& operator<<(ostream &os, DaySo &ds){
			for(int i=0; i<ds.n; i++){
				os << ds.a[i] << " ";
			}
			return os;
		}
		
		int maxChan(){
			int max;
			bool coChan = false;
			for(int i=0; i<n; i++){
				if(a[i] % 2 == 0){
					coChan = true;
					max = a[i];
				}
			}
			
			if(coChan == false){
				return -1;
			}
			
			
			for(int i=0; i<n; i++){
				if(a[i] % 2 == 0){
					if(a[i] > max)	 max = a[i];
				}
			}
			return max;
		}
		
		tichKhoang(int a, int b){
			int tich = 1;
			for(int i=0; i<n; i++){
				if(this->a[i] >= a && this->a[i] <= b)	tich *= this->a[i];
			}
			return tich;
		}
};




int main(){
	DaySo ds1;
	cin >> ds1; 
	cout << "\nDay so vua nhap la:" << ds1;
	
	if(ds1.maxChan() == -1)		cout << "\nDay khong co so chan";
	else					cout << "\nMax chan la = " << ds1.maxChan();

	int a,b;
	cout << "\nNhap a , b:";	cin >> a >> b;
	cout << "\nTich cac phan tu trong khoang [a, b] = " << ds1.tichKhoang(a, b);
	
	return 0;
}
