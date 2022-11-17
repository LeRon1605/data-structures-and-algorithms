#include <iostream>
#include <string>
using namespace std;
string reverseSimple(string str) {
    string result = "";
    for (int i = str.size();i >= 0;i--) {
        result += str[i];
    }
    return result;
}
string reverseBetter(string str) {
    /*
        Well maybe it's better in the number of time for looping 
        and no need to create more memory to store result
    */ 
    for (int i = 0;i < str.size() / 2;i++) {
        char temp = str[i];
        str[i] = str[str.size() - i - 1];
        str[str.size() - i - 1] = temp;
    }
    return str;
}
int main() {
    string str = "Hello Ron!!";
    cout << "Reverse Simple: " << reverseSimple(str) << endl;
    cout << "Reverse Better: " << reverseBetter(str);
}