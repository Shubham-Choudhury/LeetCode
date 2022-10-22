// Link: https://leetcode.com/problems/integer-to-roman/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        string res;
        int temp;
        while(num)
        {
            if(num>=1000)
            {
                temp = num/1000;
                num = num%1000;
                for(int i=0; i<temp; i++)
                    res += "M";
            }
            else if(num>=900)
            {
                res += "CM";
                num -= 900;
            }
            else if(num>=500)
            {
                res += "D";
                num -= 500;
            }
            else if(num>=400)
            {
                res += "CD";
                num -= 400;
            }
            else if(num>=100)
            {
                temp = num/100;
                num = num%100;
                for(int i=0; i<temp; i++)
                    res += "C";
            }
            else if(num>=90)
            {
                res += "XC";
                num -= 90;
            }
            else if(num>=50)
            {
                res += "L";
                num -= 50;
            }
            else if(num>=40)
            {
                res += "XL";
                num -= 40;
            }
            else if(num>=10)
            {
                temp = num/10;
                num = num%10;
                for(int i=0; i<temp; i++)
                    res += "X";
            }
            else if(num>=9)
            {
                res += "IX";
                num -= 9;
            }
            else if(num>=5)
            {
                res += "V";
                num -= 5;
            }
            else if(num>=4)
            {
                res += "IV";
                num -= 4;
            }
            else if(num>=1)
            {
                temp = num;
                num = 0;
                for(int i=0; i<temp; i++)
                    res += "I";
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    cout << s.intToRoman(3) << endl;
    cout << s.intToRoman(58) << endl;
    cout << s.intToRoman(1994) << endl;
    return 0;
}