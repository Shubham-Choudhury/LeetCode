// Link: https://leetcode.com/problems/count-the-repetitions/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        int s1Count = 0, index = 0, s2Count = 0;
        vector<int> repeatCount(s2.size() + 1, 0);
        vector<int> nextIndex(s2.size() + 1, 0);
        while (s1Count < n1) {
            s1Count++;
            for (int i = 0; i < s1.size(); i++) {
                if (s1[i] == s2[index]) {
                    index++;
                    if (index == s2.size()) {
                        index = 0;
                        s2Count++;
                    }
                }
            }
            repeatCount[s1Count] = s2Count;
            nextIndex[s1Count] = index;
            for (int start = 0; start < s1Count; start++) {
                if (nextIndex[start] == index) {
                    int prefixCount = repeatCount[start];
                    int patternCount = (repeatCount[s1Count] - repeatCount[start]) * ((n1 - start) / (s1Count - start));
                    int suffixCount = repeatCount[start + (n1 - start) % (s1Count - start)] - repeatCount[start];
                    return (prefixCount + patternCount + suffixCount) / n2;
                }
            }
        }
        return repeatCount[n1] / n2;
    }
};

int main() {
    Solution s;
    string s1 = "acb";
    int n1 = 4;
    string s2 = "ab";
    int n2 = 2;
    cout << s.getMaxRepetitions(s1, n1, s2, n2) << endl;
    return 0;
}
