// Link: https://leetcode.com/problems/largest-component-size-by-common-factor/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
using namespace std;

class Solution
{
public:
     int findpar(int node,vector<int> &par){
        if(par[node]==node) return node;

        return par[node]=findpar(par[node],par);
    }
    
    void unionbyrank(int x,int y,vector<int> &par,vector<int> &rank){
        
        int u=findpar(x,par);
        int v=findpar(y,par);
        
        if(rank[u]>rank[v]){
        par[v]=u;
      
     
    }
    else if(rank[v]>rank[u]){
         par[u]=v;
         
      
    }
    else{
        par[v]=u;
        rank[u]++;
       
    }
    }
    int largestComponentSize(vector<int>& nums) {

        int count=1e5+3;

        

        vector<int> par(count);
        vector<int> rank(count);
        
        for(int i=0;i<count;i++){
            par[i]=i;
            rank[i]=1;
        }
        
        
        for(auto x: nums){
            
            for(int i=2;i<=sqrt(x);i++){
                
                if(x%i==0){
                    
                    
                        unionbyrank(x,i,par,rank);
                        unionbyrank(i,x/i,par,rank);

                }
            }
        }
        
        unordered_map<int,int> mp;
        
        for(auto x: nums){
          
            mp[par[findpar(x,par)]]++;
        }
        
        int maxcmp=0;
        for(auto x: mp){
            maxcmp=max(maxcmp,x.second);
        }
        
        return maxcmp;
    }
};

int main()
{
    Solution a;
    vector<int> b = {4, 6, 15, 35};
    cout << a.largestComponentSize(b) << endl;
    return 0;
}
