#include <string>
using namespace std;
class Solution {
    public:
        string intToRoman(int num) {
            string result = "";
            int n = 0;
            if (num >= 1000) {
                n = num / 1000;
                result += getMulChar("M", n);
                num = num % 1000;
            }
            
            if (num >= 500) {
                if (num >= 900) {
                    result += "CM";
                    num = num % 900;
                }else{
                    n = num / 500;
                    result += getMulChar("D", n);
                    num = num % 500;   
                }
            }
            
            if (num >= 100) {
                if (num >= 400) {
                    result += "CD";
                    num = num % 400;
                }else{
                    n = num / 100;
                    result += getMulChar("C", n);
                    num = num % 100;   
                }
            }
            
            if (num >= 50) {
                if (num >= 90) {
                    result += "XC";
                    num = num % 90;
                }
                n = num / 50;
                result += getMulChar("L", n);
                num = num % 50;
            }
            
            if (num >= 10) {
                if (num >= 40) {
                    result += "XL";
                    num = num % 40;
                }else{
                    n = num / 10;
                    result += getMulChar("X", n);
                    num = num % 10;   
                }
            }
            
            if (num >= 5) {
                if (num >= 9) {
                    result += "IX";
                    num = num % 9;
                }else{
                    n = num / 5;
                    result += getMulChar("V", n);
                    num = num % 5;   
                }
            }
            if (num == 4) {
                result += "IV";
            }else{
                result += getMulChar("I", num);
            }
            return result;   
        }
        string getMulChar(string c, int n) {
            string result = "";
            for (int i = 0;i < n;i++) result += c;
            return result;
        }
};