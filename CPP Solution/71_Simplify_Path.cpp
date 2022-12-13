// Link: https://leetcode.com/problems/simplify-path/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    string simplifyPath(string path)
    {
        vector<string> v;
        string tmp;
        for (int i = 0; i < path.size(); ++i)
        {
            if (path[i] == '/')
            {
                if (tmp == "..")
                {
                    if (!v.empty())
                        v.pop_back();
                }
                else if (tmp != "." && tmp != "")
                    v.push_back(tmp);
                tmp = "";
            }
            else
                tmp += path[i];
        }
        if (tmp == "..")
        {
            if (!v.empty())
                v.pop_back();
        }
        else if (tmp != "." && tmp != "")
            v.push_back(tmp);
        string res;
        for (auto i : v)
            res += "/" + i;
        return res == "" ? "/" : res;
    }
};

int main()
{
    Solution s;
    cout << s.simplifyPath("/home/") << endl;
    cout << s.simplifyPath("/../") << endl;
    cout << s.simplifyPath("/home//foo/") << endl;
    cout << s.simplifyPath("/a/./b/../../c/") << endl;
    cout << s.simplifyPath("/a/../../b/../c//.//") << endl;
    cout << s.simplifyPath("/a//b////c/d//././/..") << endl;
    return 0;
}

