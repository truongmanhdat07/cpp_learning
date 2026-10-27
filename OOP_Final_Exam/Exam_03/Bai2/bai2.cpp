#include<iostream>
#include<iomanip>
#include<vector>

using namespace std;

class Xe{
	protected:
		string bienSo;
		string mau;
	public:
		Xe(){}
		Xe(string bienSo, string mau) : bienSo(bienSo), mau(mau){}
		
		string getMau(){
			return mau;
		}
		
		virtual void nhap(){
			cout << "\nNhap bien so xe:";	getline(cin, bienSo);
			cout << "Nhap mau xe:";			getline(cin, mau);
		}
		
		virtual void xuat(){
			cout << left
				 << setw(15) << bienSo
				 << setw(10) << mau;
		}
};

class Oto : public Xe{
	private:
		float taiTrong;
		int soCho;
	public:
		Oto(){}
		Oto(string bienSo, string mau, float taiTrong, int soCho) : Xe(bienSo, mau), taiTrong(taiTrong), soCho(soCho){}
		
		float getTaiTrong(){
			return taiTrong;
		}
		
		int getSoCho(){
			return soCho;
		}
		
		void nhap() override{
			Xe::nhap();
			cout << "Nhap tai trong xe:";	cin >> taiTrong;
			cout << "Nhap so cho ngoi:";	cin >> soCho;	cin.ignore();
		}
		
		void xuat() override{
			Xe::xuat();
			cout << setw(15) << fixed << setprecision(2) << taiTrong
				 << setw(15) << soCho << endl;
		}
};

class XeMay : public Xe{
	private:
		int phanKhoi;
	public:
		XeMay(){}
		XeMay(string bienSo, string mau, int phanKhoi): Xe(bienSo, mau), phanKhoi(phanKhoi){};
		
		int getPhanKhoi(){
			return phanKhoi;
		}
		
		void nhap() override{
			Xe::nhap();
			cout << "Nhap phan khoi xe:";	cin >> phanKhoi;	cin.ignore();
		}
		
		void xuat() override{
			Xe::xuat();
			cout << setw(15) << phanKhoi << endl;
		}
};

template <typename T>
void nhapDanhSach(vector<T> &ds, int soLuong){
	for(int i=0; i<soLuong; i++){
		cout << "Nhap thong tin xe thu " << i+1 << ":";
		ds[i].nhap();
	}
}

void xuatDanhSachOto(vector<Oto> &danhSachOto){
	int dem = 0;
	for(int i=0; i<danhSachOto.size(); i++){
		if(danhSachOto[i].getSoCho() == 7){
			danhSachOto[i].xuat();
			dem++;
		}
	}
	if(dem == 0)	cout << "\nKhong co xe nao co 7 cho ";
}

int maxTaiTrong(vector<Oto> &danhSachOto){
	float max = danhSachOto[0].getTaiTrong();
	int viTri = 0;
	for(int i=1; i<danhSachOto.size(); i++){
		if(danhSachOto[i].getTaiTrong() > max){
			max = danhSachOto[i].getTaiTrong();	
			viTri = i;
		}	
	}
	return viTri;
}

float tongTaiTrong(vector<Oto> &danhSachOto){
	float tong = 0;
	for(int i=0; i<danhSachOto.size(); i++){
		if(danhSachOto[i].getSoCho() == 4)	tong += danhSachOto[i].getTaiTrong();
	}
	return tong;
}

void xuatOtoMauDoMaxTaiTrong(vector<Oto> &danhSachOto){
    int viTri = -1;
    float max = -1;
    
    for(int i = 0; i < danhSachOto.size(); i++){
        if(danhSachOto[i].getMau() == "do"){
            if(viTri == -1 || danhSachOto[i].getTaiTrong() > max){
                max = danhSachOto[i].getTaiTrong();
                viTri = i;
            }
        }
    }
    
    if(viTri == -1){
        cout << "\nKhong co xe o to mau do nao trong danh sach!" << endl;
    } else {
        cout << "\nXe mau do co tai trong max la: " << endl;
        danhSachOto[viTri].xuat();
    }
}


void xuatDanhSachXeMay(vector<XeMay> &danhSachXeMay){
	for(int i=0; i<danhSachXeMay.size(); i++){
		danhSachXeMay[i].xuat();
	}
}

int maxPhanKhoi(vector<XeMay> &danhSachXeMay){
	int max = danhSachXeMay[0].getPhanKhoi();
	int viTri = 0;
	for(int i=1; i<danhSachXeMay.size(); i++){
		if(danhSachXeMay[i].getPhanKhoi() > max){
			max = danhSachXeMay[i].getPhanKhoi();	
			viTri = i;
		}
	}
	return viTri;
}

void thongKeMauXeMay(vector<XeMay> &danhSachXeMay){
    int demDo = 0, demVang = 0, demXanh = 0;
    
    for(int i = 0; i < danhSachXeMay.size(); i++){
        if(danhSachXeMay[i].getMau() == "do")        demDo++;
        else if(danhSachXeMay[i].getMau() == "vang") demVang++;
        else if(danhSachXeMay[i].getMau() == "xanh") demXanh++;
    }
    
    cout << "\nSo luong xe may theo tung mau:" << endl;
    cout << "Mau do  : " << demDo   << " xe" << endl;
    cout << "Mau vang: " << demVang << " xe" << endl;
    cout << "Mau xanh: " << demXanh << " xe" << endl;
    
    int maxMau = demDo;
    if(demVang > maxMau)  maxMau = demVang;
    if(demXanh > maxMau)  maxMau = demXanh;
    
    
    cout << "\nMau co nhieu xe may nhat (" << maxMau << " xe) la: ";
    if(demDo == maxMau)   cout << "do ";
    if(demVang == maxMau) cout << "vang ";
    if(demXanh == maxMau) cout << "xanh ";
}

int main(){
	int n,m;
	cout << "Nhap so luong xe oto:";	cin >> n;	cin.ignore();
	
	vector<Oto> danhSachOto(n);
	
	nhapDanhSach(danhSachOto, n);
	
	cout << "\nDanh sach oto 7 cho:" << endl;
	xuatDanhSachOto(danhSachOto);
	
	cout << "\nXe max tai trong:" << endl; danhSachOto[maxTaiTrong(danhSachOto)].xuat();
	cout << "\nTong tai trong xe 4 cho ngoi = " << tongTaiTrong(danhSachOto) << endl;
	
	xuatOtoMauDoMaxTaiTrong(danhSachOto);	
	
	cout << "\nNhap so luong xe may:";		cin >> m;		cin.ignore();
	
	vector<XeMay> danhSachXeMay(m);
	
	nhapDanhSach(danhSachXeMay, m);
	
	cout << "\nDanh sach xe may vua nhap la:" << endl;
	xuatDanhSachXeMay(danhSachXeMay);
	
	cout << "\nXe co phan khoi max la:" << endl; danhSachXeMay[maxPhanKhoi(danhSachXeMay)].xuat();
	
	thongKeMauXeMay(danhSachXeMay);
	
	return 0;
}
