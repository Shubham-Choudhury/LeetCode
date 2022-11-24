// Link: https://leetcode.com/problems/find-the-winner-of-the-circular-game/?envType=study-plan&id=data-structure-ii

#include <iostream>
#include <queue>
using namespace std;

class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int> q;
        for(int i = 1; i <= n; i++)
            q.push(i);
        while(q.size() > 1) {
            for(int i = 0; i < k - 1; i++) {
                q.push(q.front());
                q.pop();
            }
            q.pop();
        }
        return q.front();
    }
};

int main() {
    Solution s;
    cout << s.findTheWinner(5, 2) << endl;
    return 0;
}