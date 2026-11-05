#include<iostream>
#include<cmath>

using namespace std;

class DaThuc{
	private:
		int n ;
		float *a;
	public:
		DaThuc(int n = 0, float *a = nullptr){
			this->n = n;
			this->a = new float[n+1];
			
			if(a == nullptr){
				for(int i=0; i<=n; i++){
					this->a[i] = 0;
				}
			}
			else{
				for(int i=0; i<=n; i++){
					this->a[i] = a[i];
				}
			}
		}
		
		DaThuc(const DaThuc &other){
			this->n = other.n;
			this->a = new float[n+1];
			for(int i=0; i<=n; i++){
				this->a[i] = other.a[i];
			}
		}
		
		~DaThuc(){	delete[] a;}
		
		friend istream& operator>>(istream &is, DaThuc &dt){
			cout << "Nhap bac cua da thuc:";		is >> dt.n;
			dt.a = new float[dt.n + 1];
			
			for(int i=0; i<= dt.n; i++){
				cout << "Nhap he so bac " << i << ":";
				is >> dt.a[i];
			}
			return is;
		}
		
		friend ostream& operator<<(ostream &os, DaThuc &dt){
			int soDaIn = 0;
			
			for(int i=0; i<=dt.n; i++){
				if(dt.a[i] == 0)	continue;
				
				if(soDaIn == 0){
					if(dt.a[i] < 0)		os << "-";
				}
				else{
					if(dt.a[i] < 0)		os << " - ";
					else				os << " + ";
				}
				
				float value = abs(dt.a[i]);
				
				if(value != 1 || i == 0)		os << value;
				
				if(i > 1)						os << "x^" << i;
				else if(i == 1)					os << "x";
				
				soDaIn++;
			}
			
			if(soDaIn == 0)		os << "0";
			
			return os;
		}
		
		DaThuc operator+(const DaThuc &other) const{
			int bacMax = (n > other.n) ? n : other.n;
			DaThuc dtTong(bacMax);
			
			for(int i=0; i<=bacMax; i++){
				float hs1 = (i <= this->n) 		? this->a[i] : 0;
				float hs2 = (i <= other.n)  	? other.a[i] : 0;
				dtTong.a[i] = hs1 + hs2;
			}
			
			return dtTong;
		}
		
		float tinhGiaTri(float x){
			float kq = 0;
			for(int i=0; i<=n; i++){
				kq += a[i] * pow(x, i);
			}
			return kq;
		}
		
		DaThuc daoHam(){
			if(n == 0)		return DaThuc(0);
			
			int bacdh = n-1;
			DaThuc dtdh(bacdh);
			
			for(int i=0; i<=bacdh; i++){
				dtdh.a[i] = a[i+1] * (i+1);
			}
			
			return dtdh;
		}
		
		float maxHeSo(){
			float max = a[0];
			
			for(int i=0; i<=n; i++){
				if(a[i]  > max)		max = a[i];
			}
			
			return max;
		}
};




int main(){
	DaThuc dt1, dt2;
	cin >> dt1 >> dt2;
	cout << "\nDt1:" << dt1 << endl << "Dt2:" << dt2 << endl;
	
	float x;
	cout << "\nNhap x:";		cin >> x;
	cout << "\nDt1(x) = " << dt1.tinhGiaTri(x);
	
	DaThuc dt1dh = dt1.daoHam();
	cout << "\nDt1 sau khi dao ham la:" << dt1dh;
	
	DaThuc dtTong = dt1 + dt2;
	cout << "\nDt1 + Dt2 = " << dtTong;
	
	cout << "\nMax he so cua Dt1 la:" << dt1.maxHeSo();
	
	return 0;
}
