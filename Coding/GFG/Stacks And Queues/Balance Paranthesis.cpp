//
//  24.cpp
//  Coding
//
//  Created by Surya Dheeshjith on 07/07/19.
//  Copyright © 2019 Surya Dheeshjith. All rights reserved.
//
//Balance Paranthesis
// Check if a string of paranthesis are balanced

#include<iostream>
#include</Users/suryad/Coding/Coding/Coding/stdc++.h>
using namespace std;

stack<char> st;
bool iscor(char ch)
{

    if(st.empty())
    return false;
    char c = st.top();
    switch(ch)
    {
        case '}': if(c=='{')
        return true;
        else
        return false;
        case ']': if(c=='[')
        return true;
        else
        return false;
        case ')': if(c=='(')
        return true;
        else
        return false;

        default:
        cout<<1;
        return false;
    }
}
bool isbal(string s)
{

    while(!st.empty())
    st.pop();
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='{'||s[i]=='['||s[i]=='(')
        {
            //cout<<s[i];
            st.push(s[i]);
        }

        else if((s[i]=='}'||s[i]==']'||s[i]==')')&&iscor(s[i]))
        {
            //cout<<1;

            st.pop();

        }

        else
        {

            return false;
        }
    }
    if(st.empty())
    return true;

    else
    {
        //cout<<st.top();
        return false;
    }
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        if(isbal(s))
        {
            cout<<"balanced"<<endl;
        }
        else
        {
            cout<<"not balanced"<<endl;
        }
    }
}
