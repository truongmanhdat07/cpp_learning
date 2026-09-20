#ifndef MY_LIST_H
#define MY_LIST_H

#include <iostream>

struct node {
    int data;
    node *next;
};

node* makeNode(int value) {
    node* temp = new node;
    temp->data = value;
    temp->next = nullptr;
    return temp;
}

bool empty(node *head) {
    return head == nullptr;
}

int size(node *head) {
    int count = 0;
    node* current = head;
    while (current != nullptr) {
        count++;
        current = current->next;
    }
    return count;
}

void push_front(node* &head, int value) {
    node* newNode = makeNode(value);
    newNode->next = head;
    head = newNode;
}

void push_back(node* &head, int value) {
    node* newNode = makeNode(value);
    if (head == nullptr) {
        head = newNode;
        return;
    }
    node* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }
    current->next = newNode;
}

void pop_front(node* &head) {
    if (head == nullptr) return;
    node* temp = head;
    head = head->next;
    delete temp;
}

void pop_back(node* &head) {
    if (head == nullptr) return;
    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }
    node* current = head;
    while (current->next->next != nullptr) {
        current = current->next;
    }
    node* temp = current->next;
    current->next = nullptr;
    delete temp;
}

void insert(node* &head, int value, int k) {
    int n = size(head);
    if (k < 1 || k > n + 1) return;
    if (k == 1) {
        push_front(head, value);
        return;
    }
    if (k == n + 1) {
        push_back(head, value);
        return;
    }
    node* current = head;
    for (int i = 1; i < k - 1; ++i) {
        current = current->next;
    }
    node* newNode = makeNode(value);
    newNode->next = current->next;
    current->next = newNode;
}

void erase(node* &head, int k) {
    int n = size(head);
    if (k < 1 || k > n) return;
    if (k == 1) {
        pop_front(head);
        return;
    }
    node* current = head;
    for (int i = 1; i < k - 1; ++i) {
        current = current->next;
    }
    node* temp = current->next;
    current->next = temp->next;
    delete temp;
}

int front(node* head) {
    if (head == nullptr) return -1;
    return head->data;
}

int back(node* head) {
    if (head == nullptr) return -1;
    node* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }
    return current->data;
}

void print(node* head) {
    node* current = head;
    while (current != nullptr) {
        std::cout << current->data << " -> ";
        current = current->next;
    }
    std::cout << "nullptr\n";
}

void clear(node* &head) {
    node* current = head;
    while (current != nullptr) {
        node* nextNode = current->next;
        delete current;
        current = nextNode;
    }
    head = nullptr;
}

#endif
