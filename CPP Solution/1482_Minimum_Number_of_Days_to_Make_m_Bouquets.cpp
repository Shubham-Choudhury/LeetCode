// Link: https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    
    bool check(vector<int> &arr, int mid, int m, int k){
        int subarray = 0;
        int total = 0;
        for(int i = 0;i<arr.size();i++){
            if(arr[i] <= mid){
                total++;
            }
            else{
                if(total == k){
                    subarray++;
                }
                total = 0;
            }
            if(total == k){
                subarray++;
                total = 0;
            }
        }
        if(subarray >= m) return true;
        return false;
    }
    
    int minDays(vector<int>& arr, int m, int k) {
       
        if(((long long)m*(long long)k) > arr.size()) return -1;
        
       
        int l = 1, r = *max_element(arr.begin(), arr.end());
        int ans = -1;
        while(l <= r){
            int mid = l + (r-l)/2;
            if(check(arr, mid, m, k)){
                ans = mid;
                r = mid-1;
            }
            else l = mid+1;
        }
        return ans;
    }
	
};

int main() {
    Solution sol;
    vector<int> bloomDay = {1, 10, 3, 10, 2};
    int m = 3;
    int k = 1;
    cout << sol.minDays(bloomDay, m, k) << endl;
    return 0;
}