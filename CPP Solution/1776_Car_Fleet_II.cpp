// Link: https://leetcode.com/problems/car-fleet-ii/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<double> getCollisionTimes(vector<vector<int>>& cars) {
        int n = cars.size();
        vector<double> ans(n, -1);
        stack<int> s;
        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty()) {
                int j = s.top();
                if (cars[i][1] <= cars[j][1]) {
                    s.pop();
                } else {
                    double t = (cars[j][0] - cars[i][0]) / (double)(cars[i][1] - cars[j][1]);
                    if (t <= ans[j] || ans[j] < 0) {
                        ans[i] = t;
                        break;
                    } else {
                        s.pop();
                    }
                }
            }
            s.push(i);
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> cars;
    vector<double> ans;

    // Output: [-1.00000,3.00000,3.00000,-1.00000]
    cars = {{1,2},{2,1},{4,3},{7,2}};
    ans = sol.getCollisionTimes(cars);
    for (double x: ans) {
        cout << x << " ";
    }
    cout << endl;

    // Output: [2.00000,1.00000,1.50000,-1.00000]
    cars = {{3,4},{5,4},{6,3},{9,1}};
    ans = sol.getCollisionTimes(cars);
    for (double x: ans) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}