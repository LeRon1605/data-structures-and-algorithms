#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include "Node.h"
#include <iostream>
using namespace std;
template <class T>
class LinkedList{
    private:
        Node<T> *head;
        Node<T> *tail;
        int length;
    public:
        LinkedList();
        LinkedList(const LinkedList&);
        ~LinkedList();

        Node<T>* getHead();
        Node<T>* getTail();

        int indexOf(const T); // Index đầu của T
        int indexOf(bool (*compare)(const T, const string&), const string&);
        int lastIndexOf(const T); // Index cuối cùng của T
        int lastIndexOf(bool (*compare)(const T, const string&), const string&); 
        bool insertAt(const T, const int&);
        bool addHead(const T); // Thêm vào đầu
        bool addTail(const T); // Thêm vào cuối
        bool removeAt(const int&); // Xóa phần tử tại vị trí index
        bool remove(const T); // Xóa phần tử T đầu tiên
        bool remove(bool (*compare)(const T, const string&), const string &);
        bool removeTail(); // Xóa phần tử cuối
        bool removeHead(); // Xóa phần tử đầu
        bool replace(const T, const int&);
        int getLength(); //
        bool isEmpty(); // Kiểm tra xem danh sách có rỗng hay không
        bool contains(const T); // Kiểm tra xem có tồn tại phần tử T hay không
        bool contains(bool (*compare)(const T, const string&), const string &str);
        void show(); // Hiển thị
        void sort(Node<T>, Node<T>);
        void sort(bool (*compare)(const T, const T));

        T& operator[](const int&);
        const LinkedList<T>& operator=(const LinkedList&);
};

template <class T>
Node<T>* LinkedList<T>::getHead(){
    return this -> head;
}

template <class T>
Node<T>* LinkedList<T>::getTail(){
    return this -> tail;
}

template <class T>
LinkedList<T>::LinkedList(){
    this -> head = nullptr;
    this -> tail = nullptr;
    this -> length = 0;
}

template <class T>
LinkedList<T>::LinkedList(const LinkedList<T> &list){
    Node<T> *ptr = LinkedList(list).getHead();
    while (ptr != nullptr){
        this -> addTail(ptr -> getData());
        ptr = ptr -> getNext();
    }
}

template <class T>
LinkedList<T>::~LinkedList(){
    Node<T> *temp = this -> head;
    while (this -> head != this -> tail){
        temp = this -> head;
        this -> head = this -> head -> getNext();
        delete temp;
    }
    delete this -> tail;
}

template <class T>
int LinkedList<T>::indexOf(const T element){
    Node<T> *ptr = this -> head;
    int index = 0;
    while (ptr != nullptr){
        if (ptr -> getData() == element) return index;
        index++;
        ptr = ptr -> getNext();
    }
    return -1;
}

template <class T>
int LinkedList<T>::indexOf(bool (*compare)(const T, const string&), const string &str){
    Node<T> *ptr = this -> head;
    int index = 0;
    while (ptr != nullptr){
        if (compare(ptr -> getData(), str)) return index;
        index++;
        ptr = ptr -> getNext();
    }
    return -1;
}

template <class T>
int LinkedList<T>::lastIndexOf(const T element){
    Node<T> *ptr = this -> tail;
        int index = length - 1;
        while (ptr != nullptr){
            if (ptr -> getData() == element) return index;
            index--;
            ptr = ptr -> getPrev();
        }
        return -1;  
}

template <class T>
int LinkedList<T>::lastIndexOf(bool (*compare)(const T, const string&), const string &str){
    Node<T> *ptr = this -> tail;
        int index = length - 1;
        while (ptr != nullptr){
            if (compare(ptr -> getData(), str)) return index;
            index--;
            ptr = ptr -> getPrev();
        }
        return -1;  
}

template <class T>
bool LinkedList<T>::addHead(const T element){
    Node<T> *newNode = new Node<T>(element);
    if (newNode == nullptr) return false;
    if (this -> head == nullptr && this -> tail == nullptr){
        this -> head = newNode;
        this -> tail = newNode;
    }else{
        newNode -> setNextNode(this -> head);
        this -> head -> setPrevNode(newNode);
        this -> head = newNode;
    }
    this -> length += 1;
    return true;
}

template <class T>
bool LinkedList<T>::insertAt(const T element, const int &index){
    int i = 0;
    if (index > this -> length || index < 0) return false;
    if (index == 0) this -> addHead(element);
    else if (index == this -> length) this -> addTail(element);
    else{
        Node<T> *ptr = this -> head;
        Node<T> *newNode = new Node<T>(element);
        while (i != index){
            i++;
            ptr = ptr -> getNext();
        }
        newNode -> setPrevNode(ptr -> getPrev());
        newNode -> setNextNode(ptr);
        ptr -> getPrev() -> setNextNode(newNode);
        ptr -> setPrevNode(newNode);
        this -> length += 1;
    }
    return true;
}

