#include <iostream>
#include <string>
#include <cctype>
#include "myStack_list.h"

using namespace std;

int doUuTien(char toanTu) {
    if (toanTu == '+' || toanTu == '-') return 1;
    if (toanTu == '*' || toanTu == '/') return 2;
    return 0;
}

double tinhToan(double so1, double so2, char toanTu) {
    switch (toanTu) {
        case '+': return so1 + so2;
        case '-': return so1 - so2;
        case '*': return so1 * so2;
        case '/': return so1 / so2;
    }
    return 0;
}

double tinhBieuThuc(string bieuThuc) {
    Stack<double> nganXepSo;
    Stack<char> nganXepToanTu;

    for (int i = 0; i < bieuThuc.length(); i++) {
        if (bieuThuc[i] == ' ') continue;

        if (isdigit(bieuThuc[i])) {
            double giaTri = 0;
            while (i < bieuThuc.length() && isdigit(bieuThuc[i])) {
                giaTri = giaTri * 10 + (bieuThuc[i] - '0');
                i++;
            }
            if (i < bieuThuc.length() && bieuThuc[i] == '.') {
                i++;
                double heSo = 0.1;
                while (i < bieuThuc.length() && isdigit(bieuThuc[i])) {
                    giaTri += (bieuThuc[i] - '0') * heSo;
                    heSo /= 10;
                    i++;
                }
            }
            i--; 
            nganXepSo.push(giaTri);
        }
        else if (bieuThuc[i] == '(') {
            nganXepToanTu.push(bieuThuc[i]);
        }
        else if (bieuThuc[i] == ')') {
            while (!nganXepToanTu.empty() && nganXepToanTu.top() != '(') {
                double so2 = nganXepSo.top(); nganXepSo.pop();
                double so1 = nganXepSo.top(); nganXepSo.pop();
                char toanTu = nganXepToanTu.top(); nganXepToanTu.pop();

                nganXepSo.push(tinhToan(so1, so2, toanTu));
            }
            if (!nganXepToanTu.empty()) nganXepToanTu.pop(); 
        }
        else if (bieuThuc[i] == '+' || bieuThuc[i] == '-' || bieuThuc[i] == '*' || bieuThuc[i] == '/') {
            while (!nganXepToanTu.empty() && doUuTien(nganXepToanTu.top()) >= doUuTien(bieuThuc[i])) {
                double so2 = nganXepSo.top(); nganXepSo.pop();
                double so1 = nganXepSo.top(); nganXepSo.pop();
                char toanTu = nganXepToanTu.top(); nganXepToanTu.pop();

                nganXepSo.push(tinhToan(so1, so2, toanTu));
            }
            nganXepToanTu.push(bieuThuc[i]);
        }
    }

    while (!nganXepToanTu.empty()) {
        double so2 = nganXepSo.top(); nganXepSo.pop();
        double so1 = nganXepSo.top(); nganXepSo.pop();
        char toanTu = nganXepToanTu.top(); nganXepToanTu.pop();

        nganXepSo.push(tinhToan(so1, so2, toanTu));
    }

    return nganXepSo.top();
}

int main() {
    string bieuThuc;
    cout << "Nhap bieu thuc trung to: ";
    getline(cin, bieuThuc);

    double ketQua = tinhBieuThuc(bieuThuc);
    cout << "Gia tri bieu thuc = " << ketQua << endl;

    return 0;
}
