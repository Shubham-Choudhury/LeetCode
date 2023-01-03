// Link: https://leetcode.com/problems/reveal-cards-in-increasing-order/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> deckRevealedIncreasing(vector<int> &deck)
    {
        sort(deck.begin(), deck.end());
        deque<int> dq;
        for (int i = deck.size() - 1; i >= 0; i--)
        {
            if (dq.size() > 1)
            {
                dq.push_front(dq.back());
                dq.pop_back();
            }
            dq.push_front(deck[i]);
        }
        return vector<int>(dq.begin(), dq.end());
    }
};

int main()
{
    Solution sol;
    vector<int> deck = {17, 13, 11, 2, 3, 5, 7};
    vector<int> ans = sol.deckRevealedIncreasing(deck);
    for (int num : ans)
        cout << num << " ";
    cout << endl;
    return 0;
}
