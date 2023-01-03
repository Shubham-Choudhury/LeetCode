// Link: https://leetcode.com/problems/validate-stack-sequences/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool validateStackSequences(vector<int> &pushed, vector<int> &popped)
    {
        stack<int> s;
        int i = 0;
        for (int num : pushed)
        {
            s.push(num);
            while (!s.empty() && s.top() == popped[i])
            {
                s.pop();
                i++;
            }
        }
        return s.empty();
    }
};

int main()
{
    Solution sol;
    vector<int> pushed = {1, 2, 3, 4, 5};
    vector<int> popped = {4, 5, 3, 2, 1};
    cout << sol.validateStackSequences(pushed, popped) << endl;
    return 0;
}
