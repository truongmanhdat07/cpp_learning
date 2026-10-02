#ifndef GTREE_HPP
#define GTREE_HPP

#include <iostream>
using namespace std;

template <typename T>
struct GNode {
    T data;
    GNode<T> *firstChild;  
    GNode<T> *nextSibling;  

    GNode(T val) {
        data = val;
        firstChild = nullptr;
        nextSibling = nullptr;
    }
};

template <typename T>
class GTree {
    private:
        GNode<T> *root;
        int num;

        // Hàm ph? d? quy tìm ki?m nút theo giá tr?
        GNode<T>* findNode(GNode<T> *current, T val) {
            if (current == nullptr) return nullptr;
            if (current->data == val) return current;

            // Tìm sâu xu?ng các nút con
            GNode<T> *found = findNode(current->firstChild, val);
            if (found != nullptr) return found;

            // Tìm sang các nút anh em k?
            return findNode(current->nextSibling, val);
        }

        // Hàm ph? gi?i phóng b? nh? (h?u th? t?)
        void clearNode(GNode<T> *current) {
            if (current == nullptr) return;
            clearNode(current->firstChild);
            clearNode(current->nextSibling);
            delete current;
        }

        // Duy?t ti?n th? t? (Pre-order): Nút g?c -> Các con
        void preOrder(GNode<T> *current) {
            if (current == nullptr) return;
            cout << current->data << " ";
            
            // Duy?t l?n lu?t t?ng ngu?i con t? trái sang ph?i
            GNode<T> *child = current->firstChild;
            while (child != nullptr) {
                preOrder(child);
                child = child->nextSibling;
            }
        }

        // Duy?t h?u th? t? (Post-order): Các con -> Nút g?c
        void postOrder(GNode<T> *current) {
            if (current == nullptr) return;

            // Duy?t h?t các cây con tru?c
            GNode<T> *child = current->firstChild;
            while (child != nullptr) {
                postOrder(child);
                child = child->nextSibling;
            }

            // In nút g?c sau cùng
            cout << current->data << " ";
        }

        // Hàm tính chi?u cao c?a cây
        int calculateHeight(GNode<T> *current) {
            if (current == nullptr) return 0;
            int maxHeight = 0;

            // L?y chi?u cao l?n nh?t trong t?t c? các nhánh con
            GNode<T> *child = current->firstChild;
            while (child != nullptr) {
                int h = calculateHeight(child);
                if (h > maxHeight) {
                    maxHeight = h;
                }
                child = child->nextSibling;
            }

            return 1 + maxHeight;
        }

    public:
        GTree() {
            root = nullptr;
            num = 0;
        }

        ~GTree() {
            clear();
        }

        bool empty() const {
            return root == nullptr;
        }

        int size() const {
            return num;
        }

        // Thi?t l?p nút g?c cho cây
        void set_root(T value) {
            if (root != nullptr) {
                clear();
            }
            root = new GNode<T>(value);
            num = 1;
        }

        // Thêm m?t nút con vào nút cha có s?n
        bool insert(T parentVal, T value) {
            if (root == nullptr) return false;

            GNode<T> *parent = findNode(root, parentVal);
            if (parent == nullptr) return false; // Không tìm th?y nút cha

            GNode<T> *newNode = new GNode<T>(value);

            // N?u cha chua có con nào, newNode thành con tru?ng
            if (parent->firstChild == nullptr) {
                parent->firstChild = newNode;
            } 
            else {
                // Ðã có con -> tìm d?n ngu?i em cu?i cùng trong danh sách
                GNode<T> *current = parent->firstChild;
                while (current->nextSibling != nullptr) {
                    current = current->nextSibling;
                }
                current->nextSibling = newNode;
            }
            num++;
            return true;
        }

        // Ki?m tra ph?n t? có t?n t?i không
        bool find(T value) {
            return findNode(root, value) != nullptr;
        }

        // Chi?u cao cây
        int height() {
            return calculateHeight(root);
        }

        // In duy?t ti?n th? t?
        void pre_order() {
            preOrder(root);
            cout << "\n";
        }

        // In duy?t h?u th? t?
        void post_order() {
            postOrder(root);
            cout << "\n";
        }

        // Xóa và gi?i phóng toàn b? cây
        void clear() {
            clearNode(root);
            root = nullptr;
            num = 0;
        }
};

#endif
