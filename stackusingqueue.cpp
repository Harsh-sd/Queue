#include <iostream>
#include <queue>

using namespace std;
class stack
{
    int n;
    queue<int> q1;
    queue<int> q2;

public:
    stack()
    {
        n = 0;
    }
    void push(int x)
    {

        q2.push(x);
        n++;
        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }
        queue<int> temp = q1;
        q1 = q2;
        q2 = temp;
    }
    void pop()
    {
        q1.pop();
        n--;
    }
    int top()
    {
        return q1.front();
    }
};
int main()
{
    stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    cout << s.top();
}