#include<iostream>
#include<fstream>
#include<cmath>
#include<iomanip>
using namespace std;


void docDaThucTuFile(ifstream &fileIn,float *daThuc, int bacDaThuc);
void inDaThuc(float *daThuc, int bacDaThuc);
float* daoHamDaThuc(float *daThuc, int bacDaThuc, int &bacDaoHam);
int triTuyetDoiLonNhat(float *daThuc, int bacDaThuc);
float tinhGiaTriDaThuc(float *daThuc, int bacDaThuc, float x);


int main(){
	int bacDaThuc;
	string tenFileInput;
	cout << "Nhap ten file de doc da thuc :";	getline(cin, tenFileInput);
	
	ifstream fileIn(tenFileInput);
	if(!fileIn){
		cerr << "Khong the mo file " << tenFileInput;
		return 1;
	}
	
	fileIn >> bacDaThuc;
	float *daThuc = new float[bacDaThuc+1];
	
	docDaThucTuFile(fileIn, daThuc, bacDaThuc);
	cout << "\nDa thuc vua doc tu file " << tenFileInput << " la :";
	inDaThuc(daThuc, bacDaThuc);
	
	float x;
	cout << "\nNhap x:"; 	cin >> x;
	cout << "\nGia tri cua da thuc tai x = "<< x << " la :" << tinhGiaTriDaThuc(daThuc, bacDaThuc, x);
	
	int bacDaoHam;
	float *daThucDaoHam = daoHamDaThuc(daThuc, bacDaThuc, bacDaoHam);
	cout << "\nDa thuc sau khi dao ham la :";
	inDaThuc(daThucDaoHam, bacDaoHam);
	
	int bacTuongUng = triTuyetDoiLonNhat(daThuc, bacDaThuc);
	cout << "\nHe so co gia tri tuyet doi lon nhat la " << daThuc[bacTuongUng] << " voi bac tuong ung la " << bacTuongUng;
	
	delete[] daThuc;
	delete[] daThucDaoHam;
	return 0;
}

void docDaThucTuFile(ifstream &fileIn,float *daThuc, int bacDaThuc){
	for(int i=0; i<=bacDaThuc; i++){
		fileIn >> daThuc[i];
	}
}

void inDaThuc(float *daThuc, int bacDaThuc){
	int soDaIn = 0;
	for(int i=0; i<=bacDaThuc; i++){
		if(daThuc[i] == 0)	continue;
		if(soDaIn == 0){
			if(daThuc[i] < 0)	cout << "-";
		}
		else{
			if(daThuc[i] < 0)	cout << " - ";
			else				cout << " + ";
		}
		
		float heSo = abs(daThuc[i]);
		
		if(heSo != 1 || i==0)	cout << heSo;
		if(i > 1)				cout << "x^" << i;
		else if(i == 1)			cout << "x";
		
		soDaIn++;
	}
	if(soDaIn == 0)		cout << 0;
}

float* daoHamDaThuc(float *daThuc, int bacDaThuc, int &bacDaoHam){
	if(bacDaThuc <= 0)	return nullptr;
	
	bacDaoHam = bacDaThuc - 1;
	float *daThucDaoHam = new float[bacDaoHam+1];
	
	for(int i=0; i<=bacDaoHam; i++){
		daThucDaoHam[i] = (i+1) * daThuc[i+1];
	}
	
	return daThucDaoHam;
}

int triTuyetDoiLonNhat(float *daThuc, int bacDaThuc){
	float max = abs(daThuc[0]);
	int bacTuongUng = 0;
	for(int i=0; i<=bacDaThuc; i++){
		if( abs(daThuc[i]) > max){
			max = abs(daThuc[i]);
			bacTuongUng = i;
		}
	}
	return bacTuongUng;
}

float tinhGiaTriDaThuc(float *daThuc, int bacDaThuc, float x){
	float ketQua = 0;
	
	for(int i=bacDaThuc; i>=0; i--){
		ketQua = ketQua * x + daThuc[i];
	}
	
	return ketQua;
}
