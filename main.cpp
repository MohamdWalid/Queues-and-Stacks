#include <iostream>
#include <stack>
#include <queue>
using namespace std;

class Queue
{
public:
    stack<int> stack1, tempstack;
    bool isempty(stack<int> s)
    {
        if(s.empty())
            return true;
        else
            return false;
    }
    void clearfun()
    {
        if (isempty(stack1))
        {
            cout << "Queue is Empty "<<endl;;
        }
        else
        {
            while(!isempty(stack1))
            {
                stack1.pop();
            }
        }

    }
    void first_element()
    {
        if (isempty(stack1))
        {
            cout << "Queue is Empty "<<endl;;
        }
        else
        {
            cout<<"first element is "<<stack1.top()<<endl;
        }

    }
    void enQueue(int x)
    {
        while (!isempty(stack1))
        {
            tempstack.push(stack1.top());
            stack1.pop();
        }
        stack1.push(x);
        while (!isempty(tempstack))
        {
            stack1.push(tempstack.top());
            tempstack.pop();
        }
    }
    void deQueue()
    {
        if (isempty(stack1))
        {
            cout << "Queue is Empty "<<endl;;
        }
        else
        {
            stack1.pop();
        }
    }
    void print()
    {
        if(isempty(stack1))
        {
            cout << "Queue is Empty "<<endl;;
        }
        else
        {
            for(int i=0; i<stack1.size(); i++)
            {
                cout<<stack1.top()<<endl;
                int x=stack1.top();
                stack1.pop();
                enQueue(x);
            }
        }
    }
};
class stackclass
{
public:

    queue<int> Queue1, tempqueue,queue2;
    void pushfun(int x)
    {
        while(!Queue1.empty())
        {
            int temp = Queue1.front();
            Queue1.pop();
            tempqueue.push(temp);
        }
        Queue1.push(x);
        while(!tempqueue.empty())
        {
            int temp = tempqueue.front();
            tempqueue.pop();
            Queue1.push(temp);
        }
    }
    void popfun()
    {
        if(Queue1.empty())
        {
            cout<<"Stack is empty"<<endl;
        }
        else
        {
            Queue1.pop();
        }

    }
    void print()
    {
        if(Queue1.empty())
        {
            cout<<"Stack is empty"<<endl;
        }
        else
        {
            for(int i=0; i<Queue1.size(); i++)
            {
                cout<<Queue1.front()<<endl;
                queue2.push(Queue1.front());
                Queue1.pop();
                Queue1.push(queue2.back());
            }
        }


    }

};

int main()
{
    Queue q;
    stackclass s;
    int choice;
    int choice2;
    int data;
    while(true)
    {
        do
        {
            cout<<"[1] Enqueue(queue)"<<endl<<"[2] Dequeue(queue)"<<endl<<"[3] print first element(queue)"<<endl<<"[4] clear(queue)"<<endl<<"[5] print queue"<<endl<<"[6] push(stack)"<<endl<<"[7] pop(stack)"<<endl<<"[8] print stack"<<endl;
            cout<<"Enter choice: ";
            cin>>choice;
        }
        while(choice<1 || choice>8);
        switch(choice)
        {
        case 1:
            cout<<"Enter data: ";
            cin>>data;
            q.enQueue(data);
            break;

        case 2:
            q.deQueue();
            break;

        case 3:
            q.first_element();
            break;

        case 4:
            q.clearfun();
            break;

        case 5:
            q.print();
            break;

        case 6:
            cout<<"Enter data: ";
            cin>>data;
            s.pushfun(data);
            break;

        case 7:
            s.popfun();
            break;

        case 8:
            s.print();
            break;
        }
        do
        {
          cout<<"[1] continue"<<"[2] stop"<<endl;
          cin>>choice2;
        }while(choice2!=1 && choice2!=2);
        if(choice2==2)
        {
            break;
        }

    }
    return 0;
}
