#ifndef DOUBLE_LIST_H
#define DOUBLE_LIST_H

#include <iostream>
using namespace std;

template <typename T>
struct DblNode {
    T data;
    DblNode<T> *prev;
    DblNode<T> *next;

    DblNode(T val) {
        data = val;
        prev = nullptr;
        next = nullptr;
    }
};

template <typename T>
class DoubleList {
    private:
        DblNode<T> *head;
        DblNode<T> *tail;
        int num;

    public:
        class iterator {
            private:
                DblNode<T> *current;
            public:
                iterator(DblNode<T> *p = nullptr) : current(p) {}

                T& operator*() {
                    return current->data;
                }

                T* operator->() {
                    return &(current->data);
                }

                iterator& operator++() {
                    if (current != nullptr) current = current->next;
                    return *this;
                }

                iterator operator++(int) {
                    iterator temp = *this;
                    if (current != nullptr) current = current->next;
                    return temp;
                }

                iterator& operator--() {
                    if (current != nullptr) current = current->prev;
                    return *this;
                }

                iterator operator--(int) {
                    iterator temp = *this;
                    if (current != nullptr) current = current->prev;
                    return temp;
                }

                bool operator!=(const iterator &other) const {
                    return current != other.current;
                }

                bool operator==(const iterator &other) const {
                    return current == other.current;
                }
        };

        class reverse_iterator {
            private:
                DblNode<T> *current;
            public:
                reverse_iterator(DblNode<T> *p = nullptr) : current(p) {}

                T& operator*() {
                    return current->data;
                }

                T* operator->() {
                    return &(current->data);
                }

                reverse_iterator& operator++() {
                    if (current != nullptr) current = current->prev;
                    return *this;
                }

                reverse_iterator operator++(int) {
                    reverse_iterator temp = *this;
                    if (current != nullptr) current = current->prev;
                    return temp;
                }

                bool operator!=(const reverse_iterator &other) const {
                    return current != other.current;
                }

                bool operator==(const reverse_iterator &other) const {
                    return current == other.current;
                }
        };

        DoubleList() {
            head = nullptr;
            tail = nullptr;
            num = 0;
        }

        ~DoubleList() {
            clear();
        }

        bool empty() const {
            return head == nullptr;
        }

        int size() const {
            return num;
        }

        void push_front(T value) {
            DblNode<T> *newNode = new DblNode<T>(value);
            if (head == nullptr) {
                head = tail = newNode;
            } 
			else {
                newNode->next = head;
                head->prev = newNode;
                head = newNode;
            }
            num++;
        }

        void push_back(T value) {
            DblNode<T> *newNode = new DblNode<T>(value);
            if (head == nullptr) {
                head = tail = newNode;
            } 
			else {
                tail->next = newNode;
                newNode->prev = tail;
                tail = newNode;
            }
            num++;
        }

        void pop_front() {
            if (head == nullptr) return;
            DblNode<T> *temp = head;
            if (head == tail) {
                head = tail = nullptr;
            } 
			else {
                head = head->next;
                head->prev = nullptr;
            }
            delete temp;
            num--;
        }

        void pop_back() {
            if (tail == nullptr) return;
            DblNode<T> *temp = tail;
            if (head == tail) {
                head = tail = nullptr;
            } 
			else {
                tail = tail->prev;
                tail->next = nullptr;
            }
            delete temp;
            num--;
        }

        void insert(int k, T value) {
            if (k < 1 || k > num + 1) return;
            if (k == 1) {
                push_front(value);
                return;
            }
            if (k == num + 1) {
                push_back(value);
                return;
            }

            DblNode<T> *current = head;
            for (int i = 1; i < k - 1; ++i) {
                current = current->next;
            }
            DblNode<T> *newNode = new DblNode<T>(value);
            newNode->next = current->next;
            newNode->prev = current;
            current->next->prev = newNode;
            current->next = newNode;
            num++;
        }

        void erase(int k) {
            if (k < 1 || k > num) return;
            if (k == 1) {
                pop_front();
                return;
            }
            if (k == num) {
                pop_back();
                return;
            }

            DblNode<T> *current = head;
            for (int i = 1; i < k - 1; ++i) {
                current = current->next;
            }
            DblNode<T> *temp = current->next;
            current->next = temp->next;
            temp->next->prev = current;
            delete temp;
            num--;
        }

        T& front() {
            return head->data;
        }

        T& back() {
            return tail->data;
        }

        void clear() {
            DblNode<T> *current = head;
            while (current != nullptr) {
                DblNode<T> *nextNode = current->next;
                delete current;
                current = nextNode;
            }
            head = tail = nullptr;
            num = 0;
        }

        void print() const {
            DblNode<T> *current = head;
            while (current != nullptr) {
                cout << current->data << " <-> ";
                current = current->next;
            }
            cout << "nullptr\n";
        }

        iterator begin() { 
            return iterator(head); 
        }

        iterator end() { 
            return iterator(nullptr); 
        }

        reverse_iterator rbegin() { 
            return reverse_iterator(tail); 
        }

        reverse_iterator rend() { 
            return reverse_iterator(nullptr); 
        }
};

#endif
