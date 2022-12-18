// Link: https://leetcode.com/problems/can-i-win/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if (desiredTotal <= maxChoosableInteger)
            return true;
        if (desiredTotal > (1 + maxChoosableInteger) * maxChoosableInteger / 2)
            return false;
        vector<bool> used(maxChoosableInteger + 1, false);
        unordered_map<int, bool> memo;
        return canIWin(desiredTotal, used, memo);
    }
    
    bool canIWin(int desiredTotal, vector<bool>& used, unordered_map<int, bool>& memo) {
        if (desiredTotal <= 0)
            return false;
        int key = format(used);
        if (memo.count(key))
            return memo[key];
        for (int i = 1; i < used.size(); ++ i)
        {
            if (!used[i])
            {
                used[i] = true;
                if (!canIWin(desiredTotal - i, used, memo))
                {
                    used[i] = false;
                    memo[key] = true;
                    return true;
                }
                used[i] = false;
            }
        }
        memo[key] = false;
        return false;
    }
    
    int format(vector<bool>& used) {
        int n = used.size();
        int key = 0;
        for (int i = 0; i < n; ++ i)
            key = key * 2 + used[i];
        return key;
    }
};

int main() {
    Solution sol;
    int maxChoosableInteger, desiredTotal;
    bool res;

    // Output: true
    maxChoosableInteger = 10;
    desiredTotal = 11;
    res = sol.canIWin(maxChoosableInteger, desiredTotal);
    cout << res << endl;

    // Output: false
    maxChoosableInteger = 10;
    desiredTotal = 40;
    res = sol.canIWin(maxChoosableInteger, desiredTotal);
    cout << res << endl;

    return 0;
}
