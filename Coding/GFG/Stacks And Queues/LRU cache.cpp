//
//  29.cpp
//  Coding
//
//  Created by Surya Dheeshjith on 09/07/19.
//  Copyright © 2019 Surya Dheeshjith. All rights reserved.
//

// LRU cache
// SET AND GET.
// LIMIT ON CAPACITY, N. IF SET, AND IT EXISTS NEED TO REPLACE VALUE AND PUT IT ON TOP. IF DOES NOT EXIST CHECK CAPACITY IF IT CAN BE PUSHED DIRECTLY OTHERWISE LAST ELEMENT (LEAST RECENTLY USED) MUST BE REMOVED
// FOR GET, IF EXISTS YOU NEED TO OUTPUT VALUE AND PUT ON TOP....

#include</Users/suryad/Coding/Coding/Coding/stdc++.h>
    using namespace std;
    class LRUCache
    {
        stack<int> key;
        int arr[10000];
        int dummy[10000];
        int n;
        public:
        LRUCache(int );
        
        int get(int );
        
        void set(int , int );
    };
    int main()
    {
        int t;
        cin>>t;
        while(t--)
        {
            int n;
            cin>>n;
            LRUCache *l  = new LRUCache(n);
            int q;
            cin>>q;
            for(int i=0;i<q;i++)
            {
                string a;
                cin>>a;
                if(a=="SET")
                {
                    int aa,bb;
                    cin>>aa>>bb;
                    l->set(aa,bb);
                }else if(a=="GET")
                {
                    int aa;
                    cin>>aa;
                    cout<<l->get(aa)<<" ";
                }
            }
            cout<<endl;}}

/*This is a function problem.You only need to complete the function given below*/
/*The structure of the class is as follows
 class LRUCache
 {
 public:
 LRUCache(int );
 int get(int );
 void set(int , int );
 };*/
/*You are required to complete below methods */
/*Inititalize an LRU cache with size N */
stack<int> key;
int arr[10000];
int n;

void printk(stack<int> a)
{
    while(!a.empty())
    {
        cout<<"yo "<<a.top()<<endl;
        a.pop();
    }
}

LRUCache::LRUCache(int N)
{
    //Your code here
    int a[10000];
    n = N;
    while(!key.empty())
    key.pop();
    fill_n(arr, n, 2000);
    
}
/*Sets the key x with value y in the LRU cache */
void LRUCache::set(int x, int y)
{
    stack<int> temp;
    int count =0;
    int flag =0;
    //Your code here
    // printk(key);
    while(!key.empty())
    {
        
        int k = key.top();
        temp.push(k);
        if(k == x)
        {
            flag=1;
            arr[k] = y;
            key.pop();
            break;
        }
        key.pop();
        count++;
        
        
    }
    int k;
    if(flag==1)
    {
        k = temp.top();
        temp.pop();
    }
    
    while(!temp.empty())
    {
        key.push(temp.top());
        temp.pop();
    }
    
    if(flag==1)
    {
        key.push(k);
    }
    if(flag==0)
    {
        if(key.size()<n)
        {
            key.push(x);
            arr[x] = y;
        }
        else
        {
            while(!key.empty())
            {
                temp.push(key.top());
                key.pop();
                
            }
            temp.pop();
            
            while(!temp.empty())
            {
                key.push(temp.top());
                temp.pop();
                
            }
            key.push(x);
            arr[x] = y;
        }
    }
}
/*Returns the value of the key x if
 present else returns -1 */
int LRUCache::get(int x)
{
    //Your code here
    
    stack<int> temp;
    
    if(key.empty())
    return -1;
    
    int flag=0,a;
    int k;
    while(!key.empty())
    {
        int k = key.top();
        temp.push(k);
        if(k==x)
        {
            flag=1;
            a = arr[k];
            key.pop();
            break;
        }
        
        key.pop();
        
    }
    int fu ; ///// AFTER GET WE NEED TO PUT IT ON TOP OF STACK
    if(flag==1)
    {
        fu = temp.top();
        temp.pop();
    }
    while(!temp.empty())
    {
        key.push(temp.top());
        temp.pop();
    }
    
    if(flag==0)
    return -1;
    
    key.push(fu);
    return a;
}
