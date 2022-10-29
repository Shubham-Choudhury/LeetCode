// Link: https://leetcode.com/problems/peak-index-in-a-mountain-array/?envType=study-plan&id=binary-search-i

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int peakIndex = 0;
		for(int i = 0; i < arr.size(); i++) {
			if(arr[i] > arr[peakIndex]) {
				peakIndex = i;
			}
		}
		return peakIndex;
    }
};

int main() {
    Solution s;
    vector<int> A = {3,5,3,2,0};
    cout << s.peakIndexInMountainArray(A) << endl;
    return 0;
}