#ifndef SINGLE_LIST_H
#define SINGLE_LIST_H

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
class SingleList {
	private:
	    Node<T> *head;
	    int num; 
	public:
	    class iterator {
		    private:
		        Node<T> *current;
		    public:
		        iterator(Node<T> *p = nullptr) : current(p) {}
		
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
		
		        bool operator!=(const iterator &other) const { 
		            return current != other.current; 
		        }
		
		        bool operator==(const iterator &other) const { 
		            return current == other.current; 
		        }
	    };
	
	
	    SingleList() {
	        head = nullptr;
	        num = 0;
	    }
	
	    ~SingleList() {
	        clear();
	    }
	
	    bool empty() const {
	        return head == nullptr;
	    }
	
	    int size() const {
	        return num;
	    }
	
	    void push_front(T value) {
	        Node<T> *newNode = new Node<T>(value);
	        newNode->next = head;
	        head = newNode;
	        num++;
	    }
	
	    void push_back(T value) {
	        Node<T> *newNode = new Node<T>(value);
	        if (head == nullptr) {
	            head = newNode;
	        } 
			else {
	            Node<T> *current = head;
	            while (current->next != nullptr) {
	                current = current->next;
	            }
	            current->next = newNode;
	        }
	        num++;
	    }
	
	    void pop_front() {
	        if (head == nullptr) return;
	        Node<T> *temp = head;
	        head = head->next;
	        delete temp;
	        num--;
	    }
	
	    void pop_back() {
	        if (head == nullptr) return;
	        if (head->next == nullptr) {
	            delete head;
	            head = nullptr;
	        } 
			else {
	            Node<T> *current = head;
	            while (current->next->next != nullptr) {
	                current = current->next;
	            }
	            Node<T> *temp = current->next;
	            current->next = nullptr;
	            delete temp;
	        }
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
	
	        Node<T> *current = head;
	        for (int i = 1; i < k - 1; ++i) {
	            current = current->next;
	        }
	        Node<T> *newNode = new Node<T>(value);
	        newNode->next = current->next;
	        current->next = newNode;
	        num++;
	    }

	    void erase(int k) {
	        if (k < 1 || k > num) return;
	        if (k == 1) {
	            pop_front();
	            return;
	        }
	
	        Node<T> *current = head;
	        for (int i = 1; i < k - 1; ++i) {
	            current = current->next;
	        }
	        Node<T> *temp = current->next;
	        current->next = temp->next;
	        delete temp;
	        num--;
	    }
	
	    T& front() {
	        return head->data;
	    }
	
	    T& back() {
	        Node<T> *current = head;
	        while (current->next != nullptr) {
	            current = current->next;
	        }
	        return current->data;
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
	
	    void print() const {
	        Node<T> *current = head;
	        while (current != nullptr) {
	            cout << current->data << " -> ";
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
};

#endif
