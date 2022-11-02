// Link: https://leetcode.com/problems/richest-customer-wealth/?envType=study-plan&id=programming-skills-i

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int maximumWealth(vector<vector<int>> &accounts)
    {
        int maxi = 0;

        for (int i = 0; i < accounts.size(); i++)
        {
            int sum = 0;

            for (int j = 0; j < accounts[i].size(); j++)
            {
                sum += accounts[i][j];
            }

            maxi = max(maxi, sum);
        }

        return maxi;
    }
};

int main()
{
    vector<vector<int>> accounts = {{1, 2, 3}, {3, 2, 1}};
    Solution obj;
    cout << obj.maximumWealth(accounts);
    return 0;
}