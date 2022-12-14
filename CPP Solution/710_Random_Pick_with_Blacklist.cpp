// Link: https://leetcode.com/problems/random-pick-with-blacklist/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;

class Solution {
public:
    int idx;
    unordered_map<int, int>mp;
    set<int> s;
    Solution(int n, vector<int>& blacklist) {
       idx = n - blacklist.size();
       n--;
       for(int i = 0; i<blacklist.size(); i++) s.insert(blacklist[i]);
       for(int i = 0; i<blacklist.size(); i++){
           if(blacklist[i] < idx){
           while(s.find(n) != s.end())n--;
           mp[blacklist[i]] = n;
           n--; 
           }
       } 
    }
    
    int pick() {
      int ans = rand()%(idx);
      if(mp.count(ans)) return mp[ans];
      return ans;
    }
};

int main(){
    vector<int> blacklist = {1, 3};
    Solution s(4, blacklist);
    cout << s.pick() << endl;
    return 0;
}