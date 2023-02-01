#ifndef NODE_H
#define NODE_H
template <class T> 
class Node{
    private:
        T data; // Node
        Node *prev; // Node trước
        Node *next; // Node sau
    public:
        Node(const T); // Khởi tạo node
        ~Node();

        bool hasNext(); // Kiểm tra xem node hiện tại có node next hay không
        bool hasPrev(); // Kiểm tra xem node hiện tại có node prev hay không
        Node* getNext(); // Lấy ra node next
        Node* getPrev(); // Lấy ra node prev
        T getData(); // Lấy ra data
        T& getRefData();
        void setNextNode(Node*); // Set node next
        void setPrevNode(Node*); // Set node prev
        void setData(const T);  // Set Data
};

template <class T>
Node<T>::Node(const T data){
    this -> data = data;
    this -> next = nullptr;
    this -> prev = nullptr;
}

template <class T>
Node<T>::~Node(){
   
}

template <class T>
bool Node<T>::hasNext(){
    return (this -> next != nullptr);
}

template <class T>
bool Node<T>::hasPrev(){
    return (this -> prev != nullptr);
}

template <class T>
Node<T>* Node<T>::getPrev(){
    return this -> prev;
}

template <class T>
Node<T>* Node<T>::getNext(){
    return this -> next;
}

template <class T>
T Node<T>::getData(){
    return this -> data;
}

template <class T>
T& Node<T>::getRefData(){
    return this -> data;
}

template <class T>
void Node<T>::setNextNode(Node<T> *next){
    this -> next = next;
}

template <class T>
void Node<T>::setPrevNode(Node<T> *prev){
    this -> prev = prev;
}

template <class T>
void Node<T>::setData(const T data){
    this -> data = data;
}

#endif