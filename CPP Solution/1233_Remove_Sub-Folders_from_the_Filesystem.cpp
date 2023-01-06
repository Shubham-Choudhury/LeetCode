// Link: https://leetcode.com/problems/remove-sub-folders-from-the-filesystem/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> removeSubfolders(vector<string> &folder)
    {
        sort(folder.begin(), folder.end());
        vector<string> res;
        res.push_back(folder[0]);
        for (int i = 1; i < folder.size(); i++)
        {
            if (folder[i].find(res.back() + "/") != 0)
                res.push_back(folder[i]);
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<string> folder1 = {"/a", "/a/b", "/c/d", "/c/d/e", "/c/f"};
    vector<string> folder2 = {"/a", "/a/b/c", "/a/b/d"};
    vector<string> folder3 = {"/a/b/c", "/a/b/ca", "/a/b/d"};
    for (auto i : s.removeSubfolders(folder1))
        cout << i << " ";
    cout << endl;
    for (auto i : s.removeSubfolders(folder2))
        cout << i << " ";
    cout << endl;
    for (auto i : s.removeSubfolders(folder3))
        cout << i << " ";
    cout << endl;
    return 0;
}
