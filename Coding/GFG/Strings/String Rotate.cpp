//
//  12.cpp
//  Coding
//
//  Created by Surya Dheeshjith on 04/07/19.
//  Copyright © 2019 Surya Dheeshjith. All rights reserved.
//
//String Rotate
#include<iostream>
using namespace std;

void checkme(string a,string b)
{
    int len = a.length();
    if(a.length()!=b.length())
    {
        cout<<0;
        return;
    }
    string first = "",second = "";
    first+= b.substr(len-2,2)+b.substr(0,len-2);
    second+= b.substr(2,len)+b.substr(0,2);
    
    if(a.compare(first)==0||a.compare(second)==0)
    cout<<1;
    
    else
    cout<<0;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string a;
        string b;
        cin>>a>>b;
        checkme(a,b);
        cout<<endl;
        //Enter code here
    }
}
