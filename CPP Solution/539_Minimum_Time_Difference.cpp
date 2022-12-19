// Link: https://leetcode.com/problems/minimum-time-difference/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int findMinDifference(vector<string> &timePoints)
    {
        std::vector<int> time;
        for (auto &t : timePoints)
        {
            int h = std::stoi(t.substr(0, 2));
            int m = std::stoi(t.substr(3, 2));
            time.push_back(h * 60 + m);
        }
        std::sort(time.begin(), time.end());
        int min = 1440;
        for (size_t i = 1; i < time.size(); i++)
        {
            int diff = time[i] - time[i - 1];
            if (diff < min)
            {
                min = diff;
            }
        }
        int diff = time[0] + 1440 - time[time.size() - 1];
        if (diff < min)
        {
            min = diff;
        }
        return min;
    }
};

int main()
{
    Solution solution;
    std::vector<std::string> timePoints = {"23:59", "00:00"};
    std::cout << solution.findMinDifference(timePoints) << std::endl;
    return 0;
}
