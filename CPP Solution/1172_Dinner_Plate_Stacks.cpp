// Link: https://leetcode.com/problems/dinner-plate-stacks/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <set>
#include <stack>
using namespace std;

class DinnerPlates
{
public:
    vector<vector<int> *> t;
    int capacity, last_id;
    set<int> indexes;

    DinnerPlates(int capacity)
    {
        this->capacity = capacity, last_id = -1;
    }

    void push(int val)
    {
        if (indexes.empty())
        {
            if (last_id <= (int)t.size())
            {
                t.push_back(new vector<int>());
                last_id++;
            }

            t[last_id]->push_back(val);
            if (capacity != 1)
                indexes.insert(last_id);
        }
        else
        {
            int id = *indexes.begin();

            t[id]->push_back(val);
            if (t[id]->size() == capacity)
                indexes.erase(id);
        }
    }

    int pop()
    {
        if (last_id == -1)
            return -1;

        int result = t[last_id]->back();
        t[last_id]->pop_back();

        if (t[last_id]->empty())
        {
            indexes.erase(last_id);
            while (last_id != -1 && t[last_id]->empty())
                last_id--;
        }
        else
            indexes.insert(last_id);

        return result;
    }

    int popAtStack(int index)
    {
        if (index < 0 || index > last_id || t[index]->empty())
            return -1;

        if (index == last_id)
            return pop();
        else
        {
            int result = t[index]->back();
            t[index]->pop_back();

            indexes.insert(index);

            return result;
        }
    }
};

int main()
{
    DinnerPlates s(2);
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    cout << s.popAtStack(0) << endl;
    s.push(20);
    s.push(21);
    cout << s.popAtStack(0) << endl;
    cout << s.popAtStack(2) << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    return 0;
}
