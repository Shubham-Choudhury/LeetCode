// Link: https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int maxScore(vector<int>& cardPoints, int k){
        int n = cardPoints.size();
        int sum = 0;
        for(int i = 0; i < k; i++){
            sum += cardPoints[i];
        }
        int ans = sum;
        for(int i = 0; i < k; i++){
            sum -= cardPoints[k - i - 1];
            sum += cardPoints[n - i - 1];
            ans = max(ans, sum);
        }
        return ans;
    }
};

int main(){
    Solution sol;
    vector<int> cardPoints = {1,2,3,4,5,6,1};
    int k = 3;
    int ans = sol.maxScore(cardPoints, k);
    cout << ans << endl;
    return 0;
}