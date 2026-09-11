#include<iostream>
using namespace std;

template <typename T>
T timmax(T a, T b){
	return (a > b) ? a : b;
}

int main(){
	int x = 5, y = 10;
	cout << "\nMax = " << timmax(x,y);
	
	float z = 10.5, t = -5.5;
	cout << "\nMax = " << timmax(z,t);
	
	return 0;
}
