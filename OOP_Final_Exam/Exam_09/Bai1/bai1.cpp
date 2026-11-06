#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

class Vector2D{
	private:
		float x, y;
	public:
		Vector2D(float x = 0, float y =0) : x(x), y(y){}
		
		float getDoDai(){
			return sqrt(x*x + y*y);
		}
		
		friend istream& operator>>(istream &is, Vector2D &v){
			cout << "Nhap x:";		is >> v.x;
			cout << "Nhap y:";		is >> v.y;
			return is;
		}
		
		friend ostream& operator<<(ostream &os, Vector2D &v){
			return	os << "(" << v.x << ", " << v.y << ")" << "  ";
		}
		
		Vector2D operator+(Vector2D &other){
			return Vector2D(this->x + other.x , this->y + other.y);
		}
		
		float operator*(Vector2D &other){
			return this->x * other.x + this->y * other.y;
		}
		
		bool operator>(Vector2D &other){
			return this->getDoDai() > other.getDoDai();
		}
};

void nhapDanhSach(vector<Vector2D> &ds, int soLuong){
	for(int i=0; i<soLuong; i++){
		cout << "Nhap vecto thu " << i+1 << ":" << endl;
		cin >> ds[i];
	}
}

int maxDoDai(vector<Vector2D> &ds){
	float max = ds[0].getDoDai();
	int viTri = 0;
	for(int i=0; i<ds.size(); i++){
		if(ds[i].getDoDai() > max){
			max = ds[i].getDoDai();
			viTri = i;
		}
	}
	return viTri;
}


int main(){
	Vector2D u, v;
	cout << "Nhap 2 vector:" << endl;		cin >> u >> v;
	cout << "2 vector vua nhap:" << u << v;
	
	cout << "\nDo dai cua u = " << u.getDoDai();
	
	if(u*v == 0)		cout << "\nVuong goc";
	else				cout << "\nKhong vuong goc";
	
	int soLuong;
	cout << "\nNhap so luong vector:";	cin >> soLuong;
	vector<Vector2D> ds(soLuong);
	
	nhapDanhSach(ds, soLuong);
	
	cout << "\nVector co do dai lon nhat la :" << ds[maxDoDai(ds)] << "voi do dai = " << ds[maxDoDai(ds)].getDoDai();
	
	return 0;
}
