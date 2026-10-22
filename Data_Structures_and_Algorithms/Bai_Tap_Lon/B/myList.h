#ifndef MY_LIST_H
#defile MY_LIST_H

#include<iostream>
using namespace std;

template <typename T>
struct Node{
	T data;
	Node *next;
	Node(T value) : data(value), next(nullptr){}
};

template <typename T>
class SingleList{
	private:
		Node<T> *head;
		int count;
	public:
		SingleList() : head(nullptr), count(0){}
		
		~SingleList(){
		clear();
		}
		
		void push_back(T value){
			Node<T> *newNode = new Node<T>(value);
			
			if(head == nullptr){
				head = newNode;
			}
			else{
				Node<T> *current = head;
				while(current->next != nullptr){
					current = current->next;
				}
				current->next = newNode;
			}
			count ++;
		}
		
		const getHead() const{
			return head;
		}
		
		int size(){
			return count;
		}
		
		bool empty(){
			return head == nullptr;
		}
		
		void clear(){
			Node<T> *current = head;
			while(current != nullptr){
				Node<T> *nextNode = current->next;
				delete current;
				current = nextNode;
			}
			head = nullptr;
			count = 0;
		}
};
