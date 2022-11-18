/*
    Given an integer x, return true if x is a palindrome, and false otherwise.
*/
class Solution {
public:
    bool isPalindrome(long x) {
        long reverse = 0;
        long n = x;
        while (x > 0) {
            reverse = reverse * 10 + x % 10;
            x /= 10;
        }
        return (reverse == n);
    }
};