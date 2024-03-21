// In this we will implement queue using stack where we will use two stacks so that pop operation can be implemented well according to lifo property and using queue fifo property, otherwise push operation will be easy
#include <iostream>
#include <stack>
using namespace std;
class Queue
{

    stack<int> s1;
    stack<int> s2;

public:
    void push(int x)
    {
        s1.push(x);
    };
    // pop operation is costly because of using two stack
    int pop()
    {
        if (s1.empty() && s2.empty())
        {
            cout << "no elements in the queue";
            return -1;
        }
        if (s2.empty())
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
            int topval = s2.top();
            s2.pop();
            return topval;
        }
    }
    bool empty()
    {
        if (s1.empty() && s2.empty())
        {
            cout << "no elements in the queue";
            return true;
        }
        return false;
    }
};
int main()
{
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    cout << q.pop();
}
