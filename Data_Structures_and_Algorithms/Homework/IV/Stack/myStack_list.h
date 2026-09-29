#ifndef STACK_H
#define STACK_H

#include <iostream>
using namespace std;

template <typename T>
struct Node {
    T data;
    Node<T> *next;

    Node(T val) {
        data = val;
        next = nullptr;
    }
};

template <typename T>
class Stack {
    private:
        Node<T> *head;
        int num;

    public:
        Stack() {
            head = nullptr;
            num = 0;
        }

        Stack(const Stack<T> &S) {
            head = nullptr;
            num = 0;
            if (S.head == nullptr) return;

            head = new Node<T>(S.head->data);
            Node<T> *current = head;
            Node<T> *src = S.head->next;
            while (src != nullptr) {
                current->next = new Node<T>(src->data);
                current = current->next;
                src = src->next;
            }
            num = S.num;
        }

        Stack<T>& operator=(const Stack<T> &S) {
            if (this != &S) {
                clear();
                if (S.head != nullptr) {
                    head = new Node<T>(S.head->data);
                    Node<T> *current = head;
                    Node<T> *src = S.head->next;
                    while (src != nullptr) {
                        current->next = new Node<T>(src->data);
                        current = current->next;
                        src = src->next;
                    }
                    num = S.num;
                }
            }
            return *this;
        }

        ~Stack() {
            clear();
        }

        bool empty() const {
            return head == nullptr;
        }

        int size() const {
            return num;
        }

        void push(T value) {
            Node<T> *newNode = new Node<T>(value);
            newNode->next = head;
            head = newNode;
            num++;
        }

        void pop() {
            if (head == nullptr) return;
            Node<T> *temp = head;
            head = head->next;
            delete temp;
            num--;
        }

        T& top() {
            return head->data;
        }

        void clear() {
            Node<T> *current = head;
            while (current != nullptr) {
                Node<T> *nextNode = current->next;
                delete current;
                current = nextNode;
            }
            head = nullptr;
            num = 0;
        }
};

#endif
