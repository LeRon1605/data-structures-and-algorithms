#include <iostream>
#include "./SingleLinkedList.h"
using namespace std;
int main() {
    LinkedList<int> list;
    list.append(3); 
    list.append(4);
    list.prepend(2);
    list.insertAt(2, 1);
    Node<int> *ptr = list.search(2);
    list.removeFirst();
    list.removeLast();
    list.removeLast();
    list.removeAt(2);
    list.print();
}