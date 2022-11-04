// Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/?envType=study-plan&id=dynamic-programming-i

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n == 0) {
            return 0;
        }
        vector<int> buy(n, 0);
        vector<int> sell(n, 0);
        buy[0] = -prices[0];
        for(int i = 1; i < n; i++) {
            buy[i] = max(buy[i - 1], (i >= 2 ? sell[i - 2] : 0) - prices[i]);
            sell[i] = max(sell[i - 1], buy[i - 1] + prices[i]);
        }
        return sell[n - 1];
    }
};

int main() {
    Solution s;
    vector<int> prices = {1,2,3,0,2};
    cout << s.maxProfit(prices) << endl;
    return 0;
}