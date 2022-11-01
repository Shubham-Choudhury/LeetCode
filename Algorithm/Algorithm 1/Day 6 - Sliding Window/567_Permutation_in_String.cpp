// Link: https://leetcode.com/problems/permutation-in-string/?envType=study-plan&id=algorithm-i

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();
        if(n > m)
            return false;
        vector<int> count1(26, 0);
        vector<int> count2(26, 0);
        for(int i = 0; i < n; i++){
            count1[s1[i] - 'a']++;
            count2[s2[i] - 'a']++;
        }
        for(int i = n; i < m; i++){
            if(count1 == count2)
                return true;
            count2[s2[i] - 'a']++;
            count2[s2[i - n] - 'a']--;
        }
        return count1 == count2;
    }
};

int main(){
    Solution s;
    string s1 = "ab";
    string s2 = "eidbaooo";
    cout << s.checkInclusion(s1, s2) << endl;
    return 0;
}