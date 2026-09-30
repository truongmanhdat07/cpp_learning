#ifndef __VECTOR_HPP__
#define __VECTOR_HPP__

#include <iostream>


template <class T>
class vector_reverse_iterator {
    private:
        T *curr;

    public:
        vector_reverse_iterator(T *c = nullptr) { 
            curr = c; 
        }

        vector_reverse_iterator<T>& operator++() {
            curr--;
            return *this;
        }

        vector_reverse_iterator<T> operator++(int) {
            vector_reverse_iterator<T> temp = *this;
            curr--;
            return temp;
        }

        vector_reverse_iterator<T>& operator--() {
            curr++;
            return *this;
        }

        vector_reverse_iterator<T> operator--(int) {
            vector_reverse_iterator<T> temp = *this;
            curr++;
            return temp;
        }

        T& operator*() { 
            return *curr; 
        }

        T* operator->() {
            return curr;
        }

        bool operator==(const vector_reverse_iterator<T> &t) const { 
            return curr == t.curr; 
        }

        bool operator!=(const vector_reverse_iterator<T> &t) const { 
            return curr != t.curr; 
        }
};


template <class T>
class Vector {
    private:
        int cap, num;
        T *buff;

    public:
        Vector() {
            cap = num = 0;
            buff = nullptr;
        }

        Vector(int k, T x = T()) {
            cap = num = k;
            buff = (k > 0) ? new T[k] : nullptr;
            for (int i = 0; i < k; i++) buff[i] = x;
        }

        Vector(const Vector<T> &V) {
            cap = V.cap;
            num = V.num;
            buff = (cap > 0) ? new T[cap] : nullptr;
            for (int i = 0; i < num; i++) buff[i] = V.buff[i];
        }

        Vector<T>& operator=(const Vector<T> &V) {
            if (this != &V) {
                if (buff) delete[] buff;
                cap = V.cap;
                num = V.num;
                buff = (cap > 0) ? new T[cap] : nullptr;
                for (int i = 0; i < num; i++) buff[i] = V.buff[i];
            }
            return *this;
        }

        ~Vector() {
            if (buff) delete[] buff;
        }

        int capacity() const { return cap; }
        int size() const { return num; }
        bool empty() const { return num == 0; }
        void clear() { num = 0; }

        void extend(int newcap) {
            if (newcap <= cap) return;
            cap = newcap;
            T *temp = new T[cap];
            for (int i = 0; i < num; i++) temp[i] = buff[i];
            if (buff) delete[] buff;
            buff = temp;
        }

        void push_back(T x) {
            if (num == cap) extend(cap * 2 + 5);
            buff[num++] = x;
        }

        void pop_back() {
            if (num > 0) num--;
        }

        T& back() { return buff[num - 1]; }
        T& front() { return buff[0]; }
        T& operator[](int k) { return buff[k]; }

        void insert(int k, T x) {
            if (k < 0 || k > num) return;
            if (num == cap) extend(cap * 2 + 5);
            for (int i = num - 1; i >= k; i--) buff[i + 1] = buff[i];
            buff[k] = x;
            num++;
        }

        void erase(int k) {
            if (k < 0 || k >= num) return;
            for (int i = k; i < num - 1; i++) buff[i] = buff[i + 1];
            num--;
        }

        typedef T* iterator;
        iterator begin() { return buff; }
        iterator end()   { return buff + num; }

        typedef vector_reverse_iterator<T> reverse_iterator;
        reverse_iterator rbegin() { return reverse_iterator(buff + num - 1); }
        reverse_iterator rend()   { return reverse_iterator(buff - 1); }
};

#endif
