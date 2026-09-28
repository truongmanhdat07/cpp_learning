#include<iostream>
#include<string>

using namespace std;

int main(){
	string chuoi;	getline(cin, chuoi);
	string hoa = chuoi, thuong = chuoi;
	
	for(int i=0; i<chuoi.length(); i++){
		if(thuong[i] >= 'a' && thuong[i] <= 'z')	thuong[i] -= 32;
		if(hoa[i] >= 'A' && hoa[i] <= 'Z')			hoa[i] += 32;
	}
	
	cout << hoa << "   " << thuong << endl;
	
	return 0;
}
