// Link: https://leetcode.com/problems/hand-of-straights/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int W) {
        if (hand.size() % W != 0)
            return false;
        map<int, int> mp;
        for (int i = 0; i < hand.size(); i++)
            mp[hand[i]]++;
        while (mp.size() > 0)
        {
            int num = mp.begin()->first;
            for (int i = 0; i < W; i++)
            {
                if (mp.find(num + i) == mp.end())
                    return false;
                mp[num + i]--;
                if (mp[num + i] == 0)
                    mp.erase(num + i);
            }
        }
        return true;
    }
};

int main()
{
    Solution sol;
    vector<int> hand = {1, 2, 3, 6, 2, 3, 4, 7, 8};
    int W = 3;
    cout << sol.isNStraightHand(hand, W) << endl;
    return 0;
}

