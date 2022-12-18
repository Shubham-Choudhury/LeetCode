// Link: https://leetcode.com/problems/queue-reconstruction-by-height/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>> &people)
    {
        sort(people.begin(), people.end(), [](vector<int> &a, vector<int> &b) {
            if (a[0] == b[0])
                return a[1] < b[1];
            return a[0] > b[0];
        });
        vector<vector<int>> result;
        for (int i = 0; i < people.size(); i++)
        {
            result.insert(result.begin() + people[i][1], people[i]);
        }
        return result;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> people = {{7, 0}, {4, 4}, {7, 1}, {5, 0}, {6, 1}, {5, 2}};
    vector<vector<int>> result = s.reconstructQueue(people);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i][0] << " " << result[i][1] << endl;
    }
    return 0;
}
