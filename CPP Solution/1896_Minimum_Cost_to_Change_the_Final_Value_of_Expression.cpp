// Link: https://leetcode.com/problems/minimum-cost-to-change-the-final-value-of-expression/

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    Node(int n, int o)
    {
        Num = n;
        Op = o;
        Cnts[0] = INT_MAX;
        Cnts[1] = INT_MAX;
    }

    int Num;
    char Op;
    int Cnts[2];
};

class Solution
{
public:
    vector<int> pos;
    int n;
    int minOperationsToFlip(string expression)
    {
        stack<Node> stk;
        vector<Node> out;
        for (int i = 0; i < expression.size(); ++i)
        {
            if (expression[i] == '(')
            {
                stk.push(Node(0, '('));
            }
            else if (expression[i] == '0' || expression[i] == '1')
            {
                stk.push(Node(expression[i] - '0', ' '));
            }
            else if (expression[i] == ')')
            {
                while (stk.size() > 0 && stk.top().Op != '(')
                {
                    out.push_back(stk.top());
                    stk.pop();
                }
                stk.pop();
            }
            else
            {
                while (stk.size() > 0 && stk.top().Op != '(')
                {
                    out.push_back(stk.top());
                    stk.pop();
                }
                stk.push(Node(0, expression[i]));
            }
        }
        while (stk.size() > 0)
        {
            out.push_back(stk.top());
            stk.pop();
        }

        // Evalute reverse polish notation by DP.
        for (int i = 0; i < out.size(); ++i)
        {
            if (out[i].Op == ' ')
            {
                if (out[i].Num == 0)
                {
                    out[i].Cnts[0] = 0;
                    out[i].Cnts[1] = 1;
                }
                else
                {
                    out[i].Cnts[1] = 0;
                    out[i].Cnts[0] = 1;
                }
                stk.push(out[i]);
            }
            else if (out[i].Op == '|')
            {
                Node v1 = stk.top();
                stk.pop();
                Node v0 = stk.top();
                stk.pop();

                Node newNode(0, ' ');
                // 0 | 0
                newNode.Cnts[0] = min(newNode.Cnts[0], v0.Cnts[0] + v1.Cnts[0]);
                // 0 | 1
                newNode.Cnts[1] = min(newNode.Cnts[1], v0.Cnts[0] + v1.Cnts[1]);
                // 1 | 0
                newNode.Cnts[1] = min(newNode.Cnts[1], v0.Cnts[1] + v1.Cnts[0]);
                // 1 | 1
                newNode.Cnts[1] = min(newNode.Cnts[1], v0.Cnts[1] + v1.Cnts[1]);

                // 0 & 0
                newNode.Cnts[0] = min(newNode.Cnts[0], v0.Cnts[0] + v1.Cnts[0] + 1);
                // 0 & 1
                newNode.Cnts[0] = min(newNode.Cnts[0], v0.Cnts[0] + v1.Cnts[1] + 1);
                // 1 & 0
                newNode.Cnts[0] = min(newNode.Cnts[0], v0.Cnts[1] + v1.Cnts[0] + 1);
                // 1 & 1
                newNode.Cnts[1] = min(newNode.Cnts[1], v0.Cnts[1] + v1.Cnts[1] + 1);

                stk.push(newNode);
            }
            else if (out[i].Op == '&')
            {
                Node v1 = stk.top();
                stk.pop();
                Node v0 = stk.top();
                stk.pop();

                Node newNode(0, ' ');
                // 0 | 0
                newNode.Cnts[0] = min(newNode.Cnts[0], v0.Cnts[0] + v1.Cnts[0] + 1);
                // 0 | 1
                newNode.Cnts[1] = min(newNode.Cnts[1], v0.Cnts[0] + v1.Cnts[1] + 1);
                // 1 | 0
                newNode.Cnts[1] = min(newNode.Cnts[1], v0.Cnts[1] + v1.Cnts[0] + 1);
                // 1 | 1
                newNode.Cnts[1] = min(newNode.Cnts[1], v0.Cnts[1] + v1.Cnts[1] + 1);

                // 0 & 0
                newNode.Cnts[0] = min(newNode.Cnts[0], v0.Cnts[0] + v1.Cnts[0]);
                // 0 & 1
                newNode.Cnts[0] = min(newNode.Cnts[0], v0.Cnts[0] + v1.Cnts[1]);
                // 1 & 0
                newNode.Cnts[0] = min(newNode.Cnts[0], v0.Cnts[1] + v1.Cnts[0]);
                // 1 & 1
                newNode.Cnts[1] = min(newNode.Cnts[1], v0.Cnts[1] + v1.Cnts[1]);

                stk.push(newNode);
            }
        }

        return max(stk.top().Cnts[0], stk.top().Cnts[1]);
    }
};

int main()
{
    Solution s;
    cout << s.minOperationsToFlip("1^0|0|1") << endl;
    cout << s.minOperationsToFlip("(0&0)&(0&0&0)") << endl;
    cout << s.minOperationsToFlip("(0|(1|0&1))") << endl;
    return 0;
}