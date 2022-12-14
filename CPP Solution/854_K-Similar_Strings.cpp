// Link: https://leetcode.com/problems/k-similar-strings/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    int kSimilarity(string A, string B)
    {
        for (int i = 0; i < A.size(); i++)
        {
            if (A[i] == B[i])
                continue;
            vector<int> matches;
            for (int j = i + 1; j < A.size(); j++)
            {
                if (A[j] == B[i] && A[j] != B[j])
                {
                    matches.push_back(j);
                    if (A[i] == B[j])
                    {
                        swap(A[i], A[j]);
                        return 1 + kSimilarity(A.substr(i + 1), B.substr(i + 1));
                    }
                }
            }
            int best = A.size() - 1;
            for (int j : matches)
            {
                swap(A[i], A[j]);
                best = min(best, 1 + kSimilarity(A.substr(i + 1), B.substr(i + 1)));
                swap(A[i], A[j]);
            }
            return best;
        }
        return 0;
    }
};

int main()
{
    Solution solution;
    string A = "abac";
    string B = "baca";
    cout << solution.kSimilarity(A, B) << endl;
    return 0;
}