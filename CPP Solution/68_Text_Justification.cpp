// Link: https://leetcode.com/problems/text-justification/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string>res;
        if(maxWidth == 0) return {""};
        int i = 0, j = 0;
        while(j != words.size()){
            int len = -1;
            while(j < words.size() && len + words[j].size() + 1 <= maxWidth)
                len += words[j++].size() + 1;
            int space = maxWidth - len + j - i - 1;
            int k = i;
            while(space){
                words[k++] += " ";
                space--;
                if(j != words.size() && (k == j - 1 || k == j)) k = i;
                if(j == words.size() && k == j) k = j - 1;
            }
            string line = "";
            for(int l = i; l < j; l++)
                line += words[l];
            res.push_back(line);
            i = j;
        }
        return res;
    }
};

int main() {
    Solution solution;
    vector<string> words = {"This", "is", "an", "example", "of", "text", "justification."};
    vector<string> result = solution.fullJustify(words, 16);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << endl;
    }
    return 0;
}