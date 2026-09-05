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
		string getBienSo();
		int getNamSX();
		
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
void inTieuDe();
void xuatDanhSachXe(Xe **danhSachXe, int soLuongXe);
float tinhTongChiPhiBaoDuong(Xe **danhSachXe, int soLuongXe);
int timXeTheoBienSo(Xe **danhSachXe, int soLuongXe, string bienSoXeCanTim);
void xuLyTimKiemXeTheoBienSo(Xe **danhSachXe, int soLuongXe);
Xe** locDanhSachXeTheoNamSX(Xe **danhSachXe, int soLuongXe, int namSXCanLoc, int &soLuongDaLoc);
void xuLyDanhSachXeTheoNamSX(Xe **danhSachXe, int soLuongXe);


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

string Xe::getBienSo(){
	return bienSo;
}

int Xe::getNamSX(){
	return namSX;
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
    cout << setw(10) << maXe 	
         << setw(14) << bienSo 
         << setw(14) << hangXe  
         << setw(10) << namSX
         << setw(16) << giaXe;
}

void XeTai::xuat(){
    Xe::xuat();
    cout << setw(14) << taiTrong 
         << setw(16) << loaiThung
         << setw(16) << getChiPhiBaoDuong();
}

void XeKhach::xuat(){
    Xe::xuat();
    cout << setw(14) << soGhe
         << setw(16) << phamVi
         << setw(16) << getChiPhiBaoDuong();
}



int main(){
	int soLuongXe;
	cout << "Nhap so luong xe:";	cin >> soLuongXe; 	cin.ignore();
	
	Xe **danhSachXe = new Xe*[soLuongXe];
	
	nhapDanhSachXe(danhSachXe, soLuongXe);
	
	cout << "\nDanh sach xe vua nhap la:\n";
	xuatDanhSachXe(danhSachXe, soLuongXe);
	
	float tongChiPhiBaoDuong = tinhTongChiPhiBaoDuong(danhSachXe, soLuongXe);
	cout << "\nTong chi phi bao duong xe la:" << tongChiPhiBaoDuong;
	
	xuLyTimKiemXeTheoBienSo(danhSachXe, soLuongXe);
	
	xuLyDanhSachXeTheoNamSX(danhSachXe, soLuongXe);
	
	
	
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

void inTieuDe(){
    cout << left << fixed << setprecision(2);

    cout << setw(10) << "Ma xe"
         << setw(14) << "Bien so"
         << setw(14) << "Hang xe"
         << setw(10) << "Nam SX"
         << setw(16) << "Gia xe"
         << setw(14) << "Thong so 1"
         << setw(16) << "Thong so 2"
         << setw(16) << "Phi bao duong" << endl;
}

void xuatDanhSachXe(Xe **danhSachXe, int soLuongXe){
	inTieuDe();
	for(int i=0; i<soLuongXe; i++){
		danhSachXe[i]->xuat();
		cout << endl;
	}
}

float tinhTongChiPhiBaoDuong(Xe **danhSachXe, int soLuongXe){
	float tong = 0;
	for(int i=0; i<soLuongXe; i++){
		tong += danhSachXe[i]->getChiPhiBaoDuong();
	}
	
	return tong;
}

int timXeTheoBienSo(Xe **danhSachXe, int soLuongXe, string bienSoXeCanTim){
	
	for(int i=0; i<soLuongXe; i++){
		if(danhSachXe[i]->getBienSo() == bienSoXeCanTim)	return i;
	}
	
	return -1;
}

void xuLyTimKiemXeTheoBienSo(Xe **danhSachXe, int soLuongXe){
	string bienSoCanTim;
	cout << "\nNhap bien so xe can tim:";	getline(cin, bienSoCanTim);
	int viTri = timXeTheoBienSo(danhSachXe, soLuongXe, bienSoCanTim);
	
	if(viTri != -1){
		cout << "\nDa tim thay xe co bien so " << bienSoCanTim << ":" << endl;
		danhSachXe[viTri]->xuat();
	}
	else		cout << "\nKhong tim thay xe co bien so " << bienSoCanTim << "!";
}

Xe** locDanhSachXeTheoNamSX(Xe **danhSachXe, int soLuongXe, int namSXCanLoc, int &soLuongDaLoc){
	Xe** danhSachXeDaLoc = new Xe*[soLuongXe];
	soLuongDaLoc = 0;
	
	for(int i=0; i<soLuongXe; i++){
		if(danhSachXe[i]->getNamSX() >=	namSXCanLoc){
			danhSachXeDaLoc[soLuongDaLoc] = danhSachXe[i];
			soLuongDaLoc++;
		}
	}
	
	return danhSachXeDaLoc;
}

void xuLyDanhSachXeTheoNamSX(Xe **danhSachXe, int soLuongXe){
	int soLuongDaLoc;
	int namSXCanLoc;
	cout << "\nNhap nam san xuat can loc danh sach:";	cin >> namSXCanLoc;
	
	Xe** danhSachXeDaLoc = locDanhSachXeTheoNamSX(danhSachXe, soLuongXe, namSXCanLoc, soLuongDaLoc);
	
	if(soLuongDaLoc !=0){
		cout << "\nDanh sach xe san xuat sau nam " << namSXCanLoc << " la:" << endl;
		xuatDanhSachXe(danhSachXeDaLoc, soLuongDaLoc);
	}
	else	cout << "\nKhong co xe nao san xuat sau nam " << namSXCanLoc << "!";
	
	
	delete[] danhSachXeDaLoc;
}














void giaiPhongBoNho(Xe **danhSachXe, int soLuongXe){
	for(int i=0; i<soLuongXe; i++){
		delete danhSachXe[i];
	}
	
	delete[] danhSachXe;
}
