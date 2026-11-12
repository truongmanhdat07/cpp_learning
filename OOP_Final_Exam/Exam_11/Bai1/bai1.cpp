#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

class SoPhuc{
	private:
		float thuc, ao;
	public:
		SoPhuc(float thuc = 0.0f, float ao = 0.0f ) : thuc(thuc), ao(ao){}
		
		float getThuc(){
			return thuc;
		}
		
		friend istream &operator>>(istream &is, SoPhuc &sp){
			cout << "Nhap phan thuc:";		is >> sp.thuc;
			cout << "Nhap phan ao:";		is >> sp.ao;
			return is;
		}
		
		friend ostream& operator<<(ostream &os, const SoPhuc &sp){
			if(sp.thuc == 0)	os << sp.ao << "i";
			else				os << sp.thuc << " + " << sp.ao << "i";
			return os;
		}
		
		SoPhuc operator+(const SoPhuc &other) const {
			return SoPhuc(this->thuc + other.thuc, this->ao + other.ao);
		}
		
		SoPhuc operator*(const SoPhuc &other) const {
			return SoPhuc(
				this->thuc * other.thuc - this->ao * other.ao, 
				this->thuc * other.ao + this->ao * other.thuc
			);
		}
		
		float module(){
			return sqrt(thuc*thuc + ao*ao);
		}
		
		bool operator>( SoPhuc &other) {
			return this->module() > other.module();
		}
};


void nhapDanhSach(vector<SoPhuc> &ds, int n){
	for(int i=0; i<n; i++){
		cout << "Nhap so phuc thu " << i+1 << ":" << endl;
		cin >> ds[i];
	}
}

int maxModule(vector<SoPhuc> &ds){
	float max = ds[0].module();
	int viTri = 0;
	for(int i=0; i<ds.size(); i++){
		if(ds[i].module() > max){
			max = ds[i].module();
			viTri = i;	
		}
	}
	
	return viTri;
}

int demThuanAo(vector<SoPhuc> &ds){
	int dem = 0;
	for(int i=0; i<ds.size(); i++){
		if(ds[i].getThuc() == 0)	dem++;
	}
	return dem;
}


int main(){
	SoPhuc z1, z2;
	cin >> z1 >> z2;
	
	cout << "\nz1 + z2 = " << z1 + z2;
	cout << "\nz1 * z2 = " << z1 * z2;
	
	cout << "\n|z1| = " << z1.module();
	
	int n;
	cout << "\nNhap so luong so phuc:";		cin >> n;
	vector<SoPhuc> ds(n);
	
	nhapDanhSach(ds, n);
	
	cout << "\nSo phuc co module lon nhat la:" << ds[maxModule(ds)];
	
	cout << "\nSo so phuc thuan ao la:" << demThuanAo(ds);
	
	return 0;
}
