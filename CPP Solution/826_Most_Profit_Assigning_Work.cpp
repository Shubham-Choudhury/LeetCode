// Link: https://leetcode.com/problems/most-profit-assigning-work/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n=difficulty.size();
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++){
            v.push_back({difficulty[i],profit[i]});
        }
        sort(v.begin(),v.end());
        sort(worker.begin(),worker.end());
        int ans=0;
        int i=0;
        int mx=0;
        for(int j=0;j<worker.size();j++){
            while(i<n && v[i].first<=worker[j]){
                mx=max(mx,v[i].second);
                i++;
            }
            ans+=mx;
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> difficulty = {2,4,6,8,10};
    vector<int> profit = {10,20,30,40,50};
    vector<int> worker = {4,5,6,7};
    cout << s.maxProfitAssignment(difficulty, profit, worker) << endl;
    return 0;
}