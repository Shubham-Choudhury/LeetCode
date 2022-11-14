// Link: https://leetcode.com/problems/partition-labels/?envType=study-plan&id=data-structure-ii

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> result;
        unordered_map<char, int> m;
        for (int i = 0; i < S.size(); i++) {
            m[S[i]] = i;
        }
        int i = 0;
        while (i < S.size()) {
            int end = m[S[i]];
            int j = i;
            while (j != end) {
                end = max(end, m[S[j]]);
                j++;
            }
            result.push_back(j - i + 1);
            i = j + 1;
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<int> result = s.partitionLabels("ababcbacadefegdehijhklij");
    for (int i : result) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}