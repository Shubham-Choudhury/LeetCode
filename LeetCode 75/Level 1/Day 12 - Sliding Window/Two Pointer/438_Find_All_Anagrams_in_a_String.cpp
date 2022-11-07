// Link: https://leetcode.com/problems/find-all-anagrams-in-a-string/?envType=study-plan&id=level-1

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        int n = s.size();
        int m = p.size();
        if(n < m) return ans;
        vector<int> freq(26, 0);
        for(int i = 0; i < m; i++) {
            freq[p[i] - 'a']++;
        }
        int i = 0, j = 0;
        int count = m;
        while(j < n) {
            if(freq[s[j] - 'a'] > 0) {
                count--;
            }
            freq[s[j] - 'a']--;
            if(count == 0) {
                ans.push_back(i);
            }
            if(j - i + 1 < m) {
                j++;
            } else {
                if(freq[s[i] - 'a'] >= 0) {
                    count++;
                }
                freq[s[i] - 'a']++;
                i++;
                j++;
            }
        }
        return ans;
    }
};

int main() {
    string s, p;
    cin >> s >> p;
    Solution obj;
    vector<int> ans = obj.findAnagrams(s, p);
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}