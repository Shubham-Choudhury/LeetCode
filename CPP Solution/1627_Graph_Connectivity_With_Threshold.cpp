// Link: https://leetcode.com/problems/graph-connectivity-with-threshold/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<bool> areConnected(int n, int threshold, vector<vector<int>>& queries) {
        vector<bool> ans;
        vector<int> par(n+1);
        for(int i=1;i<=n;i++) par[i]=i;
        for(int i=threshold+1;i<=n;i++){
            for(int j=2*i;j<=n;j+=i){
                int x = find(par,i);
                int y = find(par,j);
                if(x!=y) par[x]=y;
            }
        }
        for(auto q:queries){
            int x = find(par,q[0]);
            int y = find(par,q[1]);
            ans.push_back(x==y);
        }
        return ans;
    }
    int find(vector<int>& par,int x){
        if(par[x]==x) return x;
        return par[x]=find(par,par[x]);
    }
};

int main()
{
    Solution a;
    vector<vector<int>> b = {{1, 4}, {2, 5}, {3, 6}};
    for (auto i : a.areConnected(6, 2, b))
        cout << i << " ";
    return 0;
}