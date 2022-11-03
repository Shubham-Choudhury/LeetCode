// Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/?envType=study-plan&id=dynamic-programming-i

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] > prices[i - 1]) {
                res += prices[i] - prices[i - 1];
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    int res = s.maxProfit(prices);
    return 0;
}