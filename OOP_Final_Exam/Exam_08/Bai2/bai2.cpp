#include<iostream>
#include<iomanip>
#include<vector>

using namespace std;

class Xe{
	protected:
		string bienSo = "";
		string hangSX = "";
		long long giaGoc = 0;
	public:
		Xe(){}
		Xe(string bienSo, string hangSX, long long giaGoc) : bienSo(bienSo), hangSX(hangSX), giaGoc(giaGoc){}
		
		string getBienSo(){
			return bienSo;
		}
		
		void nhap(){
			cout << "Nhap bien so:";		getline(cin, bienSo);
			cout << "Nhap hang san xuat:";	getline(cin, hangSX);
			cout << "Nhap gia goc:";		cin >> giaGoc;
		}
		
		void xuat(){
			cout << left
				 << setw(12) << bienSo
				 << setw(20) << hangSX
				 << setw(12) << giaGoc;
		}
		
};


class OTO : public Xe{
	private:
		int soCho = 0;
		float taiTrong = 0.0f;
	public:
		OTO(){}
		OTO(string bienSo, string hangSX, long long giaGoc, int soCho, float taiTrong) 
		: Xe(bienSo, hangSX, giaGoc) , soCho(soCho), taiTrong(taiTrong){}
		
		float getTaiTrong(){
			return taiTrong;
		}
		
		int getSoCho(){
			return soCho;
		}
		
		long long tinhGia(){
			long long gia = giaGoc * 1.1;
			if(soCho <= 7)	return gia + 20000000;
			else			return gia + 30000000;
		}
		
		void nhap(){
			Xe::nhap();
			cout << "Nhap so cho:";		cin >> soCho;
			cout << "Nhap tai trong:";	cin >> taiTrong;	cin.ignore();
		}
		
		void xuat(){
			Xe::xuat();
			cout << setw(12) << soCho
				 << fixed << setprecision(2) <<  setw(12) << taiTrong
				 << setw(12) << tinhGia() << endl;
		}
};

class XeMay : public Xe{
	private:
		int phanKhoi = 0;
		int loaiXe = 0;
	public:
		XeMay(){}
		XeMay(string bienSo, string hangSX, long long giaGoc, int phanKhoi, int loaiXe)
		: Xe(bienSo, hangSX, giaGoc), phanKhoi(phanKhoi), loaiXe(loaiXe){}
		
		int getPhanKhoi(){
			return phanKhoi;
		}
		
		int getLoaiXe(){
			return loaiXe;
		}
		
		void nhap(){
			Xe::nhap();
			cout << "Nhap phan khoi:";		cin >> phanKhoi;
			cout << "Nhap loai xe:";		cin >> loaiXe;		cin.ignore();
		}
		
		void xuat(){
			Xe::xuat();
			cout << setw(12) << phanKhoi
				 << setw(12) << loaiXe << endl;
		}
};

template<typename T> 
void nhapDanhSach(vector<T> &ds, int soLuong){
	for(int i=0; i<soLuong; i++){
		cout << "Nhap vao thong tin xe thu " << i+1 << ":";
		ds[i].nhap();
	}
}

int maxTaiTrong(vector<OTO> &dsoto){
	float max = dsoto[0].getTaiTrong();
	int viTri = 0;
	for(int i=0; i<dsoto.size(); i++){
		if(dsoto[i].getTaiTrong() > max){
			max = dsoto[i].getTaiTrong();
			viTri = i;
		}
	}
	return viTri;
}

void xuatDanhSachOto(vector<OTO> &dsoto){
	for(int i=0; i<dsoto.size(); i++){
		dsoto[i].xuat();
	}
}

void thongKeTheoSoCho(vector<OTO> &dsoto){
	for(int i=0; i<dsoto.size(); i++){
		if(dsoto[i].getSoCho() == 7)	dsoto[i].xuat();
	}
}


int maxPhanKhoi(vector<XeMay> &dsxm){
	int max = dsxm[0].getPhanKhoi();
	int viTri = 0;
	for(int i=0; i<dsxm.size(); i++){
		if(dsxm[i].getPhanKhoi() > max){
			max = dsxm[i].getPhanKhoi();
			viTri = i;
		}
	}
	return viTri;
}

void thongKeXeMay(vector<XeMay> &dsxm){
	int so = 0, ga = 0;
	
	for(int i=0; i<dsxm.size(); i++){
		if(dsxm[i].getLoaiXe() == 1)	so++;
		else							ga++;
	}
	
	cout << "\nSo luong xe so:" << so << "\nSo luong xe ga:" << ga;
}


void timKiemTheoBienSo(vector<XeMay> &dsxm, string bienSo){
	for(int i=0; i<dsxm.size(); i++){
		if(dsxm[i].getBienSo() == bienSo){
			cout << "\nDa tim thay xe co bien so " << bienSo << endl;
			dsxm[i].xuat();
			return ;
		}
	}
	cout << "\nKhong tim thay xe co bien so " << bienSo << endl;
}

int main(){
	int n;
	cout << "Nhap so luong o to :";		cin >> n;		cin.ignore();
	
	vector<OTO> dsoto(n);
	
	nhapDanhSach(dsoto, n);
	
	cout << "\nOto co trong tai lon nhat la:" << endl;
	dsoto[maxTaiTrong(dsoto)].xuat();
	
	cout << "\nThong ke gia lan banh:" << endl;
	xuatDanhSachOto(dsoto);
	
	cout << "\nDanh sach oto 7 cho la:" << endl;
	thongKeTheoSoCho(dsoto);
	
	
	
	
	int m;
	cout << "Nhap so luong xe may:";		cin >> m;		cin.ignore();
	
	vector<XeMay> dsxm(m);
	
	nhapDanhSach(dsxm, m);
	
	cout << "\nXe may co phan khoi cao nhat la:" << endl;
	dsxm[maxPhanKhoi(dsxm)].xuat();
	
	thongKeXeMay(dsxm);
	
	string bienSo;
	cout << "\nNhap bien so can tim:";
	getline(cin >> ws, bienSo);
	
	timKiemTheoBienSo(dsxm, bienSo);
	
	return 0;
}
