#include<iostream>
#include<fstream>
#include<iomanip>

using namespace std;

class Tuong{
	private:
		string maTuong;
		string tenTuong;
		string vaiTro;
		int giaVang;
		float tyLeThang;
	public:
		void nhap(istream &in);
		void in(ostream &out);
		string getMaTuong();
		string getTenTuong();
		string getVaiTro();
		int getGiaVang();
		float getTyLeThang();
};


string Tuong::getMaTuong(){
	return maTuong;
}

string Tuong::getTenTuong(){
	return tenTuong;
}

string Tuong::getVaiTro(){
	return vaiTro;
}

int Tuong::getGiaVang(){
	return giaVang;
}

float Tuong::getTyLeThang(){
	return tyLeThang;
}

void Tuong::nhap(istream &in){
	in >> maTuong >> tenTuong >> vaiTro >> giaVang >> tyLeThang;
}

void Tuong::in(ostream &out){
	out << left << setw(12) << maTuong << left << setw(20) << tenTuong << left << setw(15) << vaiTro
		<< left << setw(15) << giaVang << left << setw(15) << tyLeThang << endl;
}


void nhapDanhSachTuong(istream &in, Tuong *danhSachTuong, int soLuongTuong);
void xuatDanhSachTuong(ostream &out, Tuong *danhSachTuong, int soLuongTuong);
float trungBinhCongTyLeThang(Tuong *danhSachTuong, int soLuongTuong);
bool timKiemTuong(Tuong *danhSachTuong, int soLuongTuong, string tenTuongCanTim, int &viTriTuong);
void thongKeTheoGiaVang(Tuong *danhSachTuong, int soLuongTuong, int *Giavang);
void xuatSoTuongTheoGiaVang(int *giaVang);
Tuong* locTuongTheoVaiTro(Tuong* danhSachTuong, int soLuongTuong, string vaiTroCanTim, int &soTuong);


int main(){
	int soLuongTuong;
	string tenFileInput;
	cout << "Nhap ten file de doc du lieu :";		getline(cin, tenFileInput);
	
	ifstream fileIn(tenFileInput);
	if(!fileIn){
		cerr << "\nKhong the mo file " << tenFileInput;
		return 1;
	}
	
	fileIn >> soLuongTuong;	fileIn.ignore();
	Tuong *danhSachTuong = new Tuong[soLuongTuong];
	
	nhapDanhSachTuong(fileIn, danhSachTuong, soLuongTuong);
	cout << "\nDanh sach tuong vua doc tu file " << tenFileInput << " la :\n";
	xuatDanhSachTuong(cout, danhSachTuong, soLuongTuong);
	
	cout << "\nTrung binh cong ty le thang cua tat ca cac tuong la :" << trungBinhCongTyLeThang(danhSachTuong, soLuongTuong);
	
	int viTriTuong;
	string tenTuongCanTim;
	cout << "\nNhap ten tuong can tim :";
	getline(cin, tenTuongCanTim);
	
	if(timKiemTuong(danhSachTuong, soLuongTuong, tenTuongCanTim, viTriTuong)){
		cout << "\nDa tim thay tuong " << tenTuongCanTim << " trong danh sach tuong :\n";
		xuatDanhSachTuong(cout, &danhSachTuong[viTriTuong], 1);
	}
	else	cout << "\nKhong tim thay tuong " << tenTuongCanTim << " trong danh sach!";
	
	int giaVang[6]= {0};
	thongKeTheoGiaVang(danhSachTuong, soLuongTuong, giaVang);
	xuatSoTuongTheoGiaVang(giaVang);
	
	int soTuong;
	string vaiTroCanTim;
	cout << "\nNhap vai tro can loc :";
	getline(cin, vaiTroCanTim);
	Tuong* danhSachTuongTheoVaiTro = locTuongTheoVaiTro(danhSachTuong, soLuongTuong, vaiTroCanTim, soTuong);
	if(soTuong > 0){
		string tenFileOutput;
		
		cout << "\nNhap ten file de xuat danh sach :";
		getline(cin, tenFileOutput);
		ofstream fileOut(tenFileOutput);
		
		cout << "\nDanh sach tuong co vai tro " << vaiTroCanTim << " la :\n";
		xuatDanhSachTuong(fileOut, danhSachTuongTheoVaiTro, soTuong);	
	}
	else	cout << "\nKhong tim thay tuong thuoc vai tro " << vaiTroCanTim << "!";
	
	
	delete[] danhSachTuong;
	delete[] danhSachTuongTheoVaiTro;
	return 0;
}

void nhapDanhSachTuong(istream &in, Tuong *danhSachTuong, int soLuongTuong){
	for(int i=0; i<soLuongTuong; i++){
		danhSachTuong[i].nhap(in);
	}
}

void xuatDanhSachTuong(ostream &out, Tuong *danhSachTuong, int soLuongTuong){
	for(int i=0; i<soLuongTuong; i++){
		danhSachTuong[i].in(out);
	}
}

float trungBinhCongTyLeThang(Tuong *danhSachTuong, int soLuongTuong){
	float tongTyLeThang = 0;
	
	for(int i=0; i<soLuongTuong; i++){
		tongTyLeThang += danhSachTuong[i].getTyLeThang();
	}
	
	return tongTyLeThang / soLuongTuong;
}

bool timKiemTuong(Tuong *danhSachTuong, int soLuongTuong, string tenTuongCanTim, int &viTriTuong){
	viTriTuong = -1;
	for(int i=0; i<soLuongTuong; i++){
		if(danhSachTuong[i].getTenTuong() == tenTuongCanTim){
			viTriTuong = i;
			return true;
		}
	}
	
	return false;
}

void thongKeTheoGiaVang(Tuong *danhSachTuong, int soLuongTuong, int *giaVang){
	for(int i = 0; i < soLuongTuong; i++){
		int gia = danhSachTuong[i].getGiaVang();

		if(gia >= 1 && gia <= 5){
			giaVang[gia]++;
		}
	}
}

void xuatSoTuongTheoGiaVang(int *giaVang){
	for(int i=1; i<=5; i++){
		cout << "\nSo tuong co gia vang la " << i << " la :" << giaVang[i];
	}
}

Tuong* locTuongTheoVaiTro(Tuong* danhSachTuong, int soLuongTuong, string vaiTroCanTim, int &soTuong){
	soTuong = 0;
	Tuong* danhSachTuongTheoVaiTro = new Tuong[soLuongTuong];
	
	for(int i=0; i<soLuongTuong; i++){
		if(danhSachTuong[i].getVaiTro() == vaiTroCanTim){
			danhSachTuongTheoVaiTro[soTuong] = danhSachTuong[i];
			soTuong++;
		}
	}
	
	return danhSachTuongTheoVaiTro;
}
