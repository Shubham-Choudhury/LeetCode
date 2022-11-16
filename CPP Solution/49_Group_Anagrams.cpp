// Link: https://leetcode.com/problems/group-anagrams/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<string, vector<string>> map;
        for (int i = 0; i < strs.size(); i++) {
            string str = strs[i];
            sort(str.begin(), str.end());
            map[str].push_back(strs[i]);
        }
        for (auto it = map.begin(); it != map.end(); it++) {
            result.push_back(it->second);
        }
        return result;
    }
};

int main()
{
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    Solution sol;
    vector<vector<string>> result = sol.groupAnagrams(strs);
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}