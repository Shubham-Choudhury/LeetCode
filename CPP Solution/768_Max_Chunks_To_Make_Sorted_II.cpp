// Link: https://leetcode.com/problems/max-chunks-to-make-sorted-ii/

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        vector<int> maxLeft(n), minRight(n);
        maxLeft[0] = arr[0];
        for (int i = 1; i < n; ++i)
            maxLeft[i] = max(maxLeft[i - 1], arr[i]);
        minRight[n - 1] = arr[n - 1];
        for (int i = n - 2; i >= 0; --i)
            minRight[i] = min(minRight[i + 1], arr[i]);
        int ans = 1;
        for (int i = 0; i < n - 1; ++i)
            if (maxLeft[i] <= minRight[i + 1])
                ++ans;
        return ans;
    }
};

int main()
{
    vector<int> arr = {5, 4, 3, 2, 1};
    Solution obj;
    cout << obj.maxChunksToSorted(arr) << endl;
    return 0;
}
