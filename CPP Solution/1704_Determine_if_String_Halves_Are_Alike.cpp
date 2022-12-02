// Link: https://leetcode.com/problems/determine-if-string-halves-are-alike/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool halvesAreAlike(string s) {
        int n = s.size();
        int count = 0;
        for(int i = 0; i < n/2; i++){
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
                count++;
        }
        for(int i = n/2; i < n; i++){
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
                count--;
        }
        return count == 0;
    }
};

int main(){
    Solution s;
    cout << s.halvesAreAlike("book") << endl;
    cout << s.halvesAreAlike("textbook") << endl;
    cout << s.halvesAreAlike("MerryChristmas") << endl;
    cout << s.halvesAreAlike("AbCdEfGh") << endl;
    return 0;
}