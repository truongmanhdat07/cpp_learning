#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

class Nguoi {
	protected:
	    string cccd;
	    string hoTen;
	public:
	    Nguoi() {}
	    Nguoi(string cccd, string hoTen) : cccd(cccd), hoTen(hoTen) {}
	    
	    void nhap() {
	        cout << "Nhap CCCD: "; 		getline(cin, cccd);
	        cout << "Nhap ho ten: ";	getline(cin, hoTen);
	    }
	    
	    void xuat() {
	        cout << left << setw(15) << cccd << setw(25) << hoTen;
	    }
	
	    string getHoTen() { return hoTen; }
};

class NhanVien : public Nguoi {
	private:
	    int namSinh = 0;
	    float heSoLuong = 0.0f; 
	public:
	    NhanVien() {}
	    NhanVien(string cccd, string hoTen, int namSinh, float heSoLuong) 
	        : Nguoi(cccd, hoTen), namSinh(namSinh), heSoLuong(heSoLuong) {}
	    
	    void nhap() {
	        Nguoi::nhap();
	        cout << "Nhap nam sinh: ";		 cin >> namSinh;
	        cout << "Nhap he so luong: "; 	 cin >> heSoLuong;
	        cin.ignore();
	    }
	    
	    void xuat(){
	        Nguoi::xuat();
	        cout << left << setw(12) << namSinh 
	             << setw(15) << fixed << setprecision(2) << heSoLuong 
	             << setw(15) << tinhLuong() << endl;
	    }
	
	    float tinhLuong(){
	        return heSoLuong * 1.5f;
	    }
	
	    int getNamSinh(){ return namSinh; }
};

class SinhVien : public Nguoi {
	private:
	    int lop = 0;
	    float diem = 0.0f;
	public:
	    SinhVien() {}
	    SinhVien(string cccd, string hoTen, int lop, float diem) 
	        : Nguoi(cccd, hoTen), lop(lop), diem(diem) {}
	    
	    void nhap() {
	        Nguoi::nhap();
	        cout << "Nhap lop (1, 2, 3): "; 	cin >> lop;
	        cout << "Nhap diem: "; 				cin >> diem;
	        cin.ignore();
	    }
	    
	    void xuat() {
	        Nguoi::xuat();
	        cout << left << setw(10) << lop 
	             << setw(10) << fixed << setprecision(2) << diem << endl;
	    }
	
	    int getLop()  { return lop; }
	    float getDiem()  { return diem; }
};






int main(){
	int n;	cout << "Nhap n:";	cin >> n;
	vector<NhanVien> nv(n);
	
	
	
	
	
	
	return 0;
}
