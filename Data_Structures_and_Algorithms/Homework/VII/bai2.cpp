#include <iostream>
#include <string>
#include "BST.h"

using namespace std;

// Ham so sanh chuoi theo thu tu tu dien tang dan
int compare_StringTang(string a, string b) {
    if (a < b) return 1;
    return 0;
}

// Ham so sanh so nguyen tang dan
int compare_IntTang(int a, int b) {
    if (a < b) return 1;
    return 0;
}

int main() {
    // 1. Khoi tao cay BST voi kieu int va ham so sanh compare_IntTang
    BST<int> treeInt(compare_IntTang);

    cout << "Them cac phan tu: 50, 30, 70, 20, 40, 60, 80 vao cay\n";
    treeInt.insert(50);
    treeInt.insert(30);
    treeInt.insert(70);
    treeInt.insert(20);
    treeInt.insert(40);
    treeInt.insert(60);
    treeInt.insert(80);

    cout << "\nDuyet cay theo thu tu giua (In-order tang dan):\n";
    treeInt.in_order();

    cout << "\nDuyet cay theo thu tu truoc (Pre-order):\n";
    treeInt.pre_order();

    cout << "\nDuyet cay theo thu tu sau (Post-order):\n";
    treeInt.post_order();

    int khoaTim = 40;
    cout << "\nTim kiem gia tri " << khoaTim << " tren cay:\n";
    if (treeInt.contains(khoaTim)) {
        cout << "Gia tri " << khoaTim << " co ton tai tren cay\n";
    } else {
        cout << "Gia tri " << khoaTim << " khong ton tai tren cay\n";
    }

    int khoaXoa = 30;
    cout << "\nXoa nut co gia tri " << khoaXoa << " khoi cay\n";
    treeInt.erase(khoaXoa);

    cout << "Duyet In-order sau khi xoa " << khoaXoa << ":\n";
    treeInt.in_order();

    // 2. Thu nghiem voi kieu chuoi string va ham so sanh compare_StringTang
    cout << "\nThu nghiem cay BST voi kieu string:\n";
    BST<string> treeStr(compare_StringTang);

    treeStr.insert("banana");
    treeStr.insert("apple");
    treeStr.insert("orange");
    treeStr.insert("mango");
    treeStr.insert("grape");

    cout << "Duyet In-order cay string (theo thu tu tu dien):\n";
    treeStr.in_order();

    string tuTim = "mango";
    cout << "Tim kiem tu \"" << tuTim << "\":\n";
    if (treeStr.contains(tuTim)) {
        cout << "Tim thay tu \"" << tuTim << "\" tren cay\n";
    } else {
        cout << "Khong tim thay tu \"" << tuTim << "\" tren cay\n";
    }

    return 0;
}
