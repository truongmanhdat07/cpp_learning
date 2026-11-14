#include<iostream>

using namespace std;

class MaTran{
	private:
		int n;
		int a[20][20];
	public:
		friend istream& operator>>(istream &is, MaTran &mt){
			cout << "Nhap bac cua ma tran:";	is >> mt.n;
			for(int i=0; i<mt.n; i++){
				for(int j=0; j<mt.n; j++){
					cout << "Nhap phan thu hang " << i+1 << " cot " << j+1 << ":";
					is >> mt.a[i][j];
				}
			}
			return is;
		}
		
		friend ostream& operator<<(ostream &os, const MaTran &mt){
			for(int i=0; i<mt.n; i++){
				for(int j=0; j<mt.n; j++){
					os << mt.a[i][j] << "     ";
				}
				os << endl;
			}
			return os;
		}
		
		MaTran operator+(const MaTran &other) const{
			MaTran kq;
			kq.n = this->n;
			for(int i=0; i<n; i++){
				for(int j=0; j<n; j++){
					kq.a[i][j] = this->a[i][j] + other.a[i][j];
				}
			}
			
			return kq;
		}
		
		int tongDuongCheoChinh() const{
			int tong = 0;
			for(int i=0; i<n; i++){
				for(int j=0; j<n; j++){
					if(i == j)	tong += a[i][j];
				}
			}
			return tong;
		}
		
		void nhoNhat(){
			int idI = 0, idJ = 0;
			int min = a[0][0];
			for(int i=0; i<n; i++){
				for(int j=0; j<n; j++){
					if(a[i][j] < min){
						min = a[i][j];
						idI = i;
						idJ = j;
					}
				}
			}
			cout << "\nPhan tu co gia tri nho nhat la phan thu a[" << idI << "][" << idJ << "] = " << min;
		}
		
		void doiXung(){
			bool laDoiXung = true;
			for(int i=0; i<n; i++){
				for(int j=0; j<n; j++){
					if(a[i][j] != a[j][i]){
						laDoiXung = false;
						break;
					}
				}
			}
			
			if(laDoiXung) 	cout << "\nDoi xung";
			else			cout << "\nKhong doi xung";
		}
};



int main(){
	MaTran A, B;
	cin >> A >> B;
	cout << "\nMa tran A : " << endl << A << "\nMa tran B :" << endl << B;
	
	cout << "\nTong A + B = " << endl << A+B;
	
	cout << "\nTong duong cheo chinh cua ma tran A la:" << A.tongDuongCheoChinh();
	
	A.nhoNhat();
	
	A.doiXung();
	
	return 0;
}
