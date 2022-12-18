// Link: https://leetcode.com/problems/string-compression/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    int compress(vector<char> &chars)
    {
        int index = 0;
        int i = 0;
        while (i < chars.size())
        {
            int j = i;
            while (j < chars.size() && chars[j] == chars[i])
                j++;
            chars[index++] = chars[i];
            if (j - i > 1)
            {
                string count = to_string(j - i);
                for (char c : count)
                    chars[index++] = c;
            }
            i = j;
        }
        return index;
    }
};

int main()
{
    Solution s;
    vector<char> chars = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};
    cout << s.compress(chars) << endl;
    return 0;
}
