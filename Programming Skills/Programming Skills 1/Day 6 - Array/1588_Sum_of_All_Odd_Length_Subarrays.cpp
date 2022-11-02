// Link: https://leetcode.com/problems/sum-of-all-odd-length-subarrays/?envType=study-plan&id=programming-skills-i

#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n = arr.size();
        int sum = 0;
        for(int i = 0; i < n; i++){
            int left = i + 1;
            int right = n - i;
            int left_odd = (left + 1) / 2;
            int right_odd = (right + 1) / 2;
            int left_even = left / 2;
            int right_even = right / 2;
            sum += (left_odd * right_odd + left_even * right_even) * arr[i];
        }
        return sum;
    }
};

int main(){
    vector<int> arr = {1, 4, 2, 5, 3};
    Solution obj;
    cout << obj.sumOddLengthSubarrays(arr);
    return 0;
}