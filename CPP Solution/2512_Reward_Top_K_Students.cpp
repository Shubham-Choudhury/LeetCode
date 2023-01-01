// Link: https://leetcode.com/problems/reward-top-k-students/

#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int,int>a,pair<int,int>b)
{
    if(a.second==b.second)return a.first<b.first;
    return a.second>b.second;
}
class Solution {
public:
    vector<int> topStudents(vector<string>& pf, vector<string>& nf, vector<string>& rep, vector<int>& sid, int k) 
    {
        unordered_map<string ,int> p,n;
        for(auto e:pf) p[e]++;
        for(auto e:nf) n[e]++;
        unordered_map<int,int> ans;
        for(int i=0;i<rep.size();i++)
        {
            string line=rep[i];
            int score=0;
            for(int j=0;j<line.size();j++)
            { 
                string temp="";
                while(j<line.size() && line[j]!=' ')
                {
                    temp+=line[j];
                    j++;
                }
                // cout<<temp<<" " <<j<<endl;
                if(p.find(temp)!=p.end())score+=3;
                if(n.find(temp)!=n.end())score-=1;
            }
            // cout<<i<<" "<<score<<endl;
            ans[sid[i]]=score;
            
        }
        vector<pair<int,int>> v;
        for(auto e:ans)
        {
            v.push_back({e.first,e.second});
        }
        sort(v.begin(),v.end(),cmp);
        vector<int> sol;
        for(int i=0;i<k;i++)
        {
            sol.push_back(v[i].first);
        }
        return sol;
    }
};

int main(){
    Solution s;
    vector<string> pf={"a","b","c"};
    vector<string> nf={"d"};
    vector<string> rep={"a b c","a b c d","a b c d"};
    vector<int> sid={1,2,3};
    int k=2;

    vector<int> ans=s.topStudents(pf,nf,rep,sid,k);
    for(auto e:ans)cout<<e<<" ";
    return 0;
}