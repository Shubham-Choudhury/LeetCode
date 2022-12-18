// Link: https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestSubstring(string s, int k) {
        int L = s.size();
        if (L == 0 || k > L) {
            return 0;
        }
        if (k <= 1) {
            return L;
        }
        int count[26] = {0};
        for (int i = 0; i < L; i++) {
            count[s[i] - 'a']++;
        }
        int index = 0;
        while (index < L && count[s[index] - 'a'] >= k) {
            index++;
        }
        if (index == L) {
            return L;
        }
        int left = longestSubstring(s.substr(0, index), k);
        while (index < L && count[s[index] - 'a'] < k) {
            index++;
        }
        int right = longestSubstring(s.substr(index), k);
        return max(left, right);
    }
};

int main()
{
    Solution s;
    cout << s.longestSubstring("aaabb", 3) << endl;
    return 0;
}
