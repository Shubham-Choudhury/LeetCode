// Link: https://leetcode.com/problems/count-pairs-with-xor-in-a-range/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int trie[1 << 17];
    int countPairs(vector<int> &nums, int low, int high)
    {
        for (int i = 0; i < (1 << 17); ++i)
        {
            trie[i] = 0;
        }
        int res = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            int cnt = Search(15, 1, nums[i], 0, low) - Search(15, 1, nums[i], 0, high + 1);
            res += cnt;
            Insert(15, 1, nums[i]);
        }
        return res;
    }

    void Insert(int bitPos, int index, int val)
    {
        if (bitPos < 0)
        {
            trie[index] += 1;
            return;
        }
        if (!(val & (1 << bitPos)))
            Insert(bitPos - 1, index * 2, val);
        else
            Insert(bitPos - 1, index * 2 + 1, val);
        trie[index] = trie[index * 2] + trie[index * 2 + 1];
    }

    int Search(int bitPos, int index, int val, int xorVal, int threshold)
    {
        if (bitPos < 0)
        {
            if (xorVal >= threshold)
                return trie[index];
            return 0;
        }
        if (xorVal >= threshold)
            return trie[index];
        int mask = (1 << (bitPos + 1)) - 1;
        if ((xorVal | mask) < threshold)
            return 0;

        int ret = 0;
        if (val & (1 << bitPos))
        {
            ret += Search(bitPos - 1, index * 2, val, xorVal | (1 << bitPos), threshold);
            ret += Search(bitPos - 1, index * 2 + 1, val, xorVal, threshold);
        }
        else
        {
            ret += Search(bitPos - 1, index * 2, val, xorVal, threshold);
            ret += Search(bitPos - 1, index * 2 + 1, val, xorVal | (1 << bitPos), threshold);
        }
        return ret;
    }
};

int main()
{
    Solution sol;
    vector<int> nums;
    int low, high, ans;

    // Output: 8
    nums = {1, 4, 2, 7}, low = 2, high = 6;
    ans = sol.countPairs(nums, low, high);
    cout << ans << endl;
    return 0;
}
