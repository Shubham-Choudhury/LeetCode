// Link: https://leetcode.com/problems/self-crossing/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool isSelfCrossing(vector<int>& x) {
        int n = x.size();
        if (n <= 3)
            return false;
        for (int i = 3; i < n; i++) {
            if (x[i] >= x[i - 2] && x[i - 1] <= x[i - 3])
                return true;
            if (i >= 4 && x[i - 1] == x[i - 3] && x[i] + x[i - 4] >= x[i - 2])
                return true;
            if (i >= 5 && x[i - 2] >= x[i - 4] && x[i - 3] >= x[i - 1] && x[i - 1] + x[i - 5] >= x[i - 3] && x[i] + x[i - 4] >= x[i - 2])
                return true;
        }
        return false;
    }
};

int main() {
    Solution sol;
    vector<int> x;
    bool res;
    
    // Output: true
    x = {2, 1, 1, 2};
    res = sol.isSelfCrossing(x);
    cout << res << endl;
    
    // Output: true
    x = {1, 2, 3, 4};
    res = sol.isSelfCrossing(x);
    cout << res << endl;
    
    // Output: false
    x = {1, 1, 1, 1};
    res = sol.isSelfCrossing(x);
    cout << res << endl;
    
    // Output: true
    x = {1, 1, 2, 1, 1};
    res = sol.isSelfCrossing(x);
    cout << res << endl;
    
    // Output: true
    x = {3, 3, 4, 2, 2};
    res = sol.isSelfCrossing(x);
    cout << res << endl;
    
    // Output: false
    x = {1, 1, 2, 2, 1, 1};
    res = sol.isSelfCrossing(x);
    cout << res << endl;
    
    // Output: true
    x = {1, 1, 2, 1, 1};
    res = sol.isSelfCrossing(x);
    cout << res << endl;
    
    // Output: true
    x = {1, 1, 1, 1};
    res = sol.isSelfCrossing(x);
    cout << res << endl;
    
    // Output: true
    x = {1, 2, 3, 4, 1, 1, 1};
    res = sol.isSelfCrossing(x);
    cout << res << endl;
    
    // Output: true
    x = {1, 1, 2, 2, 1, 1, 1};
    res = sol.isSelfCrossing(x);
    cout << res << endl;
    
    // Output: true
    x = {1, 1, 2, 1, 1, 1};
    res = sol.isSelfCrossing(x);
    cout << res << endl;
    
    return 0;
}