template <class T>
bool LinkedList<T>::addTail(const T element){
    Node<T> *newNode = new Node<T>(element);
    if (newNode == nullptr) return false;
    if (this -> head == nullptr && this -> tail == nullptr){
        this -> head = newNode;
        this -> tail = newNode;
    }else{
        newNode -> setPrevNode(this -> tail);
        this -> tail -> setNextNode(newNode);
        this -> tail = newNode; 
    }
    this -> length += 1;
    return true;
}

template <class T> 
bool LinkedList<T>::removeHead(){
    if (this -> head == this -> tail){
        Node<T> *temp = this -> head;
        this -> head = nullptr;
        this -> tail = nullptr;
        this -> length -= 1;
        delete temp;
        return true;
    }
    if (this -> head != nullptr){
        Node<T> *temp = this -> head;
        this -> head = this -> head -> getNext();
        this -> head -> setPrevNode(nullptr);
        this -> length -= 1;
        delete temp;
        return true;
    }
    return false;
}

template <class T>
bool LinkedList<T>::removeTail(){
    if (this -> head == this -> tail){
        Node<T> *temp = this -> head;
        this -> head = nullptr;
        this -> tail = nullptr;
        this -> length -= 1;
        delete temp;
        return true;
    }
    if (this -> tail != nullptr){
        Node<T> *temp = this -> tail;
        this -> tail = this -> tail -> getPrev();
        this -> tail -> setNextNode(nullptr);
        this -> length -= 1;
        delete temp;
        return true;
    }
    return false;
}

template <class T>
bool LinkedList<T>::remove(const T element){
    int index = this -> indexOf(element);
    if (index == -1) return false;
    else{
        this -> removeAt(index);
        return true;
    }
}

template <class T>
bool LinkedList<T>::remove(bool (*compare)(const T, const string&), const string &str){
    int index = this -> indexOf(compare, str);
    if (index == -1) return false;
    else{
        this -> removeAt(index);
        return true;
    }
}  

template <class T>
bool LinkedList<T>::removeAt(const int &index){
    if (index < 0 || index >= this -> length) return false;
    else{
        if (index == 0) {
            this -> removeHead();
            return true;
        }
        if (index == this -> length - 1) {
            this -> removeTail();
            return true;
        }
        int i = 0;
        Node<T> *ptr = this -> head;
        while (i != index){
            i++;
            ptr = ptr -> getNext();
        }
        Node<T> *temp = ptr;
        ptr -> getPrev() -> setNextNode(ptr -> getNext());
        ptr -> getNext() -> setPrevNode(ptr -> getPrev());
        this -> length -= 1;
        delete temp;
        return true;
    }
}

template <class T>
bool LinkedList<T>::replace(const T element, const int &index){
    if (index < 0 || index >= this -> length) return false;
    else {
        int i = 0;
        Node<T> *ptr = this -> head;
        while (i != index){
            i++;
            ptr = ptr -> getNext();
        }
        ptr -> setData(element);
        return true;
    }
}

template <class T>
int LinkedList<T>::getLength(){
    return this -> length;
}

template <class T>
bool LinkedList<T>::isEmpty(){
    return (this -> head == nullptr && this -> length == 0);
}

template <class T>
bool LinkedList<T>::contains(const T element){
    Node<T> *ptr = this -> head;
    while (ptr != nullptr){
        if (ptr -> getData() == element) return true;
        ptr = ptr -> getNext();
    }
    return false;
}


template <class T>
bool LinkedList<T>::contains(bool (*compare)(const T, const string&), const string &str){
    Node<T> *ptr = this -> head;
    while (ptr != nullptr){
        if (compare(ptr -> getData(), str)) return true;
        ptr = ptr -> getNext();
    }
    return false;
}


template <class T>
void LinkedList<T>::show(){
    Node<T> *ptr = this -> head;
    while (ptr != nullptr){
        ptr -> getData().show();
        cout << endl;
        ptr = ptr -> getNext();
    }
}

template <class T>
void LinkedList<T>::sort(bool (*compare)(const T valueA, const T valueB)){
    for (Node<T> *i = this -> tail;i != nullptr;i = i -> getPrev()){
        for (Node<T> *j = this -> head;j != i;j = j -> getNext()){
            if (compare(j -> getData(), j -> getNext() -> getData())){
                T temp = j -> getData();
                j -> setData(j -> getNext() -> getData());
                j -> getNext() -> setData(temp);
            }
        }
    }
}

template <class T>
T& LinkedList<T>::operator[](const int &index){
    if (index < 0 || index >= this-> length) throw "Index out of range";
    
    Node<T> *ptr = this -> head;
    int i = 0;
    while (i != index){
        i++;
        ptr = ptr -> getNext();
    }
    return ptr -> getRefData();
}

template <class T>
const LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T> &list){
    Node<T> *ptr = LinkedList<T>(list).getHead();
    while (ptr != nullptr){
        this -> addTail(ptr -> getData());
        ptr = ptr -> getNext();
    }
    return (*this);
}
#endif