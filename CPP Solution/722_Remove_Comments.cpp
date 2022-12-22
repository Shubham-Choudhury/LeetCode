// Link: https://leetcode.com/problems/remove-comments/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> removeComments(vector<string>& source) {
        vector<string> res;
        bool inBlock = false;
        string out;
        for (string line : source)
        {
            for (int i = 0; i < line.size(); i++)
            {
                if (!inBlock && i + 1 < line.size() && line[i] == '/' && line[i + 1] == '/')
                    break;
                else if (!inBlock && i + 1 < line.size() && line[i] == '/' && line[i + 1] == '*')
                {
                    inBlock = true;
                    i++;
                }
                else if (inBlock && i + 1 < line.size() && line[i] == '*' && line[i + 1] == '/')
                {
                    inBlock = false;
                    i++;
                }
                else if (!inBlock)
                    out.push_back(line[i]);
            }
            if (!inBlock && !out.empty())
            {
                res.push_back(out);
                out.clear();
            }
        }
        return res;
    }
};

int main()
{
    Solution obj;
    vector<string> source = {"/*Test program */", "int main()", "{ ", "  // variable declaration ", "int a, b, c;", "/* This is a test", "   multiline  ", "   comment for ", "   testing */", "a = b + c;", "}"};
    vector<string> res = obj.removeComments(source);
    for (string s : res)
        cout << s << endl;
    return 0;
}
