#include <iostream>
#include "myList.h"
#include<iomanip>
#include<string>
#include<fstream>
using namespace std;

class KhachHang{
	private:
		string ten = "";
		string sdt = "";
		double tongTien = 0.0f;
		int soCuocNoiHat = 0;
		int soCuocLanCan = 0;
		int soCuocXa = 0;
		int soCuocRatXa = 0;
	public:
		KhachHang(string ten = "", string sdt = "") {
		    this->ten = ten;
		    this->sdt = sdt;
		    this->tongTien = 0;
		    this->soCuocNoiHat = 0;
		    this->soCuocLanCan = 0;
		    this->soCuocXa = 0;
		    this->soCuocRatXa = 0;
		} 
};
