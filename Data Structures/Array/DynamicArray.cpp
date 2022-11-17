#include <iostream>
using namespace std;
class Array {
    private:
        int length;
        int *data;
    
    public:
        Array() {
            this -> length = 0;
            this -> data = nullptr; 
        }
        int get(int index) {
            if (index < this -> length && index > 0)
                return data[index];
            else
                throw new invalid_argument("Invalid Index");
        }
        void push(int value) {
            if (this -> length == 0) {
                this -> data = new int[1];
                this -> data[0] = value;
            }else{
                int *temp = new int[this -> length];
                temp = this -> data;
                this -> data = new int[this -> length + 1];
                for (int i = 0;i < this -> length;i++) {
                    this -> data[i] = temp[i];
                }
                this -> data[this -> length] = value;
                delete[] temp;
            }
            this -> length += 1;
        }
        void pop() {
            if (this -> length > 0) {
                int *temp = new int[this -> length];
                temp = this -> data;
                this -> data = new int[this -> length - 1];
                for (int i = 0;i < this -> length - 1;i++) {
                    this -> data[i] = temp[i];
                }
                delete[] temp;
                this -> length -= 1;
            }  
        }
        void insert(int value, int index) {
            if (index <= this -> length && index >= 0) {
                int *temp = new int[this -> length];
                temp = this -> data;
                this -> data = new int[this -> length + 1];
                for (int i = 0;i <= this -> length;i++) {
                    if (i == index) {
                        this -> data[i] = value;
                    }else if (i < index) {
                        this -> data[i] = temp[i];
                    }else{
                        this -> data[i] = temp[i - 1];
                    }
                }
                delete[] temp;
                this -> length += 1;
            }else{
                throw new invalid_argument("Invalid Index");
            }
        }
        void remove(int index) {
            if (index < this -> length && index > 0) {
                int *temp = new int[this -> length];
                temp = this -> data;
                this -> data = new int[this -> length - 1];
                for (int i = 0;i < this -> length;i++) {
                    if (i > index) {
                        this -> data[i - 1] = temp[i];
                    }else if (i < index) {
                        this -> data[i] = temp[i];
                    }
                }
                delete[] temp;
                this -> length -= 1;
            }else {
                throw new invalid_argument("Invalid Index");
            }
        }
        void display() {
            for (int i = 0;i < this -> length;i++) {
                cout << this -> data[i] << " ";
            }
            cout << endl;
        }
};
int main() {
    Array *arr = new Array();

    // Push: O(n)
    arr -> push(1);
    arr -> push(2);
    arr -> push(3);

    cout << "Array: ";
    arr -> display();
    
    // Pop: O(n)
    arr -> pop();
    cout << "After pop: ";
    arr -> display();

    // Remove: O(n)
    arr -> remove(1);
    cout << "After remove: ";
    arr -> display();

    // Insert: O(n)
    arr -> insert(2, 1);
    cout << "After insert: ";
    arr -> display();
    return 0;
}