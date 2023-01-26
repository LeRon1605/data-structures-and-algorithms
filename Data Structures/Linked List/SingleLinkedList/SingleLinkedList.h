#include <iostream>
#include "./Node.h"
using namespace std;
template <class T>
class LinkedList {
    private:
        int length;
        Node<T> *head;
        Node<T> *tail;
    public:
        LinkedList() {
            this -> head = nullptr;
            this -> tail = nullptr;
            this -> length = 0;
        }

        Node<T>* getHead() {
            return this -> head;
        }

        int getLength() {
            return this -> length;
        }

        Node<T>* search(T value) {
            Node<T> *ptr = this -> head;
            while (ptr != nullptr) {
                if (ptr -> data == value) return ptr;
                ptr = ptr -> next;
            }
            return nullptr;
        }

        void removeFirst() {
            if (this -> head != nullptr) {
                Node<T> *ptr = this -> head;
                this -> head = this -> head -> next;               
                this -> length -= 1;
                delete ptr;
            }
        }

        void removeLast() {
            if (this -> length == 1) {
                this -> head = nullptr;
                this -> tail = nullptr;
            } else {               
                Node<T> *ptr = this -> head;
                while (ptr -> next -> next != nullptr) {
                    ptr = ptr -> next;
                }
                ptr -> next = nullptr;
                this -> tail = ptr;
            }
            this -> length -= 1;
        }

        void removeAt(int index) {
            if (index >= 0 && index < this -> length) {
                if (index == 0) removeFirst();
                else if (index == this -> length - 1) removeLast();
                else {
                    Node<T> *after = this -> head;
                    Node<T> *before = after;
                    int current = 0;
                    while (after != nullptr && index != current) {
                        before = after;
                        after = after -> next;
                        current += 1;
                    }
                    before -> next = after -> next;
                    delete after;
                    this -> length -= 1;
                }
            }
        }

        void prepend(T value) {
            Node<T> *node = new Node(value);
            if (this -> head == nullptr) {
                this -> head = node;
                this -> tail = node;
            } else {
                node -> next = this -> head;
                this -> head = node;
            }
            this -> length += 1;
        }

        void append(T value) {
            Node<T> *node = new Node(value);
            if (this -> head == nullptr) {
                this -> head = node;
                this -> tail = node;
            } else {
                this -> tail -> next = node;
                this -> tail = node;
            }
            this -> length += 1;
        }

        void insertAt(T value, int index) {
            if (index >= 0 && index <= this -> length) {
                if (index == 0) prepend(value);
                else {
                    Node<T> *node = new Node(value);
                    Node<T> *ptr = this -> head;
                    int current = 0;
                    while (ptr != nullptr && current != index - 1) {
                        ptr = ptr -> next;
                        current += 1;
                    }
                    node -> next = ptr -> next;
                    ptr -> next = node;
                    this -> length += 1;
                }
            }
        }

        void print() {
            Node<T> *p = this -> head;
            while (p != nullptr) {
                cout << p -> data << " ";
                p = p -> next;
            }
        }
};