// Link: https://leetcode.com/problems/longest-repeating-character-replacement/?envType=study-plan&id=level-1

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        vector<int> freq(26, 0);
        int i = 0, j = 0;
        int maxFreq = 0;
        int ans = 0;
        while(j < n) {
            freq[s[j] - 'A']++;
            maxFreq = max(maxFreq, freq[s[j] - 'A']);
            if(j - i + 1 - maxFreq > k) {
                freq[s[i] - 'A']--;
                i++;
            }
            ans = max(ans, j - i + 1);
            j++;
        }
        return ans;
    }
};

int main() {
    string s;
    int k;
    cin >> s >> k;
    Solution obj;
    cout << obj.characterReplacement(s, k) << endl;
    return 0;
}