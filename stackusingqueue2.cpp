#include <iostream>
#include <queue>
using namespace std;

class stack
{
    int n;

public:
    queue<int> q1;
    queue<int> q2;
    stack()
    {
        n = 0;
    }
    void push(int x)
    {
        q1.push(x);
        n++;
    };
    void pop()
    {
        if (q1.empty() && q2.empty())
        {
            cout << "No elements in the stack";
            return;
        }
        while (q1.size() != 1)
        {
            q2.push(q1.front());
            q1.pop();
        }
        q1.pop(); // Remove the last element
        n--;
        queue<int> temp = q1;
        q1 = q2;
        q2 = temp;
    };
   int top()
{
    if (q1.empty()) {
        cout << "Stack is empty" << endl;
        return -1; 
    }
    return q1.back(); // return the last element in the queue
}

};

int main()
{
    stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.pop();
    cout << s.top();
}
