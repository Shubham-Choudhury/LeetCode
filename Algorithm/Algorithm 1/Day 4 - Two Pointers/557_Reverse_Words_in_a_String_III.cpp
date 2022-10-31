// Link: https://leetcode.com/problems/reverse-words-in-a-string-iii/?envType=study-plan&id=algorithm-i

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        int i = 0;
        int j = 0;
        while (j < s.size()) {
            while (j < s.size() && s[j] != ' ') {
                j++;
            }
            int left = i;
            int right = j - 1;
            while (left < right) {
                char temp = s[left];
                s[left] = s[right];
                s[right] = temp;
                left++;
                right--;
            }
            i = j + 1;
            j = i;
        }
        return s;
    }
};

int main(){
    string s = "Let's take LeetCode contest";
    Solution obj;
    string ans = obj.reverseWords(s);
    cout << ans << endl;
    return 0;
}