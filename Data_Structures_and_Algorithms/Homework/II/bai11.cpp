#include <iostream>

using namespace std;

template <typename T>
class Vector {
    private:
        int n;
        T *v;
    public:
        Vector(int n = 0);
        Vector(const Vector<T> &other);
        ~Vector();

        Vector<T>& operator=(const Vector<T> &other);
        Vector<T> operator+(const Vector<T> &other);
        Vector<T> operator-(const Vector<T> &other);
        T operator*(const Vector<T> &other);
        Vector<T> operator-();

        template <typename U>
        friend istream& operator>>(istream &in, Vector<U> &vector);

        template <typename U>
        friend ostream& operator<<(ostream &out, const Vector<U> &vector);
};

template <typename T>
Vector<T>::Vector(int n) {
    this->n = n;
    if (n > 0) {
        v = new T[n];
        for (int i = 0; i < n; i++) {
            v[i] = 0;
        }
    } else {
        v = nullptr;
    }
}

template <typename T>
Vector<T>::Vector(const Vector<T> &other) {
    n = other.n;
    if (n > 0) {
        v = new T[n];
        for (int i = 0; i < n; i++) {
            v[i] = other.v[i];
        }
    } else {
        v = nullptr;
    }
}

template <typename T>
Vector<T>::~Vector() {
    if (v != nullptr) {
        delete[] v;
    }
}

template <typename T>
Vector<T>& Vector<T>::operator=(const Vector<T> &other) {
    if (this != &other) {
        if (v != nullptr) {
            delete[] v;
        }
        n = other.n;
        if (n > 0) {
            v = new T[n];
            for (int i = 0; i < n; i++) {
                v[i] = other.v[i];
            }
        } else {
            v = nullptr;
        }
    }
    return *this;
}

template <typename T>
Vector<T> Vector<T>::operator+(const Vector<T> &other) {
    Vector<T> result(n);
    for (int i = 0; i < n; i++) {
        result.v[i] = v[i] + other.v[i];
    }
    return result;
}

template <typename T>
Vector<T> Vector<T>::operator-(const Vector<T> &other) {
    Vector<T> result(n);
    for (int i = 0; i < n; i++) {
        result.v[i] = v[i] - other.v[i];
    }
    return result;
}

template <typename T>
T Vector<T>::operator*(const Vector<T> &other) {
    T sum = 0;
    for (int i = 0; i < n; i++) {
        sum += v[i] * other.v[i];
    }
    return sum;
}

template <typename T>
Vector<T> Vector<T>::operator-() {
    Vector<T> result(n);
    for (int i = 0; i < n; i++) {
        result.v[i] = -v[i];
    }
    return result;
}

template <typename U>
istream& operator>>(istream &in, Vector<U> &vector) {
    for (int i = 0; i < vector.n; i++) {
        in >> vector.v[i];
    }
    return in;
}

template <typename U>
ostream& operator<<(ostream &out, const Vector<U> &vector) {
    out << "(";
    for (int i = 0; i < vector.n; i++) {
        out << vector.v[i];
        if (i < vector.n - 1) {
            out << ", ";
        }
    }
    out << ")";
    return out;
}

int main() {
    int n;
    cout << "Nhap so chieu n: ";
    cin >> n;

    Vector<float> v1(n), v2(n);

    cout << "Nhap toa do vector 1:\n";
    cin >> v1;
    cout << "Nhap toa do vector 2:\n";
    cin >> v2;

    cout << "\nVector 1: " << v1 << endl;
    cout << "Vector 2: " << v2 << endl;

    cout << "\nTong (v1 + v2) = " << v1 + v2 << endl;
    cout << "Hieu (v1 - v2) = " << v1 - v2 << endl;
    cout << "Tich vo huong (v1 * v2) = " << v1 * v2 << endl;
    cout << "Doi dau v1 (-v1) = " << -v1 << endl;

    return 0;
}
