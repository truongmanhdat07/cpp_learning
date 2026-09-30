#include <iostream>
#include "myQueue_list.h"

using namespace std;

int main(){
	Queue<int> ds;
	cout << "1." << endl;
	cout << "Nhap phan tu can them vao danh sach:";
	int n;	cin >> n;	ds.push(n);
	
	cout << "2." << endl;
	cout << "Phan tu vua them vao la:" << ds.front() << endl;	ds.pop();
	
	cout << "3." << endl;
	cout << "So phan tu hien co la:" << ds.size() << endl;
	
	cout << "4." << endl;
	if(ds.empty())	cout << "Danh sach dang rong!";
	else			cout << "Danh sach dang khong rong!";
	
	return 0;
}
