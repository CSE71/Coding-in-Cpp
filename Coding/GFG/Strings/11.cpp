//
//  11.cpp
//  Coding
//
//  Created by Surya Dheeshjith on 04/07/19.
//  Copyright © 2019 Surya Dheeshjith. All rights reserved.
//
#include<algorithm>
#include<iostream>
#include<stack>
using namespace std;
string fn(string s)
{
    
    if(s.empty())
    return "";
   
    int n=s.length();
    stack<char>st;
    int flag=0;
    
    for(int i=0;i<n;i++)
    st.push(s[i]);
    
    s="";
    
    char c=st.top();
    flag=0;
    st.pop();
    
    int key=0;
    while(!st.empty())
    {
        //cout<<st.top()<<" ";
        if(st.top()==c)
        {
            flag=1;
            key=1;
        }
        else
        {
            if(flag==0)
            s+=c;
            c=st.top();
            flag=0;
        }
        st.pop();
    }
    if(flag==0)
    s+=c;
    reverse(s.begin(),s.end());
    if(key)
    s=fn(s);
    return s;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        s=fn(s);
        cout<<s<<endl;
    }
    return 0;
}
