// Link: https://leetcode.com/problems/verify-preorder-serialization-of-a-binary-tree/

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <cassert>
using namespace std;

class Solution
{
public:
    bool isValidSerialization(string preorder)
    {
        istringstream iss(preorder);
        vector<string> nodes;
        string node;
        while (getline(iss, node, ','))
        {
            nodes.push_back(node);
        }
        int diff = 1;
        for (string node : nodes)
        {
            if (--diff < 0)
            {
                return false;
            }
            if (node != "#")
            {
                diff += 2;
            }
        }
        return diff == 0;
    }
};

int main()
{
    Solution solution;
    string preorder = "9,3,4,#,#,1,#,#,2,#,6,#,#";
    cout << solution.isValidSerialization(preorder) << endl;
    return 0;
}