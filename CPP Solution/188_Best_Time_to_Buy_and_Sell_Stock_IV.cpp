// Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <climits>
using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if (n <= 1) {
            return 0;
        }
        if (k >= n / 2) {
            int result = 0;
            for (int i = 1; i < n; i++) {
                if (prices[i] > prices[i - 1]) {
                    result += prices[i] - prices[i - 1];
                }
            }
            return result;
        }
        vector<int> buy(k + 1, INT_MIN);
        vector<int> sell(k + 1, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 1; j <= k; j++) {
                buy[j] = max(buy[j], sell[j - 1] - prices[i]);
                sell[j] = max(sell[j], buy[j] + prices[i]);
            }
        }
        return sell[k];
    }
};

int main() {
    Solution sol;
    vector<int> prices;
    int k;
    int result;
    
    prices = {2,4,1};
    k = 2;
    result = sol.maxProfit(k, prices);
    cout << result << endl;
    
    prices = {3,2,6,5,0,3};
    k = 2;
    result = sol.maxProfit(k, prices);
    cout << result << endl;
    
    prices = {3,2,6,5,0,3};
    k = 3;
    result = sol.maxProfit(k, prices);
    cout << result << endl;
    
    prices = {3,2,6,5,0,3};
    k = 4;
    result = sol.maxProfit(k, prices);
    cout << result << endl;
    
    prices = {3,2,6,5,0,3};
    k = 5;
    result = sol.maxProfit(k, prices);
    cout << result << endl;
    
    prices = {3,2,6,5,0,3};
    k = 6;
    result = sol.maxProfit(k, prices);
    cout << result << endl;
    
    prices = {3,2,6,5,0,3};
    k = 7;
    result = sol.maxProfit(k, prices);
    cout << result << endl;
    
    prices = {3,2,6,5,0,3};
    k = 8;
    result = sol.maxProfit(k, prices);
    cout << result << endl;
    
    prices = {3,2,6,5,0,3};
    k = 9;
    result = sol.maxProfit(k, prices);
    cout << result << endl;
    
    prices = {3,2,6,5,0,3};
    k = 10;
    result = sol.maxProfit(k, prices);
    cout << result << endl;
    
    prices = {3,2,6,5,0,3};
    k = 11;
    result = sol.maxProfit(k, prices);
    cout << result << endl;
    
    prices = {3,2,6,5,0,3};
    k = 12;
    result = sol.maxProfit(k, prices);
    cout << result << endl;
    
    return 0;
}