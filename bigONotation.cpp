#include <iostream>
using namespace std;
/*
    Big 0
        - Worst case
        - O(1) => O(logn) => O(n) => O(nlogn) => O(n^2) => O(2^n) => O(n!)
    Memory
        - The heap is usually where we store variables that we assign values to
        - the stack is usually where we keep track of our function calls.
*/
void first() 
{
    int n = 1000;
    int count = 0;
    int arr[n]; 
    for (int i = 0;i < n / 2;i++) 
    {
        arr[i] = rand();
        if (arr[i] == 0) 
        {
            count++;
            break;
        }
    }
    // => O(n)
}
void second() 
{
    int count = rand();
    // => O(1)
}
void third() 
{
    int n = 100, m = 50;
    for (int i = 0;i < n;i++) 
    {
        for (int j = 0;j < m;j++) 
        {
            // do something
        }
    }
    // => O(n * m)
}
void fourth()
{
    int n = 5;
    int arr[n] = {1, 2, 3, 4, 5};
    for (int i = 0;i < n;i++) {
        for (int j = i;j < n;j++) {
            // print pair of values
        }
    }
    // => O(n * (n + 1) / 2) => O(n ^ 2)
}
int main() 
{
    first(); 
    second(); 
    third();
    fourth();
    return 0;
}