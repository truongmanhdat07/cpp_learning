#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
using namespace std;


class MatHang{
	private:
		string maHang;
		string tenHang;
		int soLuong;
		float donGia;
	public:
		void nhap(ifstream &fileIn);
		void ghiFile(ofstream &fileOut);
		void in();
		string getMaHang();
		int getSoLuong();
		float getGiaTri();
		float getDonGia();
};


void MatHang::nhap(ifstream &fileIn){
	getline(fileIn, maHang);
	getline(fileIn, tenHang);
	fileIn >> soLuong >> donGia;
	fileIn.ignore();
}

void MatHang::in(){
	cout << "\n" << left << setw(12) << maHang << left << setw(30) << tenHang
		 << left << setw(12) << soLuong << left << setw(12) << donGia;
}

string MatHang::getMaHang(){
	return maHang;
}

int MatHang::getSoLuong(){
	return soLuong;
}

float MatHang::getGiaTri(){
	return soLuong * donGia;
}

float MatHang::getDonGia(){
	return donGia;
}

void MatHang::ghiFile(ofstream &fileOut){
	fileOut << "\n" << left << setw(12) << maHang << left << setw(30) << tenHang
			<< left << setw(12) << soLuong << left << setw(12) << donGia;		
}


void docDanhSachHangTuFile(ifstream &fileIn, MatHang *danhSachHang, int soLuongHang);
void inDanhSachHang(MatHang *danhSachHang, int soLuongHang);
float tongGiaTri(MatHang *danhSachHang, int soLuongHang);
void sapXepTheoDonGia(MatHang *danhSachHang, int soLuongHang);
void sapXepTheoSoLuong(MatHang *danhSachHang, int soLuongHang);
void xuatDanhSachHangRaFile(MatHang *danhSachHang, int soLuongHang, string tenFileOutput);


int main(){
	int soLuongHang ;
	string tenFileInput;
	cout << "Nhap ten file can doc :";		getline(cin, tenFileInput); 
	
	ifstream fileIn(tenFileInput);
	if(!fileIn){
		cerr << "\nKhong the mo file " << tenFileInput;
		return 1;
	}
	
	fileIn >> soLuongHang;		fileIn.ignore();
	MatHang *danhSachHang = new MatHang[soLuongHang];
	
	docDanhSachHangTuFile(fileIn, danhSachHang, soLuongHang);
	cout << "\nDanh sach mat hang vua doc tu file " << tenFileInput << " la :";
	inDanhSachHang(danhSachHang, soLuongHang);
	
	float tongGiaTriTonKho = tongGiaTri(danhSachHang, soLuongHang);
	cout << "\n\nTong gia tri don hang la :" << tongGiaTriTonKho;
	
	sapXepTheoDonGia(danhSachHang, soLuongHang);
	cout << "\n\nDanh sach 3 mat hang co don gia cao nhat la :";
	inDanhSachHang(danhSachHang, 3);
	
	sapXepTheoSoLuong(danhSachHang, soLuongHang);
	cout << "\n\nDanh sach mat hang sap xep theo so luong giam dan la :";
	inDanhSachHang(danhSachHang, soLuongHang);
	
	string tenFileOutput;
	cout << "\nNhap ten file de xuat danh sach :";		getline(cin, tenFileOutput);
	xuatDanhSachHangRaFile(danhSachHang, soLuongHang, tenFileOutput);
	
	delete[] danhSachHang;
	return 0;
}


void docDanhSachHangTuFile(ifstream &fileIn, MatHang *danhSachHang, int soLuongHang){
	for(int i=0; i<soLuongHang; i++){
		danhSachHang[i].nhap(fileIn);
	}
}

void inDanhSachHang(MatHang *danhSachHang, int soLuongHang){
	cout << "\n" << left << setw(12) << "Ma Hang" << left << setw(30) << "Ten Hang"
		 << left << setw(12) << "So Luong" << left << setw(12) << "Don Gia";	
	
	for(int i=0; i<soLuongHang; i++){
		danhSachHang[i].in();
	}
}

float tongGiaTri(MatHang *danhSachHang, int soLuongHang){
	float ketQua = 0;
	for(int i=0; i<soLuongHang; i++){
		ketQua += danhSachHang[i].getGiaTri();
	}
	
	return ketQua;
}

void sapXepTheoDonGia(MatHang *danhSachHang, int soLuongHang){
	for(int i=0; i<soLuongHang -1 ; i++){
		for(int j=i+1; j<soLuongHang; j++){
			if(danhSachHang[i].getDonGia() < danhSachHang[j].getDonGia()){
				MatHang temp = danhSachHang[i];
				danhSachHang[i] = danhSachHang[j];
				danhSachHang[j] = temp;
			}
		}
	}
}

void sapXepTheoSoLuong(MatHang *danhSachHang, int soLuongHang){
	for(int i=0; i<soLuongHang-1; i++){
		for(int j=i+1; j<soLuongHang; j++){
			if(danhSachHang[i].getSoLuong() < danhSachHang[j].getSoLuong()){
				MatHang temp = danhSachHang[i];
				danhSachHang[i] = danhSachHang[j];
				danhSachHang[j] = temp;
			}
			else if(danhSachHang[i].getSoLuong() == danhSachHang[j].getSoLuong()){
				if(danhSachHang[i].getMaHang() < danhSachHang[j].getMaHang()){
					MatHang temp = danhSachHang[i];
					danhSachHang[i] = danhSachHang[j];
					danhSachHang[j] = temp;
				}
			}
		}
	}
}

void xuatDanhSachHangRaFile(MatHang *danhSachHang, int soLuongHang, string tenFileOutput){
	ofstream fileOut(tenFileOutput);
	if(!fileOut){
		cerr << "\nKhong the mo file " << tenFileOutput ;
		return;
	}
	
	for(int i=0; i<soLuongHang; i++){
		danhSachHang[i].ghiFile(fileOut);
	}
	
	cerr << "\nXuat danh sach mat hang thanh cong vao file " << tenFileOutput;
}
