// Link: https://leetcode.com/problems/gas-station/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total = 0;
        int sum = 0;
        int start = 0;
        for (int i = 0; i < gas.size(); i++) {
            total += gas[i] - cost[i];
            sum += gas[i] - cost[i];
            if (sum < 0) {
                start = i + 1;
                sum = 0;
            }
        }
        return total < 0 ? -1 : start;
    }
};

int main()
{
    Solution a;
    vector<int> b = {1, 2, 3, 4, 5};
    vector<int> c = {3, 4, 5, 1, 2};
    cout << a.canCompleteCircuit(b, c) << endl;
    return 0;
}
