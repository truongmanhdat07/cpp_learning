#include <iostream>

using namespace std;

class Nguoi{
	protected:
		string ten;
		int namSinh;
	public:
		virtual void nhap();
		virtual void xuat();
		
		int tinhTuoi();
};

class SinhVien : public Nguoi{
	private:
		string ma;
		float diem;
	public:
		void nhap() override;
		void xuat() override;
};



void Nguoi::nhap(){
	cout << "Nhap ten:";			getline(cin, ten);
	cout << "Nhap nam sinh:";		cin >> namSinh;		cin.ignore();
}

void Nguoi::xuat(){
	cout << namSinh << "   " << ten << "   ";
}

int Nguoi::tinhTuoi(){
	return 2026 - namSinh;
}



void SinhVien::nhap(){
	Nguoi::nhap();
	cout << "Nhap ma:";		getline(cin, ma);
	cout << "Nhap diem:";	cin >> diem;	cin.ignore();
}

void SinhVien::xuat(){
	Nguoi::xuat();
	cout << ma << "   " << diem;
}



int main(){
	SinhVien sv1;
	sv1.nhap();
	sv1.xuat();
	cout << "\nTuoi cua sinh vien vua nhap la:" << sv1.tinhTuoi() << endl;
	
	
	
	
	return 0;
}
