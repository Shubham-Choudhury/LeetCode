// Link: https://leetcode.com/problems/brace-expansion-ii/

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <stack>
using namespace std;

class Solution {
public:
    vector<string> braceExpansionII(string& expression) {
        size_t pos = 0;
        expression = "{" + expression + "}";
        auto ret = ParseChunk(expression, pos);
        return vector<string>(ret.begin(), ret.end());
    }

    set<string> ParseChunk(string& str, size_t& pos) {
        size_t idx = pos;
        if (str[pos] != '{') {  // parse lowercase letter string
            while (pos < str.size() && str[pos] >= 'a' && str[pos] <= 'z') ++pos;
            return set<string>{str.substr(idx, pos - idx) };
        }
        else {  // parse {...} chuck
            stack<set<string>> stk;
            stk.push(ParseChunk(str, ++pos));   // parse the first subchunk
            while (str[pos] != '}') {           // parse subsequent subchunks
                if (str[pos] == ',') stk.push(ParseChunk(str, ++pos));  // delay to union next subchunk
                else {                          // concatenate next subchunk
                    auto ans = Concatenate(stk.top(), ParseChunk(str, pos));
                    stk.pop();
                    stk.push(ans);
                }
            }
            ++pos;

			// union all residual subchunks
            auto ret = move(stk.top());
            stk.pop();
            while (!stk.empty()) {
                Union(ret, stk.top());
                stk.pop();
            }
            return ret;
        }
    }

    void Union(set<string>& s1, set<string>& s2) {
        s1.insert(s2.begin(), s2.end());
    }

    set<string> Concatenate(set<string>& s1, set<string>&& s2) {
        set<string> ret;
        for (auto& str1 : s1) {
            for (auto& str2 : s2) {
                ret.insert(str1 + str2);
            }
        }
        return ret;
    }
};

int main()
{
    Solution s;
    string expression = "{a,b}{c,{d,e}}";
    vector<string> res = s.braceExpansionII(expression);
    for (string &s : res)
        cout << s << endl;
    return 0;
}
