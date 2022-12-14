// Link: https://leetcode.com/problems/number-of-atoms/

#include <iostream>
#include <string>
#include <map>
#include <stack>
#include <sstream>
#include <vector>
using namespace std;

class Solution {
public:
    string helper(string s, int k){
        stringstream ss;
        string ans;
        for(int i = 0;i<s.size();i++){
            string tmp; 
            tmp = s[i];
            int tmpk = 1;
            
            if(i+1 == s.size() || (s[i+1] >=  'A' && s[i+1] <= 'Z')) ss<<tmp<<k;
            
            else{
                if(s[i+1]>='a' && s[i+1] <= 'z') tmp +=s[++i];
                i++;
                tmpk = 0;
                for(;i<s.size();i++){
                    int t = s[i] - '0';
                    if(t >= 0 &&  t < 10) tmpk = tmpk*10 + t;
                    else {i--;break;}
                }
                if(tmpk == 0) tmpk = 1;
                tmpk *= k;
                ss<<tmp<<tmpk;
            }
        }
        ss>>ans;
        return ans;
    }
    string countOfAtoms(string formula) {
        if(formula.empty()) return "";
        
        while(!formula.empty()){
            int pos1=-1,pos2=-1;
            for(int i=0;i<formula.size();i++){
                if(formula[i] == '(') pos1 = i;
                if(formula[i] == ')') {pos2 = i;break;}
            }
            int pos3 = pos2+1, k = 0;
            for(;pos3<formula.size();pos3++){
                int t = formula[pos3] - '0';
                if(t >= 0 &&  t < 10) k = k*10 + t;
                else break;
            }
            if(!k) k=1;
            string ret;
            if(pos2 != -1) ret = helper(formula.substr(pos1+1,pos2 - pos1 - 1), k );
            else break;
            formula.erase(pos1,pos3-pos1);
            formula.insert(pos1,ret);
            
        }
       
        vector <int> ans;
        map <string,int> mp;
        string rez;
        
        for(int i = 0;i<formula.size();i++){
            string tmp;
            tmp = formula[i];
        
            if(i+1 == formula.size() || (formula[i+1] >=  'A' && formula[i+1] <= 'Z')){
                if(mp.count(tmp)) ans[mp[tmp]]+=1;
                else {
                    ans.push_back(1);
                    mp[tmp] = ans.size()-1;
                }
            }
            else{
                if(formula[i+1]>='a' && formula[i+1] <= 'z') tmp +=formula[++i];
                i++;
                int k = 0;
                for(;i<formula.size();i++){
                    int t = formula[i] - '0';
                    if(t >= 0 &&  t < 10) k = k*10 + t;
                    else {i--;break;}
                }
                if(k == 0) k = 1;
                if(mp.count(tmp)) ans[mp[tmp]]+=k;
                else {
                    ans.push_back(k);
                    mp[tmp] = ans.size()-1;
                }
            }
        }
               
        map <string,int>::iterator it = mp.begin();
        for(;it!=mp.end();it++){
            rez = rez + it->first;
            if(ans[it->second] != 1) rez+= to_string(ans[it->second]);
        }
        
        return rez;
    }
};

int main()
{
    Solution sol;
    string formula;

    // Output: "H2O"
    formula = "H2O";
    cout << sol.countOfAtoms(formula) << endl;

    return 0;
}