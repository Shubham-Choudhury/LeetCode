// Link: https://leetcode.com/problems/flatten-nested-list-iterator/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class NestedInteger {
  public:
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;
    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;
    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};

class NestedIterator {
public:
    stack<NestedInteger> st;
    NestedIterator(vector<NestedInteger> &nestedList) {
        for(int i = nestedList.size() - 1; i >= 0; i--)
            st.push(nestedList[i]);
    }
    
    int next() {
        int result = st.top().getInteger();
        st.pop();
        return result;
    }
    
    bool hasNext() {
        while(!st.empty()) {
            NestedInteger top = st.top();
            if(top.isInteger())
                return true;
            st.pop();
            for(int i = top.getList().size() - 1; i >= 0; i--)
                st.push(top.getList()[i]);
        }
        return false;
    }
};

int main() {
    vector<NestedInteger> nestedList;
    NestedIterator* obj = new NestedIterator(nestedList);
    cout << obj->next() << endl;
    cout << obj->hasNext() << endl;
    return 0;
}