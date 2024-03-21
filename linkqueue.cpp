#include <iostream>
using namespace std;
// we have made a lonked list
class node
{
    // always the member are public
public:
    int data;
    node *next;

    node(int val)
    {
        data = val;
        next = NULL;
    }
};
// formed the queue
class Queue
{
    // both the pointers
    node *front;
    node *back;

public:
    // In the constructor initialized ny NULL
    Queue()
    {
        front = NULL;
        back = NULL;
    }
    void push(int x)
    {
        node *n = new node(x);
        if (front == NULL)
        {
            back = n;
            front = n;
            return;
        }
        back->next = n;
        back = n;
        return;
    }
    void pop()
    {
        if (front == NULL)
        {
            cout << "no elements in queue";
            return;
        }
        node *todelete = front;
        front = front->next;
        delete todelete;
    }
    int peek()
    {
        if (front == NULL)
        {
            cout << "no elements in queue";
            return -1;
        }
        return front->data;
    }
    bool empty()
    {
        if (front == NULL && front > back)
        {
            cout << "no elements in queue";
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
    cout << q.peek();
    q.pop();
    cout << q.peek();
    q.pop();
    cout << q.peek();
    q.pop();
    cout << q.empty();
};