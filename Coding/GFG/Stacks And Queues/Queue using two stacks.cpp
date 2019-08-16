//
//  26.cpp
//  Coding
//
//  Created by Surya Dheeshjith on 08/07/19.
//  Copyright © 2019 Surya Dheeshjith. All rights reserved.
//
// Queue using two stacks


#include<bits/stdc++.h>
    using namespace std;
    class StackQueue{
        private:
        stack<int> s1;
        stack<int> s2;
        public:
        void push(int B);
        int pop();
    };
    int main()
    {
        int T;
        cin>>T;
        while(T--)
        {
            StackQueue *sq = new StackQueue();
            int Q;
            cin>>Q;
            while(Q--){
                int QueryType=0;
                cin>>QueryType;
                if(QueryType==1)
                {
                    int a;
                    cin>>a;
                    sq->push(a);
                }else if(QueryType==2){
                    cout<<sq->pop()<<" ";
                }
            }
            cout<<endl;
        }
    }
    

/*This is a function problem.You only need to complete the function given below*/
/* The structure of the class is
 class StackQueue{
 private:
 // These are STL stacks ( http://goo.gl/LxlRZQ )
 stack<int> s1;
 stack<int> s2;
 public:
 void push(int);
 int pop();
 }; */
/* The method push to push element into the queue */
void StackQueue :: push(int x)
{
    // Your Code
    s1.push(x);
    
}
/*The method pop which return the element poped out of the queue*/
int StackQueue :: pop()
{
    // Your Code
    if(s1.empty())
    return -1;
    
    while(!s1.empty())
    {
        int c = s1.top();
        s2.push(c);
        s1.pop();
    }
    
    int ele = s2.top();
    s2.pop();
    while(!s2.empty())
    {
        int c = s2.top();
        s1.push(c);
        s2.pop();
    }
    
    return ele;
    
    
}