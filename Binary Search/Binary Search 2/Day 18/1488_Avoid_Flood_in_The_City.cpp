// Link: https://leetcode.com/problems/avoid-flood-in-the-city/?envType=study-plan&id=binary-search-ii

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        vector<int> ans(n, 1);
        unordered_map<int, int> last;
        set<int> dry;
        for (int i = 0; i < n; i++) {
            if (rains[i] > 0) {
                if (last.count(rains[i])) {
                    auto it = dry.lower_bound(last[rains[i]]);
                    if (it == dry.end())
                        return {};
                    ans[*it] = rains[i];
                    dry.erase(it);
                }
                last[rains[i]] = i;
                ans[i] = -1;
            } else {
                dry.insert(i);
            }
        }
        return ans;
    }
};

int main()
{
    vector<int> rains = {1, 2, 0, 0, 2, 1};
    Solution obj;
    vector<int> result = obj.avoidFlood(rains);
    for (int i = 0; i < result.size(); i++)
        cout << result[i] << " ";
    return 0;
}
