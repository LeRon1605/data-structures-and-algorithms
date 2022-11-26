#include <iostream>
#include <string.h>
using namespace std;
class Node {
    public:
        string key;
        int value;
};
class HashTable {
    private:
        int length;
        int count;
        Node **data;
    public:
        HashTable(int length) {
            this -> length = length;
            this -> count = 0;
            this -> data = new Node*[length];
            for (int i = 0;i < this -> length;i++) {
                this -> data[i] = nullptr;
            }
        }

        // O(1)
        void set(string key, int value) {
            int index = this -> hash(key);
            if (this -> data[index] == nullptr) {
                if (this -> count == this -> length) {
                    cout << "[ERROR] Hash table is full" << endl;
                }else{
                    this -> data[index] = new Node();
                    this -> data[index] -> key = key;
                    this -> data[index] -> value = value;
                    this -> count++;
                }
            }else{
                // Colission
                cout << "[WARNING] Collision at index " << index << " for key " << key << endl;
            }
        }

        // O(1)
        Node* get(string key) {
            int index = this -> hash(key);
            if (data[index] == nullptr) {
                cout << "[ERROR] Value not found" << endl;
                return nullptr;
            }else{
                return data[index];
            }
        }

        void print() {
            for (int i = 0;i < this -> length;i++) {
                if (data[i] != nullptr) {
                    cout << this -> data[i] -> key << ": " << this -> data[i] -> value << endl;
                }
            }
        }

        string* keys() {
            string *result = new string[this -> count];
            for (int i = 0, j = 0;i < this -> length;i++) {
                if (data[i] != nullptr) {
                    result[j] = data[i] -> key;
                    j++;
                }
            }
            return result;
        }

        int getCount() {
            return this -> count;
        }
    private:
        // O(1)
        int hash(string key) {
            int hash;
            for (int i = 0;i < key.size();i++) {
                hash += (key[i] * i); 
            }
            return hash % this -> length;
        }
};
int main() {
    HashTable *table = new HashTable(10);
    table -> set("First", 1);
    table -> set("Second", 3);
    table -> set("Three", 3);
    cout << table -> get("Haha") << endl;
    table -> print();

    string *keys = table -> keys();
    for (int i = 0;i < table -> getCount();i++) {
        cout << keys[i] << endl;
    }
    return 0;
}