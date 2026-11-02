#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "BST.h"

using namespace std;

class TuDien {
    private:
        string tu;
        string nghia;

    public:
        TuDien(string tu = "", string nghia = "") {
            this->tu = tu;
            this->nghia = nghia;
        }

        string getTu() { return tu; }
        string getNghia() { return nghia; }

        void setTu(string tu) { this->tu = tu; }
        void setNghia(string nghia) { this->nghia = nghia; }

        bool operator<(TuDien other) {
            return tu < other.tu;
        }

        bool operator==(TuDien other) {
            return tu == other.tu;
        }

        friend ostream& operator<<(ostream &os, TuDien td) {
            os << left << setw(20) << td.tu << td.nghia;
            return os;
        }
};

int compare_TuDien(TuDien a, TuDien b) {
    if (a.getTu() < b.getTu()) return 1;
    return 0;
}

void docTuTep(BST<TuDien> &cay, string tenTep) {
    ifstream fin(tenTep);
    if (!fin.is_open()) {
        fin.open("Bai_Tap_Ve_Nha/VII/" + tenTep);
    }
    if (!fin.is_open()) {
        cout << "Khong the mo tep " << tenTep << "\n";
        return;
    }

    string line;
    int dem = 0;
    while (getline(fin, line)) {
        if (line.empty()) continue;

        size_t pos = line.find(':');
        if (pos != string::npos) {
            string tu = line.substr(0, pos);
            string nghia = line.substr(pos + 1);

            while (!tu.empty() && tu.back() == ' ') tu.pop_back();
            while (!tu.empty() && tu.front() == ' ') tu.erase(0, 1);
            while (!nghia.empty() && nghia.front() == ' ') nghia.erase(0, 1);

            cay.insert(TuDien(tu, nghia));
            dem++;
        } else {
            string tu = line;
            string nghia = "";
            if (getline(fin, nghia)) {
                cay.insert(TuDien(tu, nghia));
                dem++;
            }
        }
    }

    fin.close();
    cout << "Da nap thanh cong " << dem << " tu tu tep " << tenTep << "\n";
}

void boSungTu(BST<TuDien> &cay) {
    string tu, nghia;
    cout << "Nhap tu tieng Anh: ";
    getline(cin, tu);
    cout << "Nhap nghia tieng Viet: ";
    getline(cin, nghia);

    TuDien canThem(tu, "");
    if (cay.contains(canThem)) {
        cout << "Tu \"" << tu << "\" da ton tai trong tu dien\n";
    } else {
        cay.insert(TuDien(tu, nghia));
        cout << "Da them tu \"" << tu << "\" thanh cong\n";
    }
}

void xoaTu(BST<TuDien> &cay) {
    string tu;
    cout << "Nhap tu can xoa: ";
    getline(cin, tu);

    TuDien canXoa(tu, "");
    if (!cay.contains(canXoa)) {
        cout << "Khong tim thay tu \"" << tu << "\" de xoa\n";
    } else {
        cay.erase(canXoa);
        cout << "Da xoa tu \"" << tu << "\" khoi tu dien thanh cong\n";
    }
}

void timKiemTu(BST<TuDien> &cay) {
    string tu;
    cout << "Nhap tu can tra cuu: ";
    getline(cin, tu);

    TuDien canTim(tu, "");
    BSTNode<TuDien> *found = cay.find(canTim);

    if (found != nullptr) {
        cout << "Nghia cua tu \"" << found->data.getTu() << "\": " << found->data.getNghia() << "\n";
    } else {
        cout << "Khong tim thay tu \"" << tu << "\" trong tu dien\n";
    }
}

void ghiNodeVaoTep(BSTNode<TuDien> *node, ofstream &fout) {
    if (node == nullptr) return;
    fout << node->data.getTu() << ": " << node->data.getNghia() << "\n";
    ghiNodeVaoTep(node->left, fout);
    ghiNodeVaoTep(node->right, fout);
}

void luuVaoTep(BST<TuDien> &cay, string tenTep) {
    ofstream fout(tenTep);
    if (!fout.is_open()) {
        cout << "Khong the tao tep " << tenTep << "\n";
        return;
    }

    ghiNodeVaoTep(cay.getRoot(), fout);
    fout.close();
    cout << "Da luu toan bo tu dien vao tep " << tenTep << " thanh cong\n";
}

void inOrderTuDien(BSTNode<TuDien> *node) {
    if (node == nullptr) return;
    inOrderTuDien(node->left);
    cout << node->data << "\n";
    inOrderTuDien(node->right);
}

void hienThiToanBo(BST<TuDien> &cay) {
    if (cay.empty()) {
        cout << "Tu dien hien dang rong\n";
        return;
    }
    cout << left << setw(20) << "Tu tieng Anh" << "Nghia tieng Viet" << "\n";
    inOrderTuDien(cay.getRoot());
}

int main() {
    BST<TuDien> tuDien(compare_TuDien);
    int chon;

    do {
        cout << "\nCHUONG TRINH TRA CUU TU DIEN\n";
        cout << "1. Doc du lieu tu dien nap vao cay tu tep\n";
        cout << "2. Bo sung tu moi vao cay\n";
        cout << "3. Xoa bo mot tu khoi cay\n";
        cout << "4. Tim kiem tu\n";
        cout << "5. Luu cay vao tep\n";
        cout << "6. Hien thi toan bo tu dien theo thu tu tu dien\n";
        cout << "0. Thoat\n";
        cout << "Nhap lua chon: ";
        cin >> chon;
        cin.ignore();

        switch (chon) {
            case 1: {
                string tenTep;
                cout << "Nhap ten tep (an Enter de dung tudien.txt): ";
                getline(cin, tenTep);
                if (tenTep.empty()) tenTep = "tudien.txt";
                docTuTep(tuDien, tenTep);
                break;
            }
            case 2:
                boSungTu(tuDien);
                break;
            case 3:
                xoaTu(tuDien);
                break;
            case 4:
                timKiemTu(tuDien);
                break;
            case 5: {
                string tenTep;
                cout << "Nhap ten tep de luu (an Enter de dung tudien_out.txt): ";
                getline(cin, tenTep);
                if (tenTep.empty()) tenTep = "tudien_out.txt";
                luuVaoTep(tuDien, tenTep);
                break;
            }
            case 6:
                hienThiToanBo(tuDien);
                break;
            case 0:
                cout << "Ket thuc chuong trinh tra cuu tu dien\n";
                break;
            default:
                cout << "Lua chon khong hop le, vui long chon lai\n";
                break;
        }
    } while (chon != 0);

    return 0;
}
