// Link: https://leetcode.com/problems/evaluate-reverse-polish-notation/?envType=study-plan&id=programming-skills-ii

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for(auto& i:tokens)
            if (i=="+"||i=="-"||i=="*"||i=="/")
            {
                long int e1=s.top();s.pop();
                long int e2=s.top();s.pop();
                   if(i=="+")   e1=e2+e1;
                    if(i=="-")  e1=e2-e1;
                    if(i=="*")  e1=e2*e1;
                    if(i=="/")  e1=e2/e1;
                s.push(e1);
            }
            else s.push(stoi(i));         
        return s.top();
    }
};

int main() {
    Solution obj;
    vector<string> tokens = {"2", "1", "+", "3", "*"};
    cout << obj.evalRPN(tokens);
    return 0;
}