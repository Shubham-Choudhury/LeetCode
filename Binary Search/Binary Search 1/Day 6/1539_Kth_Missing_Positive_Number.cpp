// Link: https://leetcode.com/problems/kth-missing-positive-number/?envType=study-plan&id=binary-search-i

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int low = 0, high = n - 1;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(arr[mid] - (mid + 1) < k)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return low + k;
    }
};

int main(){
    vector<int> arr = {2, 3, 4, 7, 11};
    int k = 5;
    Solution obj;
    cout << obj.findKthPositive(arr, k);
    return 0;
}