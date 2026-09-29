#ifndef QUEUE_H
#define QUEUE_H

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
class Queue {
    private:
        Node<T> *head;
        Node<T> *tail;
        int num;

    public:
        Queue() {
            head = nullptr;
            tail = nullptr;
            num = 0;
        }

        ~Queue() {
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
            if (head == nullptr) {
                head = tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }
            num++;
        }

        void pop() {
            if (head == nullptr) return;
            Node<T> *temp = head;
            head = head->next;
            delete temp;
            num--;
            if (head == nullptr) {
                tail = nullptr;
            }
        }

        T& front() {
            return head->data;
        }

        T& back() {
            return tail->data;
        }

        void clear() {
            Node<T> *current = head;
            while (current != nullptr) {
                Node<T> *nextNode = current->next;
                delete current;
                current = nextNode;
            }
            head = tail = nullptr;
            num = 0;
        }
};

#endif
