// Link: https://leetcode.com/problems/longest-absolute-file-path/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <climits>
#include <stack>
using namespace std;

class Solution
{
    stack<int> st;

public:
    int lengthLongestPath(string input)
    {

        int pos = 0, spos = 0;
        int level = -1;
        int maxlen = 0;

        string delimiter = "\n";
        input += delimiter;
        st.push(0);

        while ((pos = input.find(delimiter, spos)) != std::string::npos)
        {
            string token = input.substr(spos, pos - spos);

            // token processing
            int tlevel = 0;

            while (token[tlevel] == '\t')
                tlevel++;

            while (tlevel <= level)
            {
                st.pop();
                level--;
            }

            int clen = st.top() + token.size() - tlevel;

            if (tlevel)
                clen++; // '/'

            if (token.find(".") != std::string::npos)
                maxlen = max(clen, maxlen);

            st.push(clen);
            level = tlevel;

            spos = pos + delimiter.size();
        }

        return maxlen;
    }
};

int main()
{
    Solution s;
    string input = "dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext";
    cout << s.lengthLongestPath(input) << endl;
    return 0;
}