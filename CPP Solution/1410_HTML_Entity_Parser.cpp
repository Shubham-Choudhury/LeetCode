// Link: https://leetcode.com/problems/html-entity-parser/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string entityParser(string text)
    {

        int n = text.size();
        int sliding;
        vector<int> marked(n, 1);
        sliding = 7;
        for (int start = 0; start <= n - sliding; start++)
        {
            int back = start + sliding - 1;
            string sub = text.substr(start, back - start + 1);
            if (sub.compare("&frasl;") == 0)
            {
                text[start] = '/';
                for (int i = start + 1; i <= back; i++)
                {
                    // text[i] = '*';
                    marked[i] = -1;
                }
            }
        }
        sliding = 6;
        for (int start = 0; start <= n - sliding; start++)
        {
            int back = start + sliding - 1;
            string sub = text.substr(start, back - start + 1);
            if (sub.compare("&quot;") == 0)
            {
                text[start] = '"';
                for (int i = start + 1; i <= back; i++)
                {
                    // text[i] = '*';
                    marked[i] = -1;
                }
            }
            else if (sub.compare("&apos;") == 0)
            {
                text[start] = '\'';
                for (int i = start + 1; i <= back; i++)
                {
                    // text[i] = '*';
                    marked[i] = -1;
                }
            }
        }
        sliding = 5;
        for (int start = 0; start <= n - sliding; start++)
        {
            int back = start + sliding - 1;
            string sub = text.substr(start, back - start + 1);
            if (sub.compare("&amp;") == 0)
            {
                text[start] = '&';
                for (int i = start + 1; i <= back; i++)
                {
                    // text[i] = '*';
                    marked[i] = -1;
                }
            }
        }
        sliding = 4;
        for (int start = 0; start <= n - sliding; start++)
        {
            int back = start + sliding - 1;
            string sub = text.substr(start, back - start + 1);
            if (sub.compare("&gt;") == 0)
            {
                text[start] = '>';
                for (int i = start + 1; i <= back; i++)
                {
                    // text[i] = '*';
                    marked[i] = -1;
                }
            }
            else if (sub.compare("&lt;") == 0)
            {
                text[start] = '<';
                for (int i = start + 1; i <= back; i++)
                {
                    // text[i] = '*';
                    marked[i] = -1;
                }
            }
        }
        int index = 0;
        for (int i = 0; i < n; i++)
        {
            if (marked[i] == 1)
            {
                text[index] = text[i];
                index++;
            }
        }
        text.resize(index);
        return text;
    }
};

int main()
{
    Solution sol;
    string text = "&amp; is an HTML entity but &ambassador; is not.";
    string ans = sol.entityParser(text);
    cout << ans << endl;
    return 0;
}
