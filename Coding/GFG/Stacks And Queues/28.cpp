//
//  28.cpp
//  Coding
//
//  Created by Surya Dheeshjith on 08/07/19.
//  Copyright © 2019 Surya Dheeshjith. All rights reserved.
//


//Min element in stack


#include<bits/stdc++.h>
    using namespace std;
    class _stack{
        stack<int> s;
        int minEle;
        public :
        int getMin();
        int pop();
        void push(int);
    };
    int main()
    {
        int t;
        cin>>t;
        while(t--)
        {
            int q;
            cin>>q;
            _stack *a = new _stack();
            while(q--){
                int qt;
                cin>>qt;
                if(qt==1)
                {
                    //push
                    int att;
                    cin>>att;
                    a->push(att);
                }
                else if(qt==2)
                {
                    //pop
                    cout<<a->pop()<<" ";
                }
                else if(qt==3)
                {
                    //getMin
                    cout<<a->getMin()<<" ";
                }
            }
            cout<<endl;
        }
    }
    

/*This is a function problem.You only need to complete the function given below*/
/*
 The structure of the class is as follows
 class _stack{
 stack<int> s;
 int minEle;
 public :
 int getMin();
 int pop();
 void push(int);
 };
 */
/*returns min element from stack*/
int _stack :: getMin()
{
    //Your code here
    stack<int> a;
    stack<int> b;
    
    int min = 101;
    if(s.empty())
    return -1;
    
    while(!s.empty())
    {
        a.push(s.top());
        
        if(min>s.top())
        min = s.top();
        
        s.pop();
    }
    while(!a.empty())
    {
        s.push(a.top());
        a.pop();
    }
    
    minEle = min;
    return min;
    
    
}
/*returns poped element from stack*/
int _stack ::pop()
{
    //Your code here
    if(s.empty())
    return -1;
    
    int c = s.top();
    s.pop();
    return c;
}
/*push element x into the stack*/
void _stack::push(int x)
{
    //Your code here
    s.push(x);
}

