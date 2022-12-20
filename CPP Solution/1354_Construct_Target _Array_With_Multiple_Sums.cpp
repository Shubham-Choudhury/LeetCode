// Link: https://leetcode.com/problems/construct-target-array-with-multiple-sums/

#include <iostream>
#include <vector>   
#include <queue>
using namespace std;

class Solution {
public:
    bool isPossible(vector<int>& target) {
        long long sum = 0;
        priority_queue<int> pq;
        for (int num : target) {
            sum += num;
            pq.push(num);
        }
        
        while (true) {
            int num = pq.top();
            pq.pop();
            sum -= num;
            if (num == 1 || sum == 1) {
                return true;
            }
            if (num < sum || sum == 0 || num % sum == 0) {
                return false;
            }
            num %= sum;
            sum += num;
            pq.push(num);
        }
        
        return true;
    }
};

int main() {
    Solution sol;
    vector<int> target;
    
    target = {9,3,5};
    cout << sol.isPossible(target) << endl;
    
    target = {1,1,1,2};
    cout << sol.isPossible(target) << endl;
    
    target = {8,5};
    cout << sol.isPossible(target) << endl;
    
    target = {1,1000000000};
    cout << sol.isPossible(target) << endl;
    
    return 0;
}
