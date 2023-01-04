// Link: https://leetcode.com/problems/video-stitching/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int videoStitching(vector<vector<int>> &clips, int T)
    {
        sort(clips.begin(), clips.end());
        int res = 0, i = 0, end = 0, maxEnd = 0;
        while (end < T)
        {
            while (i < clips.size() && clips[i][0] <= end)
            {
                maxEnd = max(maxEnd, clips[i][1]);
                i++;
            }
            if (end == maxEnd)
                return -1;
            end = maxEnd;
            res++;
        }
        return res;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> clips = {{0, 2}, {4, 6}, {8, 10}, {1, 9}, {1, 5}, {5, 9}};
    int T = 10;
    cout << sol.videoStitching(clips, T) << endl;
    return 0;
}
