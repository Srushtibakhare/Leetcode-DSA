#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

class MinStack
{
private:
    stack<int> st;
    stack<int> minSt;

public:
    void push(int val)
    {
        st.push(val);

        if (minSt.empty())
            minSt.push(val);
        else
            minSt.push(min(val, minSt.top()));
    }

    void pop()
    {
        st.pop();
        minSt.pop();
    }

    int top()
    {
        return st.top();
    }

    int getMin()
    {
        return minSt.top();
    }
};

int main()
{
    MinStack s;

    s.push(-2);
    s.push(0);
    s.push(-3);

    cout << "Minimum = " << s.getMin() << endl;

    s.pop();

    cout << "Top = " << s.top() << endl;
    cout << "Minimum = " << s.getMin() << endl;

    return 0;
}