// Link: https://leetcode.com/problems/distinct-prime-factors-of-product-of-array/

#include <bits/stdc++.h>
using namespace std;

#include <unordered_set>
#include <cmath>

class Solution {
public:
    int distinctPrimeFactors(vector<int>& nums) {
        // Create a set to store the distinct prime factors
        unordered_set<int> primeFactors;
        
        // Iterate through each element in the array
        for (int num : nums) {
            // Get the prime factors of the current element
            unordered_set<int> currentPrimeFactors = getPrimeFactors(num);
            // Add the prime factors to the set
            primeFactors.insert(currentPrimeFactors.begin(), currentPrimeFactors.end());
        }
        
        // Return the size of the set, which is the number of distinct prime factors
        return primeFactors.size();
    }

private:
    unordered_set<int> getPrimeFactors(int num) {
        // Create a set to store the prime factors
        unordered_set<int> primeFactors;
        
        // Keep dividing the number by 2 until it is odd
        while (num % 2 == 0) {
            primeFactors.insert(2);
            num /= 2;
        }
        
        // Check for other prime factors from 3 to sqrt(num)
        for (int i = 3; i <= sqrt(num); i += 2) {
            // Keep dividing the number by i until it is not divisible by i
            while (num % i == 0) {
                primeFactors.insert(i);
                num /= i;
            }
        }
        
        // If the number is greater than 2, it is a prime number itself
        if (num > 2) {
            primeFactors.insert(num);
        }
        
        return primeFactors;
    }
};


int main(){
    Solution s;
    vector<int> nums = {2, 3, 4, 6, 8, 12};
    cout << s.distinctPrimeFactors(nums) << endl;
    return 0;
}
