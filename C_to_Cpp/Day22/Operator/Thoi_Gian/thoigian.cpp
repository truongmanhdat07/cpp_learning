#include<iostream>

using namespace std;

class ThoiGian{
	private:
		int gio;
		int phut;
		int giay;
	public:
		ThoiGian(int gio = 0, int phut = 0, int giay = 0) : gio(gio), phut(phut), giay(giay){}
		
		int tongSoGiay();
		
		friend istream& operator>>(istream &in, ThoiGian &tg);
		friend ostream& operator<<(ostream &in, const ThoiGian &tg);
		
		void chuanHoa();
};

int ThoiGian::tongSoGiay(){
	return ( gio * 3600 + phut  * 60 + giay );
}

istream& operator>>(istream &in, ThoiGian &tg){
	cout << "Nhap gio:";	in >> tg.gio;
	cout << "Nhap phut:";	in >> tg.phut;
	cout << "Nhap giay:";	in >> tg.giay;
	
	return in;
}

ostream& operator<<(ostream& out, const ThoiGian &tg){
	out << tg.gio << ":" << tg.phut << ":" << tg.giay << endl;
	
	return out;
}

void ThoiGian::chuanHoa(){
	int tongGiay = tongSoGiay();
	
	this->gio = tongGiay / 3600;	tongGiay = giay % 3600;
	this->phut = tongGiay / 60;		
	this->giay = tongGiay % 60;
}






int main(){
	ThoiGian t1;
	cin >> t1;
	cout << t1;
	t1.chuanHoa();
	cout << t1;
	
	return 0;
}
