#ifndef __STACK_HPP__
#define __STACK_HPP__

#include <iostream>

template <class T>
class Stack {
    private:
        int cap, num;
        T *buff;

        void extend(int newcap) {
            if (newcap <= cap) return;
            cap = newcap;
            T *temp = new T[cap];
            for (int i = 0; i < num; i++) temp[i] = buff[i];
            if (buff) delete[] buff;
            buff = temp;
        }

    public:
        Stack() {
            cap = num = 0;
            buff = nullptr;
        }

        Stack(const Stack<T> &S) {
            cap = S.cap;
            num = S.num;
            buff = (cap > 0) ? new T[cap] : nullptr;
            for (int i = 0; i < num; i++) buff[i] = S.buff[i];
        }

        Stack<T>& operator=(const Stack<T> &S) {
            if (this != &S) {
                if (buff) delete[] buff;
                cap = S.cap;
                num = S.num;
                buff = (cap > 0) ? new T[cap] : nullptr;
                for (int i = 0; i < num; i++) buff[i] = S.buff[i];
            }
            return *this;
        }

        ~Stack() {
            if (buff) delete[] buff;
        }

        int size() const { return num; }
        int capacity() const { return cap; }
        bool empty() const { return num == 0; }
        void clear() { num = 0; }

        void push(T x) {
		    if (num == cap) extend(cap * 2 + 5);
		    buff[num++] = x;
		}

        void pop() {
            if (num > 0) num--;
        }

        T& top() {
            return buff[num - 1];
        }
};

#endif
