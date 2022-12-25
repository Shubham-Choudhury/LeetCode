// Link: https://leetcode.com/problems/distribute-repeating-integers/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    // dp table defined by two variables:-
    // 1. index->let uniqueValues be the array representing all the unique values present in nums
    // then index tells us which index of that array we are on
    // 2. mask-> a bitmask which tells us which orders have been fullfilled
    vector<vector<int>> mem;
    // stores the total quantity demanded for a particular set of orders
    vector<int> total;
    // stores the count of the unique values present in nums
    unordered_map<int, int> cnts;
    int findTotalQuantity(vector<int> &quantity, int mask)
    {
        int ans = 0;
        // iterate thorugh the bitmask by setting the rightmost bit to zero, and add the
        // quantity of that position to the answer.
        while (mask)
        {
            int pos = log2(mask & (-mask));
            mask -= mask & (-mask);
            ans += quantity[pos];
        }
        return ans;
    }
    // for subset of unfullfilled orders we will see if the current index has enough frequency
    // to cover the total quantity demanded by the subset, if yes then mark that subset in the mask
    // and perform a recursive call, if any of them return true, then return true, else return false.
    bool solve(vector<int> &uniqueValues, int index, int mask)
    {
        int size = total.size();
        int m = log2(size);
        if (mask == (1 << m) - 1)
        {
            return true;
        }
        else if (index == uniqueValues.size())
        {
            return false;
        }
        else if (mem[index][mask] != -1)
        {
            return mem[index][mask];
        }
        else
        {
            // ignore the current index and move on
            bool ans = solve(uniqueValues, index + 1, mask);
            if (ans)
            {
                return mem[index][mask] = true;
            }
            else
            {
                // try every possible subset of the orders that have not been completed
                int remainingOrders = ((1 << m) - 1) ^ mask;
                int value = uniqueValues[index];
                for (int submask = remainingOrders; submask > 0; submask = (submask - 1) & remainingOrders)
                {
                    if (cnts[value] >= total[submask])
                    {
                        if (solve(uniqueValues, index + 1, mask | submask))
                        {
                            return mem[index][mask] = true;
                        }
                    }
                }
                return mem[index][mask] = false;
            }
        }
    }

public:
    bool canDistribute(vector<int> &nums, vector<int> &quantity)
    {
        int m = quantity.size();
        for (int i = 0; i < nums.size(); i++)
        {
            cnts[nums[i]]++;
        }
        vector<int> uniqueValues;
        for (unordered_map<int, int>::iterator it = cnts.begin(); it != cnts.end(); it++)
        {
            uniqueValues.push_back(it->first);
        }
        int n = uniqueValues.size();
        mem = vector<vector<int>>(n, vector<int>(1 << m, -1));
        total = vector<int>(1 << m, -1);
        for (int mask = 0; mask < (1 << m); mask++)
        {
            total[mask] = findTotalQuantity(quantity, mask);
        }
        return solve(uniqueValues, 0, 0);
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 2, 3, 4};
    vector<int> quantity = {2};
    cout << sol.canDistribute(nums, quantity) << endl;
    return 0;
}