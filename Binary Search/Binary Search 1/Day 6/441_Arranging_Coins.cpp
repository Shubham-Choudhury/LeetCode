// Link: https://leetcode.com/problems/arranging-coins/?envType=study-plan&id=binary-search-i

#include <iostream>
using namespace std;

class Solution {
public:
    int arrangeCoins(int n) {
        int low = 0, high = n;
        while(low <= high){
            long long mid = low + (high - low) / 2;
            long long curr = mid * (mid + 1) / 2;
            if(curr == n)
                return mid;
            else if(curr < n)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return high;
    }
};

int main(){
    int n = 5;
    Solution obj;
    cout << obj.arrangeCoins(n);
    return 0;
}