// Link: https://leetcode.com/problems/maximum-frequency-stack/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
using namespace std;

class FreqStack {
public:
    FreqStack() {
        maxFreq = 0;
    }
    
    void push(int x) {
        int freq = ++freqs[x];
        if (freq > maxFreq) {
            maxFreq = freq;
        }
        if (freq > stacks.size()) {
            stacks.push_back(stack<int>());
        }
        stacks[freq - 1].push(x);
    }
    
    int pop() {
        int x = stacks[maxFreq - 1].top();
        stacks[maxFreq - 1].pop();
        if (stacks[maxFreq - 1].empty()) {
            maxFreq--;
        }
        freqs[x]--;
        return x;
    }

private:
    vector<stack<int>> stacks;
    unordered_map<int, int> freqs;
    int maxFreq;
};

int main()
{
    FreqStack fs;
    vector<int> A;

    // Output: 5
    A = {5, 7, 5, 7, 4, 5};
    for (int x : A) {
        fs.push(x);
    }
    cout << fs.pop() << endl;
    cout << fs.pop() << endl;
    cout << fs.pop() << endl;
    cout << fs.pop() << endl;

    return 0;
}
