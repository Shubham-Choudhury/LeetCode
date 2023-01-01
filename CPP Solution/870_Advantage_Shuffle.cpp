// Link: https://leetcode.com/problems/advantage-shuffle/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
vector<int> advantageCount(vector<int>& A, vector<int>& B) {
  multiset<int> s(begin(A), end(A));
  for (auto i = 0; i < B.size(); ++i) {
    auto p = *s.rbegin() <= B[i] ? s.begin() : s.upper_bound(B[i]);
    A[i] = *p;
    s.erase(p);
  }
  return A;
}
};

int main()
{
    Solution s;
    vector<int> A = {2, 7, 11, 15};
    vector<int> B = {1, 10, 4, 11};
    vector<int> ans = s.advantageCount(A, B);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}
