// Link: https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numPairsDivisibleBy60(vector<int> &time)
    {
        int ans = 0;
        vector<int> count(60);
        for (int i = 0; i < time.size(); i++)
        {
            int remainder = time[i] % 60;
            ans += count[(60 - remainder) % 60];
            count[remainder]++;
        }
        return ans;
    }
};

int main(){
    Solution sol;
    vector<int> time = {30,20,150,100,40};
    cout << sol.numPairsDivisibleBy60(time) << endl;
    return 0;
}