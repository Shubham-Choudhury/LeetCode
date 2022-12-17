// Link: https://leetcode.com/problems/mini-parser/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <climits>
#include <stack>
using namespace std;

class NestedInteger
{
public:
    // Constructor initializes an empty nested list.
    NestedInteger();

    // Constructor initializes a single integer.
    NestedInteger(int value);

    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;

    // Set this NestedInteger to hold a single integer.
    void setInteger(int value);

    // Set this NestedInteger to hold a nested list and adds a nested integer to it.
    void add(const NestedInteger &ni);

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};

class Solution
{
public:
    NestedInteger deserialize(string s)
    {
        stack<NestedInteger> stk;
        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '[')
            {
                stk.push(NestedInteger());
            }
            else if (s[i] == ']')
            {
                if (stk.size() > 1)
                {
                    NestedInteger ni = stk.top();
                    stk.pop();
                    stk.top().add(ni);
                }
            }
            else if (s[i] == ',')
            {
                continue;
            }
            else
            {
                int j = i;
                while (j < n && s[j] != ',' && s[j] != ']')
                {
                    j++;
                }
                int num = stoi(s.substr(i, j - i));
                if (stk.empty())
                {
                    stk.push(NestedInteger(num));
                }
                else
                {
                    stk.top().add(NestedInteger(num));
                }
                i = j - 1;
            }
        }
        return stk.top();
    }
};

int main()
{
    Solution s;
    string str = "[123,[456,[789]]]";
    NestedInteger ni = s.deserialize(str);
    return 0;
}