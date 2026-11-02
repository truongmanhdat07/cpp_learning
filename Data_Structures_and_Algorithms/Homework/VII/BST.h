#ifndef BST_H
#define BST_H

#include <iostream>

using namespace std;

template <typename T>
struct BSTNode {
    T data;
    BSTNode<T> *left;
    BSTNode<T> *right;

    BSTNode(T val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

template <typename T>
class BST {
    private:
        BSTNode<T> *root;
        int num;
        int (*comp)(T, T);

        bool isLess(T a, T b) {
            if (comp != nullptr) {
                return comp(a, b) == 1;
            }
            return a < b;
        }

        bool isEqual(T a, T b) {
            if (comp != nullptr) {
                return !isLess(a, b) && !isLess(b, a);
            }
            return a == b;
        }

        BSTNode<T>* insertNode(BSTNode<T> *current, T val) {
            if (current == nullptr) {
                num++;
                return new BSTNode<T>(val);
            }

            if (isLess(val, current->data)) {
                current->left = insertNode(current->left, val);
            } 
            else if (isLess(current->data, val)) {
                current->right = insertNode(current->right, val);
            }
            return current;
        }

        BSTNode<T>* searchNode(BSTNode<T> *current, T val) {
            if (current == nullptr) return nullptr;
            if (isEqual(val, current->data)) return current;

            if (isLess(val, current->data)) {
                return searchNode(current->left, val);
            }
            return searchNode(current->right, val);
        }

        BSTNode<T>* findMinNode(BSTNode<T> *current) {
            while (current != nullptr && current->left != nullptr) {
                current = current->left;
            }
            return current;
        }

        BSTNode<T>* eraseNode(BSTNode<T> *current, T val) {
            if (current == nullptr) return nullptr;

            if (isLess(val, current->data)) {
                current->left = eraseNode(current->left, val);
            } 
            else if (isLess(current->data, val)) {
                current->right = eraseNode(current->right, val);
            } 
            else {
                if (current->left == nullptr) {
                    BSTNode<T> *temp = current->right;
                    delete current;
                    num--;
                    return temp;
                } 
                else if (current->right == nullptr) {
                    BSTNode<T> *temp = current->left;
                    delete current;
                    num--;
                    return temp;
                }

                BSTNode<T> *temp = findMinNode(current->right);
                current->data = temp->data;
                current->right = eraseNode(current->right, temp->data);
            }
            return current;
        }

        void clearNode(BSTNode<T> *current) {
            if (current == nullptr) return;
            clearNode(current->left);
            clearNode(current->right);
            delete current;
        }

        void preOrder(BSTNode<T> *current) {
            if (current == nullptr) return;
            cout << current->data << " ";
            preOrder(current->left);
            preOrder(current->right);
        }

        void inOrder(BSTNode<T> *current) {
            if (current == nullptr) return;
            inOrder(current->left);
            cout << current->data << " ";
            inOrder(current->right);
        }

        void postOrder(BSTNode<T> *current) {
            if (current == nullptr) return;
            postOrder(current->left);
            postOrder(current->right);
            cout << current->data << " ";
        }

    public:
        BST(int (*comp)(T, T) = nullptr) {
            root = nullptr;
            num = 0;
            this->comp = comp;
        }

        ~BST() {
            clear();
        }

        bool empty() {
            return root == nullptr;
        }

        int size() {
            return num;
        }

        BSTNode<T>* getRoot() {
            return root;
        }

        void setComparator(int (*comp)(T, T)) {
            this->comp = comp;
        }

        void insert(T value) {
            root = insertNode(root, value);
        }

        void erase(T value) {
            root = eraseNode(root, value);
        }

        BSTNode<T>* find(T value) {
            return searchNode(root, value);
        }

        bool contains(T value) {
            return searchNode(root, value) != nullptr;
        }

        void pre_order() {
            preOrder(root);
            cout << "\n";
        }

        void in_order() {
            inOrder(root);
            cout << "\n";
        }

        void post_order() {
            postOrder(root);
            cout << "\n";
        }

        void clear() {
            clearNode(root);
            root = nullptr;
            num = 0;
        }
};

#endif
