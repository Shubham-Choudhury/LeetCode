// Link: https://leetcode.com/problems/special-binary-string/

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
public:
    string makeLargestSpecial(string S) {
        int n = S.size();
        vector<string> v;
        for (int i = 0, j = 0, cnt = 0; i < n; ++i) {
            cnt += S[i] == '1' ? 1 : -1;
            if (cnt == 0) {
                v.push_back('1' + makeLargestSpecial(S.substr(j + 1, i - j - 1)) + '0');
                j = i + 1;
            }
        }
        sort(v.begin(), v.end(), greater<string>());
        string ans;
        for (auto &s : v) ans += s;
        return ans;
    }
};

int main()
{
    Solution obj;
    cout << obj.makeLargestSpecial("11011000") << endl;
    return 0;
}
