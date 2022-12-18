// Link: https://leetcode.com/problems/find-in-mountain-array/

#include <iostream>
#include <vector>
using namespace std;

class MountainArray
{
public:
    int get(int index);
    int length();
};

class Solution
{
public:
    int findInMountainArray(int target, MountainArray &mountainArr)
    {
        int n = mountainArr.length();
        int l = 0, r = n - 1;
        while (l < r)
        {
            int m = l + (r - l) / 2;
            if (mountainArr.get(m) < mountainArr.get(m + 1))
                l = m + 1;
            else
                r = m;
        }
        int peak = l;
        l = 0, r = peak;
        while (l < r)
        {
            int m = l + (r - l) / 2;
            if (mountainArr.get(m) < target)
                l = m + 1;
            else
                r = m;
        }
        if (mountainArr.get(l) == target)
            return l;
        l = peak, r = n - 1;
        while (l < r)
        {
            int m = l + (r - l) / 2;
            if (mountainArr.get(m) > target)
                l = m + 1;
            else
                r = m;
        }
        if (mountainArr.get(l) == target)
            return l;
        return -1;
    }
};

int main()
{
    Solution s;
    MountainArray mountainArr;
    int target = 0;
    cout << s.findInMountainArray(target, mountainArr) << endl;
    return 0;
}
