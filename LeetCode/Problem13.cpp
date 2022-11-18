#include <iostream>
#include <string>
using namespace std;
int main()
{
    int result = 0;
    string s = "MCMXCIV";
    for (int i = s.size() - 1; i >= 0; i--)
    {
        int value = 0;
        if (s[i] == 'I')
            value += 1;
        else if (s[i] == 'V')
            value += 5;
        else if (s[i] == 'X')
            value += 10;
        else if (s[i] == 'L')
            value += 50;
        else if (s[i] == 'C')
            value += 100;
        else if (s[i] == 'D')
            value += 500;
        else if (s[i] == 'M')
            value += 1000;

        if (i - 1 > 0)
        {
            if (s[i - 1] == 'I' && value >= 5 && value <= 10)
            {
                value -= 1;
                i--;
            }
            else if (s[i - 1] == 'X' && value >= 50 && value <= 100)
            {
                value -= 10;
                i--;
            }
            else if (s[i - 1] == 'C' && value >= 500 && value <= 1000)
            {
                value -= 100;
                i--;
            }
        }
        result += value;
    }
    cout << result;
}