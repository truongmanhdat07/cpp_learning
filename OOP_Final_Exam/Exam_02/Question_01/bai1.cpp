#include<iostream>
#include<cmath>

using namespace std;

class CTime{
	private:
		int gio = 0, phut = 0, giay = 0;
	public:
		CTime(){}
		CTime(int gio, int phut, int giay){
		    if(gio < 0 || gio >= 24 || phut < 0 || phut >= 60 || giay < 0 || giay >= 60){
		        cout << "\nTG khong hop le!";
		        this->gio = 0;
		        this->phut = 0;
		        this->giay = 0;
		    } else {
		        this->gio = gio;
		        this->phut = phut;
		        this->giay = giay;
		    }
		}
		
		void nhap(){
			cout << "Nhap gio:";
			do{
				cin >> gio;
				if(gio < 0 || gio >=24)		cout << "\nGio k hop le, vui long nhap lai! :";
			} while(gio < 0 || gio >=24);
			
			cout << "Nhap phut:";
			do{
				cin >> phut;
				if(phut < 0 || phut >=60)		cout << "\nPhut k hop le, vui long nhap lai! :";
			} while(phut < 0 || phut >=60);
			
			cout << "Nhap giay:";
			do{
				cin >> giay;
				if(giay < 0 || giay >=60)		cout << "\nGiay k hop le, vui long nhap lai! :";
			} while(giay < 0 || giay >=60);
		}
		
		void xuat(){
			cout << gio << ":" << phut << ":" << giay << endl;
		}
		
		CTime& congGiay(int soGiay) {
		    int tongGiay = giay + soGiay;
		    giay = tongGiay % 60;
		    
		    int tongPhut = phut + (tongGiay / 60);
		    phut = tongPhut % 60;
		    
		    gio = (gio + tongPhut / 60) % 24; 
		    
		    return *this;
		}
};



int main(){
	CTime time;
	
	time.nhap();
	time.xuat();
	
	time.congGiay(5);
	time.xuat();
	
	time.congGiay(1);
	time.xuat();
	
	return 0;
}
