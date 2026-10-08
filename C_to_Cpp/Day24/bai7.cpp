#include<iostream>
#include<iomanip>
#include<string>
#include<vector>
using namespace std;

class MH{
	protected:
		string ma = "";
		string ten = "";
		string nsx = "";
		int sl = 0;
		float dg = 0.0f;
	public:
		MH(){}
		MH(string ma, string ten, string nsx, int sl, float dg) : ma(ma), ten(ten), nsx(nsx),
			sl(sl), dg(dg){}
			
		virtual void nhap(){
			cout << "Ma:";			getline(cin, ma);
			cout << "Ten:";			getline(cin, ten);
			cout << "NSX:";			getline(cin, nsx);
			cout << "So Luong:";	cin >> sl;
			cout << "Don Gia:";		cin >> dg;	cin.ignore();
		}
		
		virtual void xuat(){
			cout << left << fixed << setprecision(0)
				 << setw(10) << ma
				 << setw(20) << ten
				 << setw(20) << nsx
				 << setw(8)  << sl
				 << setw(14) << dg;
		}
		
		float getDonGia(){
			return dg;
		}
};


class MayTinh : public MH{
	private:
		string cpu = "";
		string hdh = "";
		float tl = 0.0f;
	public:
		MayTinh(){}
		MayTinh(string ma, string ten, string nsx, int sl, float dg, string cpu, string hdh, float tl) :
			MH(ma, ten, nsx, sl, dg), cpu(cpu), hdh(hdh), tl(tl){}
			
		void nhap() override{
			MH::nhap();
			cout << "CPU:";				getline(cin, cpu);
			cout << "HDH:";				getline(cin, hdh);
			cout << "Trong Luong:";		cin >> tl;	cin.ignore();
		}
		
		void xuat() override{
			MH::xuat();
			cout << setw(10) << cpu
				 << setw(14) << hdh
				 << setw(12) << tl << endl;
		}
};

void nhapDanhSach(vector<MH*> &ds, int soLuong){
	for(int i=0; i<soLuong; i++){
		MH* mt = new MayTinh();
		mt->nhap();
		ds.push_back(mt);
	}
}

void xuatDanhSach(vector<MH*> &ds){
	for(int i=0; i<ds.size(); i++){
		ds[i]->xuat();
	}
}

float maxDonGia(vector<MH*> &ds){
	float max = ds[0]->getDonGia();
	for(int i=0; i<ds.size(); i++){
		if(ds[i]->getDonGia() > max)	max = ds[i]->getDonGia();
	}
	return max;
}

vector<MH*> locDanhSach(vector<MH*> &ds, float max){
	vector<MH*> dsl;
	for(int i=0; i<ds.size(); i++){
		if(ds[i]->getDonGia() == max){
			dsl.push_back(ds[i]);
		}
	}
	return dsl;
}



int main(){
	int soLuong;
	cout << "Nhap so luong mat hang:";		cin >> soLuong;		cin.ignore();
	
	vector<MH*> ds;
	
	nhapDanhSach(ds, soLuong);
	
	float max = maxDonGia(ds);
	vector<MH*> dsl = locDanhSach(ds, max);
	cout << "\nDanh sach may tinh co don gia cao nhat la:" << endl;
	xuatDanhSach(dsl);
	
	
	return 0;
}
