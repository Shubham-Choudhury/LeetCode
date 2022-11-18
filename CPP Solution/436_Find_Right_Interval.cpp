// Link: https://leetcode.com/problems/find-right-interval/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n=intervals.size();
        vector<int> ans(n,-1);
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++){
            v.push_back({intervals[i][0],i});
        }
        sort(v.begin(),v.end());
        for(int i=0;i<n;i++){
            int l=0;
            int r=n-1;
            int idx=-1;
            while(l<=r){
                int mid=l+(r-l)/2;
                if(v[mid].first>=intervals[i][1]){
                    idx=v[mid].second;
                    r=mid-1;
                }
                else{
                    l=mid+1;
                }
            }
            ans[i]=idx;
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<vector<int>> intervals = {{1,2}};
    vector<int> result = s.findRightInterval(intervals);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    return 0;
}