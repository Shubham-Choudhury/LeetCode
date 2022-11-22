// Link: https://leetcode.com/problems/nearest-exit-from-entrance-in-maze/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int nearestExit(vector<vector<char>>& arr, vector<int>& ent) {
        int n=arr.size();
        int m=arr[0].size();

        queue<pair<int,int>>q;
        q.push(make_pair(ent[0],ent[1]));  //row col
        arr[ent[0]][ent[1]]='+';

        int steps = 0;
        while(!q.empty())
        {
            int size = q.size();
            for(int i=0;i<size;i++)
            {
                pair<int,int>p = q.front();
                q.pop();

                int x = p.first;  //curr row
                int y = p.second; //curr col
               // cout<<"x="<<x<<" "<<"y="<<y<<endl;
                if((x==0 or y==0 or x==n-1 or y==m-1))
                {
                    cout<<"steps="<<steps<<endl;
                    if((x!=ent[0] or y!=ent[1]))
                        return steps;
                }

                if(isvalid(n,m,x+1,y)==true and arr[x+1][y]!='+')
                {
                    arr[x+1][y]='+';
                    q.push(make_pair(x+1,y));
                }
                if(isvalid(n,m,x-1,y)==true and arr[x-1][y]!='+')
                {
                    arr[x-1][y]='+';
                    q.push(make_pair(x-1,y));
                }
                if(isvalid(n,m,x,y+1)==true and arr[x][y+1]!='+')
                {
                    arr[x][y+1]='+';
                    q.push(make_pair(x,y+1));
                }
                if(isvalid(n,m,x,y-1)==true and arr[x][y-1]!='+')
                {
                    arr[x][y-1]='+';
                    q.push(make_pair(x,y-1));
                }
            }
            steps++;
        }
        return -1;
    }
    bool isvalid(int n,int m,int row,int col)
    {
        if(row>=0 and row<n and col>=0 and col<m)
        {
            return true;
        }
        return false;
    }
};

int main()
{
    vector<vector<char>>arr = {{'+','+','.','+'},{'.','.','.','+'},{'+','+','+','.'}};
    vector<int>ent = {1,2};
    Solution s;
    cout<<s.nearestExit(arr,ent);
    return 0;
}