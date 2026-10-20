#include<iostream>
#include<vector>
#include<iomanip>
#include<string>
using namespace std;

class Vehicle{
	protected:
		string brand;
		float speed;
	public:
		Vehicle(){}
		Vehicle(string brand, float speed) : brand(brand), speed(speed){}
		
		void nhap(){
			cout << "Nhap brand:";		getline(cin, brand);
			cout << "Nhap speed:";		cin >> speed;		cin.ignore();
		}
		
		void xuat(){
			cout << left << fixed << setprecision(2)
			     << setw(20) << brand
			     << setw(10) << speed << endl;
		}
		
		virtual void move() = 0;
		virtual ~Vehicle(){}
};

class Car : public Vehicle{
	public:
		void move() override{
			cout << "\nOto, di chuyen bang dong co";
		}
};

class Bicycle : public Vehicle{
	public:
		void move() override{
			cout << "\nXe dap, di chuyen bang suc nguoi";
		}
};

class Motorcycle : public Vehicle{
	public:
		void move() override{
			cout << "\nXe may, di chuyen bang dong co";
		}
};


void nhapDanhSach(vector<Vehicle*> &danhSach, int soLuong){
	for(int i=0; i<soLuong; i++){
		int chon;
		cout << "\nNhap loai phuong tien(Car-Bicycle-Motorcycle) :";	cin >> chon;	cin.ignore();
		
		if(chon == 1){
			Vehicle* x = new Car;
			x->nhap();
			danhSach.push_back(x);
		}
		else if(chon == 2){
			Vehicle* x = new Bicycle;
			x->nhap();
			danhSach.push_back(x);	
		}	
		else{
			Vehicle* x = new Motorcycle;
			x->nhap();
			danhSach.push_back(x);	
		}
	}
}

void xuatDanhSach(vector<Vehicle*> &danhSach){
	for(int i=0; i<danhSach.size(); i++){
		danhSach[i]->move();
	}
}

void giaiPhongBoNho(vector<Vehicle*> &danhSach){
	for(int i=0; i<danhSach.size(); i++)	delete danhSach[i];
}

int main(){
	int soLuong;
	cout << "Nhap so luong:";	cin >> soLuong ; 	cin.ignore();
	
	vector<Vehicle*> danhSach;
	
	nhapDanhSach(danhSach, soLuong);
	
	xuatDanhSach(danhSach);
	
	giaiPhongBoNho(danhSach);
	
	return 0;
}
