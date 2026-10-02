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

        BSTNode<T>* insertNode(BSTNode<T> *current, T val) {
            if (current == nullptr) {
                num++;
                return new BSTNode<T>(val);
            }

            if (val < current->data) {
                current->left = insertNode(current->left, val);
            } 
            else if (val > current->data) {
                current->right = insertNode(current->right, val);
            }
            return current;
        }

        bool searchNode(BSTNode<T> *current, T val) {
            if (current == nullptr) return false;
            if (current->data == val) return true;

            if (val < current->data) {
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

            if (val < current->data) {
                current->left = eraseNode(current->left, val);
            } 
            else if (val > current->data) {
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

        int calculateHeight(BSTNode<T> *current) {
            if (current == nullptr) return 0;
            int hLeft = calculateHeight(current->left);
            int hRight = calculateHeight(current->right);
            return 1 + (hLeft > hRight ? hLeft : hRight);
        }

    public:
        BST() {
            root = nullptr;
            num = 0;
        }

        ~BST() {
            clear();
        }

        bool empty() const {
            return root == nullptr;
        }

        int size() const {
            return num;
        }

        void insert(T value) {
            root = insertNode(root, value);
        }

        void erase(T value) {
            root = eraseNode(root, value);
        }

        bool find(T value) {
            return searchNode(root, value);
        }

        T min_element() {
            BSTNode<T> *minNode = findMinNode(root);
            if (minNode != nullptr) return minNode->data;
            return T();
        }

        T max_element() {
            BSTNode<T> *current = root;
            while (current != nullptr && current->right != nullptr) {
                current = current->right;
            }
            if (current != nullptr) return current->data;
            return T();
        }

        int height() {
            return calculateHeight(root);
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
