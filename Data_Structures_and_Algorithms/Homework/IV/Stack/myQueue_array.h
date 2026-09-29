#ifndef __QUEUE_HPP__
#define __QUEUE_HPP__

#include <iostream>

template <class T>
class Queue {
    private:
        int cap, num;
        int head;
        T *buff;

        void extend(int newcap) {
            if (newcap <= cap) return;
            cap = newcap;
            T *temp = new T[cap];
            
            for (int i = 0; i < num; i++) {
                temp[i] = buff[(head + i) % (cap == newcap ? (num == 0 ? 1 : num) : (cap))]; 
            }
        }

    public:
        Queue() {
            cap = num = head = 0;
            buff = nullptr;
        }

        Queue(const Queue<T> &Q) {
            cap = Q.cap;
            num = Q.num;
            head = 0;
            buff = (cap > 0) ? new T[cap] : nullptr;
            for (int i = 0; i < num; i++) {
                buff[i] = Q.buff[(Q.head + i) % Q.cap];
            }
        }

        Queue<T>& operator=(const Queue<T> &Q) {
            if (this != &Q) {
                if (buff) delete[] buff;
                cap = Q.cap;
                num = Q.num;
                head = 0;
                buff = (cap > 0) ? new T[cap] : nullptr;
                for (int i = 0; i < num; i++) {
                    buff[i] = Q.buff[(Q.head + i) % Q.cap];
                }
            }
            return *this;
        }

        ~Queue() {
            if (buff) delete[] buff;
        }

        int size() const { return num; }
        int capacity() const { return cap; }
        bool empty() const { return num == 0; }
        
        void clear() {
            num = 0;
            head = 0;
        }

        void push(T x) {
            if (num == cap) {
                int newcap = cap * 2 + 5;
                T *temp = new T[newcap];
                for (int i = 0; i < num; i++) {
                    temp[i] = buff[(head + i) % cap];
                }
                if (buff) delete[] buff;
                buff = temp;
                head = 0;
                cap = newcap;
            }

            buff[(head + num) % cap] = x;
            num++;
        }

        void pop() {
            if (num > 0) {
                head = (head + 1) % cap; 
                num--;
            }
        }

        T& front() {
            return buff[head];
        }

        T& back() {
            return buff[(head + num - 1) % cap];
        }
};

#endif
