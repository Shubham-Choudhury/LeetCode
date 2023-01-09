// Link: https://leetcode.com/problems/filter-restaurants-by-vegan-friendly-price-and-distance/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) {
        vector<int> ans;
        for (int i = 0; i < restaurants.size(); i++) {
            if (restaurants[i][2] >= veganFriendly && restaurants[i][3] <= maxPrice && restaurants[i][4] <= maxDistance) {
                ans.push_back(i);
            }
        }
        sort(ans.begin(), ans.end(), [&](int a, int b) {
            if (restaurants[a][1] == restaurants[b][1]) {
                return restaurants[a][0] > restaurants[b][0];
            }
            return restaurants[a][1] > restaurants[b][1];
        });
        vector<int> res;
        for (int i = 0; i < ans.size(); i++) {
            res.push_back(restaurants[ans[i]][0]);
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> restaurants = {{1,4,1,40,10}, {2,8,0,50,5}, {3,8,1,30,4}, {4,10,0,10,3}, {5,1,1,15,1}};
    int veganFriendly = 1;
    int maxPrice = 50;
    int maxDistance = 10;
    vector<int> ans = sol.filterRestaurants(restaurants, veganFriendly, maxPrice, maxDistance);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}
