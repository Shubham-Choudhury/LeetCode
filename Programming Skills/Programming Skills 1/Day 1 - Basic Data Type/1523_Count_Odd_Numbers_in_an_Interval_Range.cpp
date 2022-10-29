// Link: https://leetcode.com/problems/count-odd-numbers-in-an-interval-range/?envType=study-plan&id=programming-skills-i

#include <iostream>
using namespace std;

class Solution {
public:
    int countOdds(int low, int high) {
        int count = 0;
        // for (int i = low; i <= high; i++) {
        //     if (i % 2 == 1) {
        //         count++;
        //     }
        // }
        // return count;
        if((low%2!=0) && (high%2!=0)){
            count = (high-low)/2 + 1;
        }
        else if(((high-low) % 2) == 0){
            count = (high-low)/2;
        }
        else{
            count = (high-low)/2 + 1;
        }

        return count;
    }
};



int main() {
    Solution s;
    cout << s.countOdds(3, 7) << endl;
    cout << s.countOdds(8, 10) << endl;
}