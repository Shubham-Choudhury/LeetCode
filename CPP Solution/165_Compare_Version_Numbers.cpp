// Link: https://leetcode.com/problems/compare-version-numbers/

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Solution
{
public:
    int compareVersion(string version1, string version2)
    {
        stringstream ss1(version1);
        stringstream ss2(version2);
        string s1, s2;
        getline(ss1, s1, '.');
        getline(ss2, s2, '.');
        while (s1.size() != 0 || s2.size() != 0)
        {
            if (s1.size() == 0)
                s1 = "0";
            if (s2.size() == 0)
                s2 = "0";
            if (stoi(s1) > stoi(s2))
                return 1;
            else if (stoi(s1) < stoi(s2))
                return -1;
            else
                s1 = "", s2 = "";
            getline(ss1, s1, '.');
            getline(ss2, s2, '.');
        }
        return 0;
    }
};

int main()
{
    Solution a;
    cout << a.compareVersion("1.01", "1.001") << endl;
    cout << a.compareVersion("1.0", "1.0.0") << endl;
    cout << a.compareVersion("0.1", "1.1") << endl;
    cout << a.compareVersion("1.0.1", "1") << endl;
    return 0;
}
