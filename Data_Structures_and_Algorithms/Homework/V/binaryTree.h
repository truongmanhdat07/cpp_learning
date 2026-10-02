#ifndef BINARY_TREE_HPP
#define BINARY_TREE_HPP

#include <iostream>
using namespace std;

template <typename T>
struct BNode {
    T data;
    BNode<T> *left;
    BNode<T> *right;

    BNode(T val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

template <typename T>
class BinaryTree {
    private:
        BNode<T> *root;
        int num;

        BNode<T>* findNode(BNode<T> *current, T val) {
            if (current == nullptr) return nullptr;
            if (current->data == val) return current;

            BNode<T> *found = findNode(current->left, val);
            if (found != nullptr) return found;

            return findNode(current->right, val);
        }

        void clearNode(BNode<T> *current) {
            if (current == nullptr) return;
            clearNode(current->left);
            clearNode(current->right);
            delete current;
        }

        void preOrder(BNode<T> *current) {
            if (current == nullptr) return;
            cout << current->data << " ";
            preOrder(current->left);
            preOrder(current->right);
        }

        void inOrder(BNode<T> *current) {
            if (current == nullptr) return;
            inOrder(current->left);
            cout << current->data << " ";
            inOrder(current->right);
        }

        void postOrder(BNode<T> *current) {
            if (current == nullptr) return;
            postOrder(current->left);
            postOrder(current->right);
            cout << current->data << " ";
        }

        int calculateHeight(BNode<T> *current) {
		    if (current == nullptr) return 0;
		    int hLeft = calculateHeight(current->left);
		    int hRight = calculateHeight(current->right);
		    return 1 + (hLeft > hRight ? hLeft : hRight);
		}

    public:
        BinaryTree() {
            root = nullptr;
            num = 0;
        }

        ~BinaryTree() {
            clear();
        }

        bool empty() const {
            return root == nullptr;
        }

        int size() const {
            return num;
        }

        void set_root(T value) {
            if (root != nullptr) {
                clear();
            }
            root = new BNode<T>(value);
            num = 1;
        }

        bool insert_left(T parentVal, T value) {
            if (root == nullptr) return false;
            BNode<T> *parent = findNode(root, parentVal);
            if (parent == nullptr || parent->left != nullptr) return false;

            parent->left = new BNode<T>(value);
            num++;
            return true;
        }

        bool insert_right(T parentVal, T value) {
            if (root == nullptr) return false;
            BNode<T> *parent = findNode(root, parentVal);
            if (parent == nullptr || parent->right != nullptr) return false;

            parent->right = new BNode<T>(value);
            num++;
            return true;
        }

        bool find(T value) {
            return findNode(root, value) != nullptr;
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
