#include<iostream>
using namespace std;

int main(){
	int a, b ,c;
	cin >> a >> b >> c;
	
	if(a*a + b*b == c*c || a*a + c*c == b*b || b*b + c*c == a*a){
		cout << "\nLa tam giac vuong";
	}
	else	cout << "\nKhong phai tam giac vuong";
	
	return 0;
}
