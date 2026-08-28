#include<iostream>
#include<cmath>

using namespace std;

class DaThuc{
	private:
		int bacDaThuc;
		float *heSo; 
	public:
		void nhap();
		void xuat();
		int getBac();
		float* getHeSo();
		DaThuc daoHam();
};

int DaThuc::getBac(){
	return bacDaThuc;
}

float* DaThuc::getHeSo(){
	return heSo; 
}

DaThuc DaThuc::daoHam(){
	DaThuc daThucDaoHam;
	if(bacDaThuc < 1){
		daThucDaoHam.bacDaThuc = 0;
		daThucDaoHam.heSo = new float[1];
		daThucDaoHam.heSo[0] = 0;
		return daThucDaoHam;
	}
	daThucDaoHam.bacDaThuc = bacDaThuc - 1;
	daThucDaoHam.heSo = new float[daThucDaoHam.bacDaThuc + 1];
	
	for(int i=0; i<=daThucDaoHam.bacDaThuc; i++){
		daThucDaoHam.heSo[i] = (i+1) * heSo[i+1];
	}
	return daThucDaoHam;
}

void DaThuc::nhap(){
	cout << "\nNhap bac cua da thuc :";
	cin >> bacDaThuc;
	
	heSo = new float[bacDaThuc+1];
	for(int i=0; i<=bacDaThuc; i++){
		cout << "Nhap he so bac " << i << " :";
		cin >> heSo[i];
	}
}

void DaThuc::xuat(){
	int soDaIn = 0;
	
	for(int i=0; i<=bacDaThuc; i++){
		if(heSo[i] == 0) continue;
		
		if(soDaIn == 0){
			if(heSo[i] < 0)	cout << "-";
		}
		else{
			if(heSo[i] < 0) cout << " - ";
			else            cout << " + ";
		}
		
		float giaTriHeSo = abs(heSo[i]);
		
		if(giaTriHeSo != 1 || i == 0)   cout << giaTriHeSo;
		if(i > 1)                       cout << "x^" << i;
		else if(i == 1)                 cout << "x";
		
		soDaIn++;
	}
}




float giaTriDaThuc(DaThuc *daThuc, float giaTri);
void nhapDanhSachDaThuc(DaThuc *danhSachDaThuc, int soLuongDaThuc);
void xuatDanhSachDaThuc(DaThuc *danhSachDaThuc, int soLuongDaThuc);
float nhapGiaTri();
DaThuc* daoHamDanhSach(DaThuc *danhSachDaThuc, int soLuongDaThuc);
int timViTriDaThucDaoHamMax(DaThuc *danhSachDaoHam, int soLuongDaThuc, float x);


int main(){
	int soLuongDaThuc;
	cout << "Nhap so luong da thuc :";	cin >> soLuongDaThuc;
	DaThuc *danhSachDaThuc = new DaThuc[soLuongDaThuc];
	
	nhapDanhSachDaThuc(danhSachDaThuc, soLuongDaThuc);
	cout << "\nDanh sach da thuc vua nhap la :\n";
	xuatDanhSachDaThuc(danhSachDaThuc, soLuongDaThuc);
	
	float x = nhapGiaTri();
	
	DaThuc *danhSachDaoHam = daoHamDanhSach(danhSachDaThuc, soLuongDaThuc);
	cout << "\nDanh sach da thuc sau khi dao ham la :";
	xuatDanhSachDaThuc(danhSachDaoHam, soLuongDaThuc);
	
	int viTri = timViTriDaThucDaoHamMax(danhSachDaoHam, soLuongDaThuc, x);
	cout << "\nDa thuc co gia tri dao ham lon nhat tai x la :" ;
	danhSachDaThuc[viTri].xuat();
	cout << " voi gia tri = " << giaTriDaThuc(&danhSachDaoHam[viTri], x);
	
	
	delete[] danhSachDaoHam;
	delete[] danhSachDaThuc;
	return 0;
}



float giaTriDaThuc(DaThuc *daThuc, float giaTri){
	float ketQua = 0;
	
	for(int i=0; i<=daThuc->getBac(); i++){
		ketQua += daThuc->getHeSo()[i] * pow(giaTri, i);
	}
	
	return ketQua;
}

void nhapDanhSachDaThuc(DaThuc *danhSachDaThuc, int soLuongDaThuc){
	for(int i=0; i<soLuongDaThuc; i++){
		cout << "\nNhap da thuc thu " << i+1 << " :";
		danhSachDaThuc[i].nhap();
	}
}

void xuatDanhSachDaThuc(DaThuc *danhSachDaThuc, int soLuongDaThuc){
	for(int i=0; i<soLuongDaThuc; i++){
		cout << "\nDa thuc thu " << i+1 << " la :";
		danhSachDaThuc[i].xuat();
	}
}

float nhapGiaTri(){
	float x;
	cout << "\nNhap x :";
	cin >> x;
	return x;
}

DaThuc* daoHamDanhSach(DaThuc *danhSachDaThuc, int soLuongDaThuc){
	DaThuc *danhSachDaoHam = new DaThuc[soLuongDaThuc];
	
	for(int i=0; i<soLuongDaThuc; i++){
		danhSachDaoHam[i] = danhSachDaThuc[i].daoHam();
	}
	
	return danhSachDaoHam;
}

int timViTriDaThucDaoHamMax(DaThuc *danhSachDaoHam, int soLuongDaThuc, float x){
	int viTri=0;
	float max = giaTriDaThuc(&danhSachDaoHam[0], x);
	
	for(int i=1; i<soLuongDaThuc; i++){
		if( giaTriDaThuc(&danhSachDaoHam[i], x) > max){
			max = giaTriDaThuc(&danhSachDaoHam[i], x);
			viTri = i;
		}
	}
	
	return viTri;
}
