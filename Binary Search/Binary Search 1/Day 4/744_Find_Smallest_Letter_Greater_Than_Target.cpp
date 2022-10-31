// Link: https://leetcode.com/problems/find-smallest-letter-greater-than-target/?envType=study-plan&id=binary-search-i

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int l = 0, r = letters.size() - 1;
        while(l < r){
            int mid = l + (r - l) / 2;
            if(letters[mid] <= target) l = mid + 1;
            else r = mid;
        }
        return letters[l] > target ? letters[l] : letters[0];
    }
};

int main(){
    Solution s;
    vector<char> letters = {'c', 'f', 'j'};
    cout << s.nextGreatestLetter(letters, 'a') << endl;
    cout << s.nextGreatestLetter(letters, 'c') << endl;
    cout << s.nextGreatestLetter(letters, 'd') << endl;
    cout << s.nextGreatestLetter(letters, 'g') << endl;
    cout << s.nextGreatestLetter(letters, 'j') << endl;
    cout << s.nextGreatestLetter(letters, 'k') << endl;
    return 0;
}