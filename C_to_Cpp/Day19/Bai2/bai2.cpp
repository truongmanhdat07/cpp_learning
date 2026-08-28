#include<iostream>
#include<cmath>

using namespace std;

struct PhanSo{
	int tuSo;
	int mauSo;
};

int UCLN(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

void toiGianPhanSo(PhanSo &phanSo){
	int ucln = UCLN(phanSo.tuSo, phanSo.mauSo);
	phanSo.tuSo /= ucln;
	phanSo.mauSo /= ucln;
	
	if(phanSo.mauSo < 0){
		phanSo.tuSo = -phanSo.tuSo;
		phanSo.mauSo = -phanSo.mauSo;
	}
}

void nhapPhanSo(PhanSo &phanSo){
		cout << "\nNhap tu so :"; 	cin >> phanSo.tuSo;
		
	do{
		cout << "Nhap mau so :";	cin >> phanSo.mauSo;
		if(phanSo.mauSo == 0)	cout << "\nMau so phai khac 0, vui long nhap lai :\n";;
	}while(phanSo.mauSo == 0);
	
	toiGianPhanSo(phanSo);
}

void inPhanSo(PhanSo phanSo){
	if(phanSo.mauSo == 1)			cout << phanSo.tuSo;
	else if(phanSo.tuSo == 0)		cout << 0;
	else							cout << phanSo.tuSo << "/" << phanSo.mauSo;
}

PhanSo congPhanSo(PhanSo ps1, PhanSo ps2) {
    PhanSo ketQua;
    
    ketQua.tuSo = (ps1.tuSo * ps2.mauSo) + (ps2.tuSo * ps1.mauSo);
    ketQua.mauSo = ps1.mauSo * ps2.mauSo;
    toiGianPhanSo(ketQua);
    
    return ketQua;
}

PhanSo hieuPhanSo(PhanSo ps1, PhanSo ps2){
	PhanSo ketQua;
    
    ketQua.tuSo = (ps1.tuSo * ps2.mauSo) - (ps2.tuSo * ps1.mauSo);
    ketQua.mauSo = ps1.mauSo * ps2.mauSo;
    toiGianPhanSo(ketQua);
    
    return ketQua;
}

PhanSo tichPhanSo(PhanSo ps1, PhanSo ps2){
	PhanSo ketQua;
	
	ketQua.tuSo = ps1.tuSo * ps2.tuSo;
	ketQua.mauSo = ps1.mauSo * ps2.mauSo;
	toiGianPhanSo(ketQua);
	
	return ketQua;
}

PhanSo thuongPhanSo(PhanSo ps1, PhanSo ps2){
	PhanSo ketQua;
	
	ketQua.tuSo = ps1.tuSo * ps2.mauSo;
	ketQua.mauSo = ps2.tuSo * ps1.mauSo;
	toiGianPhanSo(ketQua);
	    
	return ketQua;
}


int main(){
	PhanSo ps1, ps2;
	
	cout << "Nhap phan so 1 :";		nhapPhanSo(ps1);
	cout << "\nNhap phan so 2 :";	nhapPhanSo(ps2);
	
	cout << "\nPhan so 1 vua nhap la:";		inPhanSo(ps1);
	cout << "\nPhan so 2 vua nhap la:";		inPhanSo(ps2);
	
	PhanSo tong = congPhanSo(ps1, ps2);
	cout << "\nTong 2 phan so vua nhap la :";
	inPhanSo(tong);
	
	PhanSo hieu = hieuPhanSo(ps1, ps2);
	cout << "\nHieu 2 phan so vua nhap la :";
	inPhanSo(hieu);
	
	PhanSo tich = tichPhanSo(ps1, ps2);
	cout << "\nTich 2 phan so vua nhap la :";
	inPhanSo(tich);
	
	PhanSo thuong = thuongPhanSo(ps1, ps2);
	cout << "\nThuong 2 phan so vua nhap la:";
	inPhanSo(thuong);
	
	
	return 0;
}
