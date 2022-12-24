// Link: https://leetcode.com/problems/kth-ancestor-of-a-tree-node/

#include <bits/stdc++.h>
using namespace std;

class TreeAncestor {
public:
    int dp[50005][20];
    TreeAncestor(int n, vector<int>& parent) {
        for(int i=0;i<n;i++){
            for(int j=0;j<20;j++){
                dp[i][j]=-1;
            }
        }
        for(int i=0;i<n;i++){
            dp[i][0]=parent[i];
        }
        for(int j=1;j<20;j++){
            for(int i=0;i<n;i++){
                if(dp[i][j-1]!=-1){
                    dp[i][j]=dp[dp[i][j-1]][j-1];
                }
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        for(int i=0;i<20;i++){
            if(k&(1<<i)){
                node=dp[node][i];
                if(node==-1){
                    return -1;
                }
            }
        }
        return node;
    }
};

int main()
{
    vector<int> parent = {-1, 0, 0, 1, 1, 2, 2};
    TreeAncestor *obj = new TreeAncestor(7, parent);
    cout << obj->getKthAncestor(3, 1) << endl;
    cout << obj->getKthAncestor(5, 2) << endl;
    cout << obj->getKthAncestor(6, 3) << endl;
    return 0;
}
