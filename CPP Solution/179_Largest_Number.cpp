// Link: https://leetcode.com/problems/largest-number/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    string largestNumber(vector<int> &nums)
    {
        vector<string> s;
        for (int i = 0; i < nums.size(); i++)
            s.push_back(to_string(nums[i]));
        sort(s.begin(), s.end(), [](string a, string b) { return a + b > b + a; });
        string res;
        for (int i = 0; i < s.size(); i++)
            res += s[i];
        while (res.size() > 1 && res[0] == '0')
            res.erase(0, 1);
        return res;
    }
};

int main()
{
    Solution a;
    vector<int> nums = {3, 30, 34, 5, 9};
    cout << a.largestNumber(nums) << endl;
    return 0;
}
