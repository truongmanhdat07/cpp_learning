#include<iostream>

using namespace std;

class DaySo{
	private:
		int n;
		int *a;
	public:
		DaySo(int n = 0, int *a = nullptr){
			this->n = n;
			this->a = new int[n];
			for(int i=0; i<n; i++){
				if(a == nullptr)	this->a[i] = 0;
				else				this->a[i] = a[i];
			}
		}
		
		~DaySo(){	delete[] a;}
		
		friend istream& operator>>(istream &is , DaySo &ds){
			cout << "Nhap so luong phan tu:";		is >> ds.n;
			ds.a = new int[ds.n];
			
			for(int i=0; i<ds.n; i++){
				cout << "Nhap phan tu thu " << i+1 << ":";
				is >> ds.a[i];
			}
			return is;
		}
		
		friend ostream& operator<<(ostream &os, DaySo &ds){
			for(int i=0; i<ds.n; i++){
				os << ds.a[i] << "   ";
			}
			return os;
		}
		
		int maxSnt(){
			int max = 1;
			bool coSnt = false;
			for(int i=0; i<n; i++){
				if(laSnt(a[i]) && a[i] > max){
					max = a[i];
					coSnt = true;
				}
			}
			
			if(coSnt)	return max;
			else		return -1;
		}
		
		bool laSnt(int k){
			if(k < 2)	return false;
			for(int i=2; i*i <= k ; i++){
				if(k % i == 0)	return false;
			}
			return true;
		}
		
		void TBCKhoang(int a, int b){
			float tong = 0;
			int dem = 0;
			for(int i=0; i<n; i++){
				if(this->a[i] >= a && this->a[i] <= b){
					tong += this->a[i];
					dem++;
				}
			}
			if(dem == 0){
				cout << "\nKhong co phan tu nao thuoc khoang [a, b]";
				return ;
			}
			cout << "\nTBC cac phan tu trong khoang [a, b] = " << tong / dem;
		}
		
		bool laDayDanDau(){
			for(int i=0; i<n-1; i++){
				if(a[i] * a[i+1] >= 0)	return false;
			}
			return true;
		}
		
		void sapXepGiamDan(){
			for(int i=0; i<n-1; i++){
				for(int j=i+1; j<n; j++){
					if(a[i] < a[j]){
						swap(a[i], a[j]);
					}
				}
			}
		}
};


int main(){
	DaySo ds1;
	cin >> ds1;
	cout << "\nDay so vua nhap la:" <<	ds1;
	
	if(ds1.maxSnt() == -1)	cout << "\nKhong co so nguyen to nao trong day";
	else	cout << "\nMax so nguyen so cua day la:" << ds1.maxSnt();
	
	int a, b;
	cout << "\nNhap [a,b] :";	cin >> a >> b;
	
	ds1.TBCKhoang(a,b);
	
	if(ds1.laDayDanDau())	cout << "\nLa day dan dau!";
	else					cout << "\nKhong phai day dan dau!";
	
	ds1.sapXepGiamDan();
	cout << "\nDay so sau khi sap xep giam dan la:" << ds1;
	
	return 0;
}
