// Link: https://leetcode.com/problems/product-of-the-last-k-numbers/

#include <bits/stdc++.h>
using namespace std;

class ProductOfNumbers {
public:
    vector<int> nums;
    ProductOfNumbers() {
        nums.push_back(1);
    }
    
    void add(int num) {
        if (num == 0) {
            nums = {1};
        } else {
            nums.push_back(nums.back() * num);
        }
    }
    
    int getProduct(int k) {
        int n = nums.size();
        if (k >= n) {
            return 0;
        }
        return nums.back() / nums[n - k - 1];
    }
};

int main() {
    ProductOfNumbers sol;
    sol.add(3);
    sol.add(0);
    sol.add(2);
    sol.add(5);
    sol.add(4);
    cout << sol.getProduct(2) << endl;
    cout << sol.getProduct(3) << endl;
    cout << sol.getProduct(4) << endl;
    sol.add(8);
    cout << sol.getProduct(2) << endl;
    return 0;
}
