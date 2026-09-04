#include<iostream>
#include<iomanip>
#include<fstream>

using namespace std;

const int namHienTai = 2026;


class Xe{
	protected:
		string maXe;
		string bienSo;
		string hangXe;
		int namSX;
		float giaXe;
	public:
		Xe() : maXe(""), bienSo(""), hangXe(""), namSX(0), giaXe(0.0) {};
		Xe(string maXe, string bienSo, string hangXe, int namSX, float giaXe){
			this->maXe = maXe;
			this->bienSo = bienSo;
			this->hangXe = hangXe;
			this->namSX = namSX;
			this->giaXe = giaXe;
		};
		virtual ~Xe(){};
		
		virtual float getChiPhiBaoDuong() = 0;
		
		virtual void nhap();
		virtual void xuat();
};


class XeTai : public Xe{
	private:
		float taiTrong = 0.0;
		string loaiThung = "";
	public:
		XeTai() : Xe(), taiTrong(0.0), loaiThung(""){};
		XeTai(string maXe, string bienSo, string hangXe, int namSX, float giaXe, 
          	float taiTrong, string loaiThung) 
			: Xe(maXe, bienSo, hangXe, namSX, giaXe) {
          	  	
          	this->taiTrong = taiTrong;
       	 	this->loaiThung = loaiThung; 	 
		}
		~XeTai() override{};
		
		float getChiPhiBaoDuong() override;
		
		void nhap();
		void xuat();
};



class XeKhach : public Xe{
	private:
		int soGhe = 0;
		string phamVi = "";
	public:
		XeKhach() : Xe(), soGhe(0), phamVi(""){};
		XeKhach(string maXe, string bienSo, string hangXe, int namSX, float giaXe,
				int soGhe, string phamVi) 
				: Xe(maXe, bienSo, hangXe, namSX, giaXe) {
					
				this->soGhe = soGhe;
				this->phamVi = phamVi;
				}
		~XeKhach() override{};
		
		float getChiPhiBaoDuong() override;
		
		void nhap();
		void xuat();
};



void nhapDanhSachXe(Xe **danhSachXe, int soLuongXe);



void giaiPhongBoNho(Xe **danhSachXe, int soLuongXe);



float XeTai::getChiPhiBaoDuong(){
	float chiPhi = 2000000.0 + ( taiTrong * 1500000.0 );
	
	if(loaiThung == "dong lanh")	chiPhi *= 1.2;
	
	return chiPhi;
}

float XeKhach::getChiPhiBaoDuong(){
	float chiPhi = 2000000.0 + (soGhe * 100000.0);
	
	if(phamVi == "lien tinh")	chiPhi *= 1.15;
	
	return chiPhi;
}


void Xe::nhap(){
	cout << "\nNhap ma xe:";		getline(cin, maXe);
	cout << "Nhap bien so xe:";		getline(cin, bienSo);
	cout << "Nhap hang xe:";		getline(cin, hangXe);
	do{
		cout << "Nhap nam san xuat:";	cin >> namSX;
		if(namSX > namHienTai)	cout << "\nNam san xuat khong hop le vui long nhap lai!";
	}while(namSX > namHienTai);

	cout << "Nhap gia xe:";			cin >> giaXe;	cin.ignore();
}

void XeTai::nhap(){
	Xe::nhap();
	cout << "Nhap loai thung:";		getline(cin, loaiThung);
	cout << "Nhap tai trong:";		cin >> taiTrong;	cin.ignore();
}

void XeKhach::nhap(){
	Xe::nhap();
	cout << "Nhap pham vi:";		getline(cin, phamVi);
	cout << "Nhap so ghe:";			cin >> soGhe;		cin.ignore();
}


void Xe::xuat(){
	cout << left << setw(12) << maXe 	<< left << setw(15) << bienSo 
		 << left << setw(20) << hangXe  << left << setw(12) << namSX
		 << left << setw(12) << fixed   << setprecision(2)  << giaXe;
}

void XeTai::xuat(){
	Xe::xuat();
	cout << left << setw(12) << fixed << setprecision(2) << taiTrong << left << setw(15) << loaiThung;
}

void XeKhach::xuat(){
	Xe::xuat();
	cout << left << setw(12) << phamVi << left << setw(12) << soGhe;
}



int main(){
	int soLuongXe;
	cout << "Nhap so luong xe:";	cin >> soLuongXe; 	cin.ignore();
	
	Xe **danhSachXe = new Xe*[soLuongXe];
	
	nhapDanhSachXe(danhSachXe, soLuongXe);
	
	
	
	giaiPhongBoNho(danhSachXe, soLuongXe);
	return 0;
}


void nhapDanhSachXe(Xe **danhSachXe, int soLuongXe){
	for(int i=0; i<soLuongXe; i++){
		int chon = 0;
		cout << "\nNhap thong tin xe thu " << i+1 << ":";
		cout << "\n1:Xe Tai";
		cout << "\n2:Xe Khach";
		do{
			cout << "\nChon loai xe:";	cin >> chon;
			cin.ignore();
			
			switch(chon){
				case 1:
					danhSachXe[i] = new XeTai();
					break;
				case 2:
					danhSachXe[i] = new XeKhach();
					break;
				default:
					cout << "\nLua chon khong hop le vui long chon lai!";
					break;
			}
		}while(chon != 1 && chon !=2);
		
		danhSachXe[i]->nhap();
	}
}








void giaiPhongBoNho(Xe **danhSachXe, int soLuongXe){
	for(int i=0; i<soLuongXe; i++){
		delete danhSachXe[i];
	}
	
	delete[] danhSachXe;
}
