// Link: https://leetcode.com/problems/maximum-bags-with-full-capacity-of-rocks/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks){
        int n = capacity.size();
        int m = rocks.size();
        sort(rocks.begin(), rocks.end());
        vector<int> prefix(m);
        prefix[0] = rocks[0];
        for(int i = 1; i < m; i++){
            prefix[i] = prefix[i - 1] + rocks[i];
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            int idx = upper_bound(rocks.begin(), rocks.end(), capacity[i]) - rocks.begin();
            if(idx == 0){
                continue;
            }
            --idx;
            int sum = (idx + 1) + additionalRocks;
            sum -= (prefix[idx] - (i > 0 ? prefix[i - 1] : 0));
            ans = max(ans, sum);
        }
        return ans;
    }
};

int main(){
    Solution s;
    vector<int> capacity = {1, 2, 3};
    vector<int> rocks = {1, 2, 3};
    int additionalRocks = 1;
    cout << s.maximumBags(capacity, rocks, additionalRocks) << endl;
    return 0;
}
