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

void inTieuDe(ostream &os) {
    os << left << setw(20) << "Tu tieng Anh" << "Nghia tieng Viet" << endl;
}

// 1. Doc du lieu tu dien nap vao cay tu file
void docFile(BST<TuDien> &cay, string tenFile) {
    ifstream fin(tenFile);
    if (!fin.is_open()) {
        fin.open("Bai_Tap_Ve_Nha/VII/" + tenFile);
    }
    if (!fin.is_open()) {
        cout << "Khong the mo file " << tenFile << endl;
        return;
    }

    int soLuong = 0;
    fin >> soLuong;
    fin.ignore();

    for (int i = 0; i < soLuong; i++) {
        string line;
        if (!getline(fin, line)) break;
        if (line.empty()) {
            i--;
            continue;
        }

        size_t viTri = line.find(';');
        if (viTri != string::npos) {
            string tu = line.substr(0, viTri);
            string nghia = line.substr(viTri + 1);

            while (!tu.empty() && (tu.back() == ' ' || tu.back() == '\r')) tu.pop_back();
            while (!tu.empty() && tu.front() == ' ') tu.erase(0, 1);
            while (!nghia.empty() && (nghia.back() == ' ' || nghia.back() == '\r')) nghia.pop_back();
            while (!nghia.empty() && nghia.front() == ' ') nghia.erase(0, 1);

            cay.insert(TuDien(tu, nghia));
        }
    }

    fin.close();
    cout << "Da doc thanh cong " << soLuong << " tu tu file " << tenFile << endl;
}

// 2. Bo sung tu moi vao cay
void boSungTu(BST<TuDien> &cay) {
    string tu, nghia;
    cout << "Nhap tu tieng Anh: ";
    getline(cin, tu);
    cout << "Nhap nghia tieng Viet: ";
    getline(cin, nghia);

    TuDien canThem(tu, "");
    if (cay.contains(canThem)) {
        cout << "Tu \"" << tu << "\" da ton tai trong tu dien" << endl;
    } else {
        cay.insert(TuDien(tu, nghia));
        cout << "Them tu \"" << tu << "\" thanh cong" << endl;
    }
}

// 3. Xoa bo mot tu khoi cay
void xoaTu(BST<TuDien> &cay) {
    string tu;
    cout << "Nhap tu can xoa: ";
    getline(cin, tu);

    TuDien canXoa(tu, "");
    if (!cay.contains(canXoa)) {
        cout << "Khong tim thay tu \"" << tu << "\" de xoa" << endl;
    } else {
        cay.erase(canXoa);
        cout << "Xoa tu \"" << tu << "\" thanh cong" << endl;
    }
}

// 4. Tim kiem tu trong tu dien
void timKiemTu(BST<TuDien> &cay) {
    string tu;
    cout << "Nhap tu can tim: ";
    getline(cin, tu);

    TuDien canTim(tu, "");
    BSTNode<TuDien> *node = cay.find(canTim);

    if (node != nullptr) {
        cout << "Tim thay: " << node->data.getTu() << " -> " << node->data.getNghia() << endl;
    } else {
        cout << "Khong tim thay tu \"" << tu << "\" trong tu dien" << endl;
    }
}

// 5. Luu cay vao file
void ghiFileDeQuy(BSTNode<TuDien> *node, ofstream &fout) {
    if (node == nullptr) return;
    fout << node->data.getTu() << " ; " << node->data.getNghia() << endl;
    ghiFileDeQuy(node->left, fout);
    ghiFileDeQuy(node->right, fout);
}

void ghiFile(BST<TuDien> &cay, string tenFile) {
    ofstream fout(tenFile);
    if (!fout.is_open()) {
        fout.open("Bai_Tap_Ve_Nha/VII/" + tenFile);
    }
    if (!fout.is_open()) {
        cout << "Khong the mo file " << tenFile << " de ghi" << endl;
        return;
    }

    fout << cay.size() << endl;
    ghiFileDeQuy(cay.getRoot(), fout);
    fout.close();
    cout << "Da ghi thanh cong toan bo tu dien vao file " << tenFile << endl;
}

// Hien thi toan bo tu dien theo thu tu In-order (A -> Z)
void inOrderTuDien(BSTNode<TuDien> *node, ostream &os) {
    if (node == nullptr) return;
    inOrderTuDien(node->left, os);
    os << node->data << endl;
    inOrderTuDien(node->right, os);
}

void hienThiDanhSach(BST<TuDien> &cay, ostream &os) {
    if (cay.empty()) {
        os << "Tu dien hien dang rong" << endl;
        return;
    }
    inTieuDe(os);
    inOrderTuDien(cay.getRoot(), os);
}

int main() {
    BST<TuDien> tuDien(compare_TuDien);
    int chon;

    do {
        cout << "\nCHUONG TRINH TRA CUU TU DIEN\n";
        cout << "1. Doc du lieu tu dien nap vao cay tu file\n";
        cout << "2. Bo sung tu moi vao cay\n";
        cout << "3. Xoa bo mot tu khoi cay\n";
        cout << "4. Tim kiem tu\n";
        cout << "5. Luu cay vao file\n";
        cout << "6. Hien thi toan bo tu dien theo thu tu tu dien\n";
        cout << "0. Thoat\n";
        cout << "Nhap lua chon: ";
        cin >> chon;
        cin.ignore();

        switch (chon) {
            case 1: {
                string tenFile;
                cout << "Nhap ten file (an Enter de dung tudien.txt): ";
                getline(cin, tenFile);
                if (tenFile.empty()) tenFile = "tudien.txt";
                docFile(tuDien, tenFile);
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
                string tenFile;
                cout << "Nhap ten file de luu (an Enter de dung tudien_out.txt): ";
                getline(cin, tenFile);
                if (tenFile.empty()) tenFile = "tudien_out.txt";
                ghiFile(tuDien, tenFile);
                break;
            }
            case 6:
                hienThiDanhSach(tuDien, cout);
                break;
            case 0:
                cout << "Ket thuc chuong trinh tra cuu tu dien" << endl;
                break;
            default:
                cout << "Lua chon khong hop le, vui long chon lai" << endl;
                break;
        }
    } while (chon != 0);

    return 0;
}
