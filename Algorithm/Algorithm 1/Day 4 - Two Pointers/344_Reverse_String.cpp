// Link: https://leetcode.com/problems/reverse-string/?envType=study-plan&id=algorithm-i

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int i = 0;
        int j = s.size() - 1;
        while (i < j) {
            char temp = s[i];
            s[i] = s[j];
            s[j] = temp;
            i++;
            j--;
        }
    }
};

int main(){
    vector<char> s = {'h','e','l','l','o'};
    Solution obj;
    obj.reverseString(s);
    for (int i = 0; i < s.size(); i++) {
        cout << s[i] << " ";
    }
    cout << endl;
    return 0;
}