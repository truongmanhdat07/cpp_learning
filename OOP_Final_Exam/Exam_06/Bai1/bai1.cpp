#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

class DaThuc{
	private:
		int bac;
		float *heSo;
	public:
		DaThuc(int bac = 0, float *heSo = nullptr){
			this->bac = bac;
			this->heSo = new float[bac+1];
			for(int i=0; i<= bac; i++){
				if(heSo != nullptr){
					this->heSo[i] = heSo[i];
				}
				else{
					this->heSo[i] = 0.0f;
				}
			}
		}
		DaThuc(const DaThuc &other){
			this->bac = other.bac;
			this->heSo = new float[bac+1];
			for(int i=0; i<=bac; i++){
				this->heSo[i] = other.heSo[i];
			}
		}
		
		 ~DaThuc(){ delete[] heSo;}
		
		
		void nhap(){
			cout << "\nNhap bac cua da thuc:";	cin >> bac;
			heSo = new float[bac+1];
			
			for(int i=0; i<=bac; i++){
				cout << "Nhap he so bac " << i << ":";
				cin >> heSo[i];
			}
		}
		
		void xuat(){
			int soDaIn = 0;
			
			for(int i=0; i<=bac; i++){
				if(heSo[i] == 0)	continue;
				
				if(soDaIn == 0){
					if(heSo[i] < 0)		cout << "-";
				}
				else{
					if(heSo[i] < 0) 	cout << " - ";
					else				cout << " + ";
				}
				
				float value = abs(heSo[i]);
				
				if(value != 1 || i == 0)		cout << fixed << setprecision(2) << value;
				
				if(i > 1)			cout << "x^" << i ;
				else if(i == 1)		cout << "x";
				
				soDaIn++;
			}
			
			if(soDaIn == 0)		cout << "0";
		}
		
		DaThuc daoHam(){
			if(bac == 0)	return DaThuc(0);
			
			int bacDaoHam = bac - 1;
			DaThuc daThucDaoHam(bacDaoHam);
			
			for(int i=0; i<=bacDaoHam; i++){
				daThucDaoHam.heSo[i] = heSo[i+1] * (i+1);
			}
			
			return daThucDaoHam;
		}
		
		float tinhGiaTri(float x){
			float ketQua = 0;
			
			for(int i=0; i<=bac; i++){
				ketQua += heSo[i] * pow(x, i);
			}
			return ketQua;
		}
};



int main(){
	DaThuc dt1;
	dt1.nhap();
	
	cout << "\nDa thuc vua nhap:";		dt1.xuat();
	
	DaThuc dt2 = dt1.daoHam();
	cout << "\nDa thuc sau khi dao ham la:";	dt2.xuat();
	
	float x;
	cout << "\nNhap x:";	cin >> x;
	
	cout << "\nGia tri dao ham tai x la:" << dt2.tinhGiaTri(x);
	
	return 0;
}
