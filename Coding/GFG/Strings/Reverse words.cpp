
//
//  8.cpp
//  Coding
//
//  Created by Surya Dheeshjith on 04/07/19.
//  Copyright © 2019 Surya Dheeshjith. All rights reserved.
//

// Reverse words in a sentence
#include</Users/suryad/Coding/Coding/Coding/stdc++.h>
#include<iostream>
#include<string>
using namespace std;


string reverse(string rev)
{
    string ret="";
    for(int i=rev.size()-1;i>=0;i--)
        ret+=rev[i];
    
    return ret;
}
string reverseWords(string s)
{
    string rev = "",finalrev ="";
    
    for(int i=0;i<=s.size();i++) // Till \0
    {
        cout<<rev<<endl;
        if(s[i]==' ')
        {
            finalrev+= reverse(rev)+' ';
            rev="";
        }
        
        else if(s[i]=='\0')
        finalrev+= reverse(rev)+'\0';
        
        else
            rev+=s[i];
    }
    return finalrev;
}


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin.ignore();
        getline(cin,s);
        cout<<reverseWords(s);
    }
}
