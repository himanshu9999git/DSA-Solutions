#include<iostream>
#include<string>
#include<vector>

using namespace std;

#define max 1000

class Stack{
    int top;

    public:

    int a[max];
    Stack(){ top = -1;}
    bool push(int x);
    int pop();
    int peek();
    bool isEmpty();

};

bool Stack::push(int x){
    if(top>=(max-1))
    {
        cout<<"Stack Overflow";
        return false;
    }
    else
    {
        a[++top] = x;
        return true;
    }
}

int Stack::pop(){
    if(top<0)
    {
        cout<<"Stack Underflow";
        return 0;
    }
    else
    {
        int x = a[top--];
        return x;
    }
}

int Stack::peek(){
    if(top<0)
    {
        cout<<"Stack Underflow";
        return 0;
    }
    else
    {
        int x = a[top];
        return x;
    }
}

bool Stack::isEmpty(){
    if(top<0)
    return true;

    else
    return false;
}

int main()
{
    Stack s;
    s.push(15);
    s.push(40);
    s.push(34);
    s.pop();
    s.push(74);

    while (!s.isEmpty())
    {
        cout<<s.peek()<<endl;
        s.pop();
    }
    
    return 0;
}