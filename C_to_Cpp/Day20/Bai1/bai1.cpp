#include<iostream>
#include<iomanip>
#include<fstream>

using namespace std;


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
		~virtual Xe(){};
		
		virtual void nhap();
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
		
};



class XeKhach : public Xe{
	private:
		int soGhe = 0;
		string phamVi = "";
	public:
		XeKhach() : Xe(), soGhe(0), phamVi(""){};
		XeKhach(string maXe, string bienSo, string hangXe, int namSX, float giaXe,
				int soghe, string phamVi) 
				: Xe(maXe, bienSo, hangXe, namSX, giaVe) {
					
				this->soGhe = soGhe;
				this->phamVi = phamVi;
				}
		~XeKhach() override{};
		
};


void Xe::nhap(){
	cout << "\nNhap ma xe:";		getline(cin, maXe);
	cout << "Nhap bien so xe:";		getline(cin, bienSo);
	cout << "Nhap hang xe:";		getline(cin, hangXe);
	cout << "Nhap nam san xuat:";	cin >> namSX;
	cout << "Nhap gia xe:";			cin >> giaXe;	cin.ignore();
}
