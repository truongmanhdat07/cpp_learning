#include<iostream>
#include<iomanip>
#include<fstream>

using namespace std;


class Xe{
	protected:
		string maXe = "";
		string bienSo = "";
		string hangXe = "";
		int namSX = 0;
		float giaXe = 0.0;
	public:
		Xe(){};

		
};


class XeTai : public Xe{
	private:
		float taiTrong = 0.0;
		string loaiThung = "";
	public:
		XeTai(){};

};



class XeKhach : public Xe{
	private:
		int soGhe = 0;
		string phamVi = "";
	public:
		XeKhach(){};
		
		
};
