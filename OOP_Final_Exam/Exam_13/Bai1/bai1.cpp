#include<iostream>
#include<vector>

using namespace std;
class ThoiGian{
	private:
		int gio, phut , giay;
	public:
		ThoiGian(int gio = 0, int phut = 0, int giay = 0) : gio(gio), phut(phut), giay(giay){}
		
		int tongGiay(){
			return giay + phut * 60 + gio * 3600;
		}
		
		int getGio(){
			return gio;
		}
		
		void chuanHoa(){
			int tongGiay = giay + phut * 60 + gio * 3600;
			gio = (tongGiay / 3600) % 24;
			tongGiay = tongGiay % 3600;
			phut = tongGiay / 60;
			giay = tongGiay % 60;
		}
		
		friend istream& operator>>(istream &is, ThoiGian &t){
			cout << "Nhap gio:";		is >> t.gio;
			cout << "Nhap phut:";		is >> t.phut;
			cout << "Nhap giay:";		is >> t.giay;
			return is;
		}
		
		friend ostream& operator<<(ostream &os, const ThoiGian &t){
			return	os << t.gio << ":" << t.phut << ":" << t.giay ;
		}
		
		ThoiGian operator+(int k){
			ThoiGian kq = *this;
			kq.giay += k;
			kq.chuanHoa();
			return kq;
		}
		
		bool operator>(ThoiGian &other){
			return this->tongGiay() > other.tongGiay();
		}
};

void nhapDanhSach(vector<ThoiGian> &ds, int sl){
	for(int i=0; i<sl; i++){
		cout << "\nNhap t thu " << i+1 << ":" << endl;
		cin >> ds[i];
	}
}

void muonNhat(vector<ThoiGian> &ds){
	int max = ds[0].tongGiay();
	int viTri = 0;
	for(int i=0; i<ds.size(); i++){
		if(ds[i].tongGiay() > max){
			max = ds[i].tongGiay();	
			viTri = i;
		}
	}
	cout << "\nThoi gian muon nhat la:" << ds[viTri];
}

int thongKeBuoiSang(vector<ThoiGian> &ds){
	int dem = 0;
	for(int i=0; i<ds.size(); i++){
		if(ds[i].getGio() < 12)	dem ++;
	}
	return dem;
}




int main(){
	ThoiGian t1, t2;
	cout << "Nhap t1:" << endl;		cin >> t1;
	cout << "Nhap t2:" << endl;		cin >> t2;
	
	cout << "t1 = " << t1 << ", t2 = " << t2;
	t2.chuanHoa();
	cout << "\nSau khi chuan hoa t2 = " << t2;
	
	cout << "\nt1 + 150s = " << t1 + 150;
	
	if(t1 > t2)		cout << "\nt1 muon hon t2";
	else			cout << "\nt1 som hon t2";
	
	int sl;
	cout << "\nNhap so luong:";		cin >> sl;
	vector<ThoiGian> ds(sl);
	
	nhapDanhSach(ds, sl);
	
	muonNhat(ds);
	
	cout << "\nSo thoi gian buoi sang la:" << thongKeBuoiSang(ds);
	
	return 0;
}
