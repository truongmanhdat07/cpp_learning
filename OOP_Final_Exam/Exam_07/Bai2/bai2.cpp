#include<iostream>
#include<iomanip>
#include<vector>

using namespace std;

class ThietBi{
	protected:
		string ma = "";
		string ten = "";
		string hangSX = "";
		long long gia = 0;
	public:
		ThietBi(){}
		ThietBi(string ma, string ten, string hangSX, long long gia) : ma(ma), ten(ten), hangSX(hangSX), gia(gia){}
		
		string getMa(){
			return ma;
		}
		
		string getHangSX(){
			return hangSX;
		}
		
		void nhap(){
			cout << "Nhap ma: ";			getline(cin, ma);
			cout << "Nhap ten: ";			getline(cin, ten);
			cout << "Nhap hang san xuat: ";	getline(cin, hangSX);
			cout << "Nhap gia: ";			cin >> gia;		cin.ignore();
		}
		
		void xuat(){
			cout << left 
				 << setw(12) << ma
				 << setw(25) << ten
				 << setw(20) << hangSX
				 << setw(12) << gia;
		}
};

class MayTinh : public ThietBi{
	private:
		string cpu = "";
		int ram = 0;
	public:
		MayTinh(){};
		MayTinh(string ma, string ten, string hangSX, long long gia, string cpu, int ram) 
		: ThietBi(ma, ten, hangSX, gia), cpu(cpu), ram(ram){}
		
		float getGia(){
			return gia * 1.2 + ram * 100000;
		}
		
		void nhap(){
			ThietBi::nhap();
			cout << "Nhap cpu: ";		getline(cin, cpu);
			cout << "Nhap ram: ";		cin >> ram;		cin.ignore();
		}
		
		void xuat(){
			ThietBi::xuat();
			cout << setw(20) << cpu
				 << setw(12) << ram << endl;
		}
};


class DienThoai : public ThietBi{
	private:
		int pin = 0;
		int soSim = 0;
	public:
		DienThoai(){}
		DienThoai(string ma, string ten, string hangSX, long long gia, int pin, int soSim)
		: ThietBi(ma, ten, hangSX, gia), pin(pin), soSim(soSim){}
		
		int getPin(){
			return pin;
		}
		
		int getSoSim(){
			return soSim;
		}
		
		void nhap(){
			ThietBi::nhap();
			cout << "Nhap pin: ";		cin >> pin;
			cout << "Nhap so sim: ";	cin >> soSim;		cin.ignore();
		}
		
		void xuat(){
			ThietBi::xuat();
			cout << setw(20) << pin
				 << setw(12) << soSim << endl;
		}
};


template<typename T> 
void nhapDanhSach(vector<T> &ds, int soLuong){
	for(int i=0; i<soLuong; i++){
		ds[i].nhap();
	}
}

void maxGia(vector<MayTinh> &dsmt){
	float max = dsmt[0].getGia();
	int viTri = 0;
	
	for(int i=0; i<dsmt.size(); i++){
		if(dsmt[i].getGia() > max){
			max = dsmt[i].getGia();
			viTri = i;
		}
	}
	
	cout << "\nMay tinh co gia ban cao nhat la:" << endl;
	dsmt[viTri].xuat();
}

void thongKeTheoHang(vector<MayTinh> &dsmt, string hang){
	int dem = 0;
	for(int i=0; i<dsmt.size(); i++){
		if(dsmt[i].getHangSX() == hang){
			dem++;
			if(dem == 1)	cout << "\nDanh sach may tinh thuoc hang " << hang << " la:" << endl;
			dsmt[i].xuat();
		}
	}
}

void maxPin(vector<DienThoai> &dsdt){
	int max = dsdt[0].getPin();
	int viTri = 0;
	for(int i=0; i<dsdt.size(); i++){
		if(dsdt[i].getPin() > max){
			max = dsdt[i].getPin();
			viTri = i;
		}
	}
	
	cout << "\nDien thoai co pin cao nhat la:" << endl;
	dsdt[viTri].xuat();
}

void thongKeTheoSim(vector<DienThoai> &dsdt){
	int sim1 = 0, sim2 = 0;
	for(int i=0; i<dsdt.size(); i++){
		if(dsdt[i].getSoSim() == 1)		sim1++;
		else							sim2++;
	}
	
	cout << "\nThong ke so luong dien thoai:";
	cout << "\nSim 1:" << sim1;
	cout << "\nSim 2:" << sim2;
	if(sim1 > sim2)				cout << "\nSim 1 nhieu hon sim 2";
	else if(sim1 == sim2)		cout << "\nSim 1 bang sim 2";
	else						cout << "\nSim 2 nhieu hon sim 1";
}

void timKiemTheoMa(vector<DienThoai> &dsdt, string ma){
	for(int i=0; i<dsdt.size(); i++){
		if(dsdt[i].getMa() == ma){
			cout << "\nDa tim thay dien thoai co ma " << ma << ":" << endl;
			dsdt[i].xuat();
			return;
		}
	}
	cout << "\nKhong tim thay dien thoai co ma " << ma;
}


int main(){
	//mt
	int n;
	cout << "Nhap so luong may tinh:";		cin >> n;		cin.ignore();
	
	vector<MayTinh> dsmt(n);
	
	nhapDanhSach(dsmt, n);
	
	maxGia(dsmt);
	
	string hang;
	cout << "\nNhap hang san xuat can thong ke:";		getline(cin >> ws, hang);
	
	thongKeTheoHang(dsmt, hang);
	
	//dt
	int m;
	cout << "\nNhap so luong dien thoai:";		cin >> m;		cin.ignore();
	vector<DienThoai> dsdt(m);
	
	nhapDanhSach(dsdt, m);
	
	maxPin(dsdt);
	
	thongKeTheoSim(dsdt);
	
	string ma;
	cout << "\nNhap ma dien thoai can tim:";		getline(cin >> ws, ma);
		
	timKiemTheoMa(dsdt, ma);
	
	return 0;
}
