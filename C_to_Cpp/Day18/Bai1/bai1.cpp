#include<iostream>
#include<cmath>
#include<iomanip>
#include<fstream>

using namespace std;

class Diem{
	private:
		float x,y;
	public:
		void nhap(istream &in);
		void in(ostream &out);
		float getX();
		float getY();
};


void Diem::nhap(istream &in){
	in >> x >> y;
}

void Diem::in(ostream &out){
	out << "( " << x << " , " << y << " )" << endl ;
}

float Diem::getX(){
	return x;
}

float Diem::getY(){
	return y;
}


void nhapDanhSachDiem(ifstream &fileIn,Diem *danhSachDiem, int soLuongDiem);
void inDanhSachDiem(ostream &out, Diem *danhSachDiem, int soLuongDiem);
float tinhKhoangCach(Diem *danhSachDiem, int viTri);
Diem *diemXaGocToaDoNhat(Diem *danhSachDiem, int soLuongDiem, int &soDiem, float &max);
void demDiemThuocGocPhanTu(Diem *danhSachDiem, int soLuongDiem, int *danhSach);
int demDiemThuocTrucToaDo(Diem *danhSachDiem, int soLuongDiem);
Diem *diemThuocDuongTron(Diem *danhSachDiem, int soLuongDiem , float R , int &soDiemThoaMan);



int main(){
	int soLuongDiem;
	string tenFileInput;
	cout << "Nhap ten file can doc :";	getline(cin, tenFileInput);
	
	ifstream fileIn(tenFileInput);
	if(!fileIn){
		cerr << "\nKhong the mo file " << tenFileInput;
		return 1;
	}
	
	fileIn >> soLuongDiem;
	Diem *danhSachDiem = new Diem[soLuongDiem];
	
	nhapDanhSachDiem(fileIn,danhSachDiem, soLuongDiem);
	cout << "\nDanh sach diem vua doc tu file " << tenFileInput << " la :\n";
	inDanhSachDiem(cout, danhSachDiem, soLuongDiem);
	
	int viTri;
	cout << "\nNhap diem can tinh vi tri :";	cin >> viTri;
	cout << "Khoang cach tu diem thuoc vi tri " << viTri << " den goc toa do O(0, 0) la :" << tinhKhoangCach(danhSachDiem, viTri-1);
	
	int soDiem = 0;
	float max;
	
	Diem *danhSachDiemXaGocToaDoNhat = diemXaGocToaDoNhat(danhSachDiem, soLuongDiem, soDiem, max);
	cout << "\nDanh sach diem xa goc toa do nhat la :\n";
	inDanhSachDiem(cout, danhSachDiemXaGocToaDoNhat, soDiem);
	
	int *danhSach = new int[4]();
	demDiemThuocGocPhanTu(danhSachDiem, soLuongDiem, danhSach);
	
	cout << "\nSo diem thuoc goc phan tu thu nhat la :" << danhSach[0];
	cout << "\nSo diem thuoc goc phan tu thu hai la :"  << danhSach[1];
	cout << "\nSo diem thuoc goc phan tu thu ba la :"   << danhSach[2];
	cout << "\nSo diem thuoc goc phan tu thu tu la :"   << danhSach[3];
	
	int ketQua = demDiemThuocTrucToaDo(danhSachDiem, soLuongDiem);
	cout << "\nSo diem thuoc truc toa do Ox va Oy la :" << ketQua;
	
	float R;
	cout << "\nNhap ban kinh R :";	cin >> R;
	int soDiemThoaMan = 0;
	Diem* danhSachDiemThuocDuongTron = diemThuocDuongTron(danhSachDiem, soLuongDiem, R, soDiemThoaMan);
	
	
	string tenFileOutput;
	cout << "\nNhap ten file de xuat danh sach diem thuoc duong tron :";
	cin.ignore();	getline(cin, tenFileOutput);
	
	ofstream fileOut(tenFileOutput);
	if(!fileOut){
		cerr << "\nKhong the mo file " << tenFileOutput;
		return 1;
	}
	
	inDanhSachDiem(fileOut, danhSachDiemThuocDuongTron, soDiemThoaMan);
	
	delete[] danhSachDiem;
	delete[] danhSachDiemXaGocToaDoNhat;
	delete[] danhSach;
	delete[] danhSachDiemThuocDuongTron;
	return 0;
}


void nhapDanhSachDiem(ifstream &fileIn, Diem *danhSachDiem, int soLuongDiem){
	
	for(int i=0; i<soLuongDiem; i++){
		danhSachDiem[i].nhap(fileIn);
	}
	
}

void inDanhSachDiem(ostream &out, Diem *danhSachDiem, int soLuongDiem){
	
	for(int i=0; i<soLuongDiem; i++){
		danhSachDiem[i].in(out);
	}
	
}

float tinhKhoangCach(Diem *danhSachDiem, int viTri){
	float x = danhSachDiem[viTri].getX();
	float y = danhSachDiem[viTri].getY();
	return sqrt( x*x + y*y );
}

Diem *diemXaGocToaDoNhat(Diem *danhSachDiem, int soLuongDiem, int &soDiem, float &max){
	soDiem = 0;
	max = tinhKhoangCach(danhSachDiem, 0);
	
	Diem *danhSachDiemXaGocToaDoNhat = new Diem[soLuongDiem];
	
	for(int i=1; i<soLuongDiem; i++){
		if(tinhKhoangCach(danhSachDiem, i) > max)	max = tinhKhoangCach(danhSachDiem, i);
	}
	
	for(int i=0; i<soLuongDiem; i++){
		if(tinhKhoangCach(danhSachDiem, i) == max){
			danhSachDiemXaGocToaDoNhat[soDiem] = danhSachDiem[i];
			soDiem++;
		}
	}
	
	return danhSachDiemXaGocToaDoNhat;
}

void demDiemThuocGocPhanTu(Diem *danhSachDiem, int soLuongDiem, int *danhSach){
	for(int i=0; i<soLuongDiem; i++){
		float x = danhSachDiem[i].getX();
		float y = danhSachDiem[i].getY();
		
		if(x > 0 && y > 0)			danhSach[0]++;
		else if( x < 0 && y > 0)	danhSach[1]++;
		else if( x < 0 && y < 0)	danhSach[2]++;
		else if( x > 0 && y < 0)	danhSach[3]++;
	}

}

int demDiemThuocTrucToaDo(Diem *danhSachDiem, int soLuongDiem){
	int dem = 0;
	
	for(int i=0; i<soLuongDiem; i++){
		float x = danhSachDiem[i].getX();
		float y = danhSachDiem[i].getY();
		
		if(x == 0 || y==0)	dem++;
	}
	
	return dem;
}

Diem *diemThuocDuongTron(Diem *danhSachDiem, int soLuongDiem , float R , int &soDiemThoaMan){
	soDiemThoaMan = 0;
	Diem *danhSachDiemThuocDuongTron = new Diem[soLuongDiem];
	
	for(int i=0; i<soLuongDiem; i++){
		if(tinhKhoangCach(danhSachDiem, i) <= R){
			danhSachDiemThuocDuongTron[soDiemThoaMan] = danhSachDiem[i];
			soDiemThoaMan++;
		}
	}
	
	return danhSachDiemThuocDuongTron;
}
