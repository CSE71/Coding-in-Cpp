//
//  27.cpp
//  Coding
//
//  Created by Surya Dheeshjith on 08/07/19.
//  Copyright © 2019 Surya Dheeshjith. All rights reserved.
//

//Stack using two queues


#include<bits/stdc++.h>
    using namespace std;
    class QueueStack{
        private:
        queue<int> q1;
        queue<int> q2;
        public:
        void push(int);
        int pop();
    };
    int main()
    {
        int T;
        cin>>T;
        while(T--)
        {
            QueueStack *qs = new QueueStack();
            int Q;
            cin>>Q;
            while(Q--){
                int QueryType=0;
                cin>>QueryType;
                if(QueryType==1)
                {
                    int a;
                    cin>>a;
                    qs->push(a);
                }else if(QueryType==2){
                    cout<<qs->pop()<<" ";
                }
            }
            cout<<endl;
        }
    }
    

/*This is a function problem.You only need to complete the function given below*/
/* The structure of the class is
 class QueueStack{
 private:
 queue<int> q1;
 queue<int> q2;
 public:
 void push(int);
 int pop();
 };
 */
/* The method push to push element into the stack */
void QueueStack :: push(int x)
{
    // Your Code
    q1.push(x);
}
/*The method pop which return the element poped out of the stack*/
int QueueStack :: pop()
{
    // Your Code
    if(q1.empty())
    return -1;
    
    //cout<<"Size: "<<q1.size()<<endl;
    while(q1.size()!=1) //for(int i=1;i<=q1.size()-1;i++) wont work cause q1 size keeps shrinking. so do int k = q1.size() then put it in loop.
    {
        //cout<<"Front :"<<q1.front()<<endl;
        int r = q1.front();
        q2.push(r);
        q1.pop();
    }
    //cout<<" "<<q1.size()<<endl;
    int ele = q1.front();
    //cout<<ele;
    q1.pop();
    //cout<<"Size2: "<<q1.size()<<endl;
    while(!q2.empty())
    {
        int r = q2.front();
        q2.pop();
        q1.push(r);
    }
    
    return ele;
}
