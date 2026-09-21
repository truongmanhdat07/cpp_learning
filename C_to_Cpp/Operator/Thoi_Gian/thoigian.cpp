#include<iostream>
#include<cmath>
using namespace std;

class ThoiGian{
	private:
		int gio;
		int phut;
		int giay;
	public:
		ThoiGian(int gio = 0, int phut = 0, int giay = 0) : gio(gio), phut(phut), giay(giay){
			chuanHoa();
		}
		
		int tongSoGiay() const;
		
		friend istream& operator>>(istream &in, ThoiGian &tg);
		friend ostream& operator<<(ostream &out, const ThoiGian &tg);
		
		void chuanHoa();
		
		ThoiGian& operator++();
		ThoiGian operator++(int);
		
		ThoiGian operator+(const int s) const;
		ThoiGian operator-(const int s) const;
		int operator-(const ThoiGian &other) const;
		
		ThoiGian& operator+=(const int s);
		ThoiGian& operator-=(const int s);
		
		bool operator==(const ThoiGian &other) const;
		bool operator!=(const ThoiGian &other) const;
		bool operator<(const ThoiGian &other) const;
		bool operator>(const ThoiGian &other) const;
		bool operator<=(const ThoiGian &other) const;
		bool operator>=(const ThoiGian &other) const;
};

int ThoiGian::tongSoGiay() const{
	return ( gio * 3600 + phut  * 60 + giay );
}


istream& operator>>(istream &in, ThoiGian &tg){
	cout << "Nhap gio - phut - giay:";	
	in >> tg.gio >> tg.phut >> tg.giay;
	tg.chuanHoa();
	
	return in;
}

ostream& operator<<(ostream& out, const ThoiGian &tg){
	out << tg.gio << ":" << tg.phut << ":" << tg.giay << endl;
	
	return out;
}


void ThoiGian::chuanHoa(){
	int tongGiay = tongSoGiay();
	if(tongGiay < 0)	tongGiay = 0;
	
	this->gio = tongGiay / 3600;	tongGiay = tongGiay % 3600;
	this->phut = tongGiay / 60;		
	this->giay = tongGiay % 60;
}


ThoiGian& ThoiGian::operator++(){
	this->giay++;
	chuanHoa();
	return *this;
}

ThoiGian ThoiGian::operator++(int){
	ThoiGian temp = *this;
	this->giay++;
	chuanHoa();
	return temp;
}


ThoiGian ThoiGian::operator+(const int s) const{
	ThoiGian kq = *this;
	kq.giay += s;
	kq.chuanHoa();
	return kq;
}

ThoiGian ThoiGian::operator-(const int s) const{
	ThoiGian kq = *this;
	kq.giay -= s;
	kq.chuanHoa();
	return kq;
}


int ThoiGian::operator-(const ThoiGian &other) const{
	return abs( this->tongSoGiay() - other.tongSoGiay() );
}


ThoiGian& ThoiGian::operator+=(const int s){
	this->giay += s;
	this->chuanHoa();
	return *this;
}

ThoiGian& ThoiGian::operator-=(const int s){
	this->giay -= s;
	this->chuanHoa();
	return *this;
}


bool ThoiGian::operator==(const ThoiGian &other) const{
	return (giay == other.giay && phut == other.phut && gio == other.gio);
}

bool ThoiGian::operator!=(const ThoiGian &other) const{
	return !(*this == other);
}

bool ThoiGian::operator<(const ThoiGian &other) const{
	return ( this->tongSoGiay() < other.tongSoGiay() );
}

bool ThoiGian::operator>(const ThoiGian &other) const{
	return (other < *this);
}

bool ThoiGian::operator<=(const ThoiGian &other) const{
	return !(*this > other);
}

bool ThoiGian::operator>=(const ThoiGian &other) const{
	return !(*this < other);
}



int main(){
    ThoiGian t1, t2;
    cin >> t1 >> t2;
    cout << "t1 = " << t1;
    cout << "t2 = " << t2;
    
    int s;
    cout << "Nhap so giay s: "; cin >> s;
    
    cout << "t1 + s = " << t1 + s;
    cout << "t1 - s = " << t1 - s;
    cout << "Do lech giua t1 va t2: " << t1 - t2 << " giay" << endl;
    
	cout << "++t1: " << ++t1;
	cout << "t1++: " << t1++;         
	cout << "t1 sau khi t1++: " << t1; 

    t1 += s;
    cout << "t1 sau khi += s: " << t1;
    t1 -= s;
    cout << "t1 sau khi -= s: " << t1 << endl;
    
    if(t1 == t2) cout << "t1 == t2\n";
    if(t1 != t2) cout << "t1 != t2\n";
    if(t1 < t2)  cout << "t1 < t2\n";
    if(t1 > t2)  cout << "t1 > t2\n";
    if(t1 <= t2) cout << "t1 <= t2\n";
    if(t1 >= t2) cout << "t1 >= t2\n";

    return 0;
}
