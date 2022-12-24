// Link: https://leetcode.com/problems/find-a-value-of-a-mysterious-function-closest-to-target/

#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int closestToTarget(vector<int>& arr, int target) {
        int n = arr.size();
        int limit = log2(n+1)+1;
        vector<vector<int>>table(n,vector<int>(limit));
        for(int i = 0 ; i < n ; i ++){
            table[i][0] = arr[i];
        }
        for(int i = 1 ; i < limit ; i ++){
            for(int j = 0 ; j + (1<<i) <= n ; j ++){
                table[j][i] = table[j][i-1] & table[j+(1<<(i-1))][i-1];
            }
        }
        auto get_and =  [&](int l , int r){
            int s = log2(r-l +1);
            return table[l][s] & table[r-(1<<s)+1][s];
        };
      
        int ans = 1e9;
        for(int i = 0; i < n ; i ++){
            int l = 1 ;
            int r = n - i ;
            while(l<=r){
                int mid = (l+r)/2;
                int mask = get_and(i,i+mid-1);
                 ans =min (ans,abs(mask - target));
                 if(ans == 0)return ans;
                if(mask < target){
                    r = mid - 1 ;
                }else{
                    l = mid + 1 ;
                }
            }
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> arr;
    int target, ans;

    // Output: 2
    arr = {9, 12, 3, 7, 15};
    target = 5;
    ans = sol.closestToTarget(arr, target);
    cout << ans << endl;

    // Output: 0
    arr = {1000000, 1000000, 1000000};
    target = 1;
    ans = sol.closestToTarget(arr, target);
    cout << ans << endl;

    // Output: 1
    arr = {1, 2, 4, 8, 16};
    target = 0;
    ans = sol.closestToTarget(arr, target);
    cout << ans << endl;

    return 0;
}
