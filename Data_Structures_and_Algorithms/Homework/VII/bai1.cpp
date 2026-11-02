#include <iostream>
#include "../VI/bai2.h"

using namespace std;

// Thuat toan tim kiem nhi phan tong quat tren mang da sap xep theo ham so sanh comp
template <typename T>
int binarySearch(T a[], int n, T x, int (*comp)(T, T)) {
    int left = 0;
    int right = n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (a[mid] == x) {
            return mid;
        }

        // Neu a[mid] dung truoc x theo quy tac comp thi tim tiep ben phai
        if (comp(a[mid], x)) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1; // Khong tim thay
}

// Ham so sanh tang dan
template <typename T>
int compare_Tang(T a, T b) {
    if (a < b) return 1;
    return 0;
}

// Ham so sanh giam dan
template <typename T>
int compare_Giam(T a, T b) {
    if (a > b) return 1;
    return 0;
}

int main() {
    int n;
    cout << "Nhap so luong phan tu n = ";
    cin >> n;

    if (n <= 0) {
        cout << "So luong phan tu khong hop le!\n";
        return 0;
    }

    float *a = new float[n];
    cout << "Nhap cac phan tu cua mang:\n";
    for (int i = 0; i < n; i++) {
        cout << "a[" << i << "] = ";
        cin >> a[i];
    }

    // Sap xep mang tang dan theo ham so sanh truoc khi tim kiem nhi phan
    QuickSort(a, n, compare_Tang);

    cout << "\nMang sau khi sap xep tang dan:\n";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    float x;
    cout << "\nNhap gia tri can tim x = ";
    cin >> x;

    int viTri = binarySearch(a, n, x, compare_Tang);

    if (viTri != -1) {
        cout << "Tim thay " << x << " tai vi tri chi so: " << viTri << endl;
    } else {
        cout << "Khong tim thay " << x << " trong mang!\n";
    }

    delete[] a;
    return 0;
}
