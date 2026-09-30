#include <iostream>
#include "myVector.h"
using namespace std;

void printVector(Vector<double> &v) {
    cout << "Vector: ";
    for (Vector<double>::iterator it = v.begin(); it != v.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}

int main() {
    Vector<double> v;

    v.push_back(1.5);
    v.push_back(3.2);
    v.push_back(7.8);
    cout << "Khoi tao ban dau:\n";
    printVector(v);

    cout << "\n1. Chen 4.6 vao index 1:\n";
    v.insert(1, 4.6);
    printVector(v);

    cout << "\n2. Xoa phan tu o index 2:\n";
    v.erase(2);
    printVector(v);

    cout << "\n3. Thay the index 0 thanh 9.9:\n";
    v[0] = 9.9;
    printVector(v);

    int k = 1;
    cout << "\n4. Gia tri tai index " << k 
         << " la: " << v[k] << "\n";

    cout << "\n5. In nguoc bang reverse_iterator:\n";
    for (Vector<double>::reverse_iterator it = v.rbegin(); 
         it != v.rend(); it++) {
        cout << *it << " ";
    }
    cout << "\n";

    return 0;
}
