// Link: https://leetcode.com/problems/bulls-and-cows/?envType=study-plan&id=level-1

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char, int> map;
        int bulls = 0, cows = 0;
        for (int i = 0; i < secret.size(); i++) {
            if (secret[i] == guess[i]) {
                bulls++;
            } else {
                if (map[secret[i]]++ < 0) {
                    cows++;
                }
                if (map[guess[i]]-- > 0) {
                    cows++;
                }
            }
        }
        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};

int main() {
    Solution sol;
    string secret = "1807", guess = "7810";
    cout << sol.getHint(secret, guess) << endl;
    return 0;
}