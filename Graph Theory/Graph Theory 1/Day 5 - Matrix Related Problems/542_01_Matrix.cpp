// Link: https://leetcode.com/problems/01-matrix/?envType=study-plan&id=graph-i

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& grid) {
         int n=grid.size();
	    int m=grid[0].size();
	    
	    vector<vector<int>>ans(n,vector<int>(m,0));
	    vector<vector<int>>vis(n,vector<int>(m,0));
	    
	    queue<pair<pair<int,int>,int>>q;
	    
	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++){
	            if(grid[i][j]==0){
	                q.push({{i,j},0});
	                vis[i][j]=1;
	            }else vis[i][j]=0;
	        }
	    }
	    
	    int dx[4]={0,0,1,-1};
	    int dy[4]={1,-1,0,0};
	    
	    
	    while(!q.empty()){
	        int i=q.front().first.first;
	        int j=q.front().first.second;
	        int stpes=q.front().second;
	        
	        q.pop();
	        ans[i][j]=stpes;
	        for(int k=0;k<4;k++){
	            int x=i+dx[k];
	            int y=j+dy[k];
	            
	            if(x>=0 && y>=0 && x<n && y<m && vis[x][y]==0){
	                vis[x][y]=1;
	                q.push({{x,y},stpes+1});
	            }
	        }
	        
	        
	    }
	    return ans;
    }
};

int main()
{
    vector<vector<int>> matrix = {{0, 0, 0}, {0, 1, 0}, {1, 1, 1}};
    Solution obj;
    vector<vector<int>> ans = obj.updateMatrix(matrix);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[0].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}