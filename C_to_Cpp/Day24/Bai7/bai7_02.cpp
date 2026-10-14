#include <iostream>
#include <iomanip>
#include <string>
#include<vector>
using namespace std;

class MH {
	protected:
	    string maMH;
	    string ten;
	    int stc;
	public:
	    MH() : maMH(""), ten(""), stc(0) {}
	
	    void nhap() {
	        cout << "Nhap ma mon hoc: ";    getline(cin, maMH);
	        cout << "Nhap ten mon hoc: ";   getline(cin, ten);
	        cout << "Nhap so tin chi: ";    cin >> stc;  cin.ignore();
	    }
	
	    void xuat()  {
	        cout << left 
				 << setw(12) << maMH 
	             << setw(25) << ten 
	             << setw(8) << stc << endl;
	    }
	
	    int getSTC()  { return stc; }
};

class HK {
	private:
	    string maHK;
	    int soMH;
	    MH* ds;
	public:
	    HK() : maHK(""), soMH(0), ds(nullptr){}
	
	    void nhap() {
	        cout << "Nhap ma hoc ky: ";     getline(cin, maHK);
	        cout << "Nhap so mon hoc: ";    cin >> soMH; cin.ignore();
	        
	        ds = new MH[soMH];
	        for (int i = 0; i < soMH; i++) {
	            cout << "Mon hoc thu " << i + 1 << "\n";
	            ds[i].nhap();
	        }
    }

    int tinhTongTinChi() {
        int tong = 0;
        for (int i = 0; i < soMH; i++) {
            tong += ds[i].getSTC();
        }
        return tong;
    }

    void xuat() {
        cout << "\nHoc ky: " << maHK << " | Tong so tin chi: " << tinhTongTinChi() << endl;
        cout << left << setw(12) << "Ma MH" << setw(25) << "Ten MH" << setw(8) << "So TC" << endl;
        for (int i = 0; i < soMH; i++) {
            ds[i].xuat();
        }
    }
};

void nhapDanhSach(vector<HK> &danhSach, int soHocKy){
	for(int i=0; i<soHocKy; i++){
		danhSach[i].nhap();
	}
}

void xuatDanhSach(vector<HK> &danhSach){
	for(int i=0; i<danhSach.size(); i++){
		danhSach[i].xuat();
	}
}

int maxTinChi(vector<HK> &danhSach){
	int max = danhSach[0].tinhTongTinChi();
	int viTri = 0;
	
	for(int i=0; i<danhSach.size(); i++){
		if(danhSach[i].tinhTongTinChi() > max){
			max = danhSach[i].tinhTongTinChi();
			viTri = i;
		}
	}
	return viTri;
}

int main(){
	int soHocKy;
	cout << "Nhap so ky hoc:";		cin >> soHocKy;		cin.ignore();
	
	vector<HK> danhSach(soHocKy);
	
	nhapDanhSach(danhSach, soHocKy);
	
	cout << "\nDanh sach hoc ky vua nhap la:" << endl;
	xuatDanhSach(danhSach);
	
	int viTri = maxTinChi(danhSach);
	cout << "\nHoc ky co nhieu tin chi nhat la:";
	danhSach[viTri].xuat();
	
	return 0;
}
