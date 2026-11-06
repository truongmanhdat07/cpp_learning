#include<iostream>
#include<iomanip>
#include<vector>

using namespace std;

class NhanVat{
	protected:
		string id;
		string ten;
		int level;
	public:
		NhanVat(string id = "", string ten = "", int level = 0) : id(id), ten(ten), level(level){}
		
		string getTen(){
			return ten;
		}
		
		int getLevel(){
			return level;
		}
		
		void nhap(){
			cout << "Nhap id:";		getline(cin, id);
			cout << "Nhap ten:";	getline(cin, ten);
			cout << "Nhap level:";	cin >> level;
		}
		
		void xuat(){
			cout << left 
				 << setw(12) << id
				 << setw(20) << ten
				 << setw(12) << level;
		}
};

class ChienBinh : public NhanVat{
	private:
		float hp, atk;
	public:
		ChienBinh(string id = "", string ten = "", int level = 0, float hp = 0.0f, float atk = 0.0f)
		: NhanVat(id, ten, level), hp(hp), atk(atk){}
		
		float getLucChien(){
			return hp + atk * 2.5;
		}
		
		void nhap(){
			NhanVat::nhap();
			cout << "Nhap HP:";		cin >> hp;
			cout << "Nhap ATK:";	cin >> atk;		cin.ignore();
		}
		
		void xuat(){
			NhanVat::xuat();
			cout << setw(12) << hp << setw(12) << atk << endl;
		}
};

class PhapSu : public NhanVat{
	private:
		float mana, ap;
	public:
		PhapSu(string id = "", string ten = "", int level = 0, float mana = 0.0f, float ap = 0.0f)
		: NhanVat(id, ten, level), mana(mana), ap(ap){}
		
		float getMana(){
			return mana;
		}
		
		float getAp(){
			return ap;
		}
		
		void nhap(){
			NhanVat::nhap();
			cout << "Nhap mana:";	cin >> mana;
			cout << "Nhap ap:";		cin >> ap;		cin.ignore();
		}
		
		void xuat(){
			NhanVat::xuat();
			cout << setw(12) << mana << setw(12) << ap << endl;
		}
};


template<typename T>
void nhapDanhSach(vector<T> &ds, int sl){
	for(int i=0; i<sl; i++){
		cout << "Nhap nhan vat thu " << i+1 << ":" << endl;
		ds[i].nhap();
	}
}

int maxLucChien(vector<ChienBinh> &dscb){
	float max = dscb[0].getLucChien();
	int viTri = 0;
	for(int i=0; i<dscb.size(); i++){
		if(dscb[i].getLucChien() > max){
			max = dscb[i].getLucChien();
			viTri = i;
		}
	}
	return viTri;
}

void timKiemTheoTen(vector<ChienBinh> &dscb, string ten){
	for(int i=0; i<dscb.size(); i++){
		if(dscb[i].getTen() == ten){
			cout << "\nDa tim thay chien binh " << ten << ":" << endl;
			dscb[i].xuat();
			return;
		}
	}
	cout << "\nKhong tim thay chien binh " << ten;
}


int minMana(vector<PhapSu> &dsps){
	float min = dsps[0].getMana();
	int viTri = 0;
	for(int i=0; i<dsps.size(); i++){
		if(dsps[i].getMana() < min){
			min = dsps[i].getMana();
			viTri = i;
		}
	}
	return viTri;
}

void thongKeTheoLevel(vector<PhapSu> &dsps){
	int dem = 0;
	for(int i=0; i<dsps.size(); i++){
		if(dsps[i].getLevel() >= 50){
			if(dem == 0)	cout << "\nDanh sach phap su co level >= 50 la:" << endl;
			dsps[i].xuat();
			dem++;
		}
	}
	
	if(dem == 0)	cout << "\nKhong co phap su nao co level >= 50";
	else			cout << "Tong cong co " << dem << " phap su co level >= 50" << endl;
}

void thongKeTheoAP(vector<PhapSu> &dsps){
	int dem = 0;
	for(int i=0; i<dsps.size(); i++){
		if(dsps[i].getAp() >= 300){
			if(dem == 0)	cout << "\nDanh sach phap su co AP >= 300 la:" << endl;
			dsps[i].xuat();
			dem++;
		}
	}
	
	if(dem == 0)	cout << "\nKhong co phap su nao co AP >= 300";
}

int main(){
	int n;
	cout << "Nhap so luong chien binh:";		cin >> n;		cin.ignore();
	
	vector<ChienBinh> dscb(n);
	
	nhapDanhSach(dscb, n);
	
	cout << "\nChien binh co luc chien cao nhat la:" << endl ;		dscb[maxLucChien(dscb)].xuat();
	
	string ten;
	cout << "\nNhap ten chien binh can tim:";		getline(cin>>ws, ten);
	timKiemTheoTen(dscb, ten);
	
	
	int m;
	cout << "\nNhap so luong phap su:";		cin >> m;		cin.ignore();
	
	vector<PhapSu> dsps(m);
	
	nhapDanhSach(dsps, m);
	
	cout << "\nPhap su co luong mana thap nhat la:" << endl;	dsps[minMana(dsps)].xuat();
	
	thongKeTheoLevel(dsps);
	
	thongKeTheoAP(dsps);
	
	
	return 0;
}
