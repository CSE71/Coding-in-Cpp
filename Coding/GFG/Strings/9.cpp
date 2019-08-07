//
//  9.cpp
//  Coding
//
//  Created by Surya Dheeshjith on 04/07/19.
//  Copyright © 2019 Surya Dheeshjith. All rights reserved.
//

//Permutation


//Without inbuilt function
#include<iostream>
using namespace std;

void swap(char *a,char* b)
{
    char temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void permutationof(char* s,int i,int n)
{
    if(i==n)
    {
        cout<<s<<"\t";
    }
    else
    {
        for(int j=i;j<=n;j++)
        {
            swap(s[i],s[j]);
            permutationof(s,i+1,n);
            swap(s[i],s[j]);
        }
    }
}


int main()
{
    int a;
    cin>>a;
    for(int i=0;i<a;i++)
    {
        char s[100];
        cin>>s;
        permutationof(s,0,strlen(s)-1);
        cout<<endl;
        
    }
}

//With function
/*
 #include<bits/stdc++.h>
 using namespace std;
 
 int main()
 {
 int t;
 cin>>t;
 while(t--)
 {
 string s;
 cin>>s;
 sort(s.begin(),s.end());
 do
 {
 std::cout << s << " ";
 }
 while ( std::next_permutation(s.begin(), s.end()) );
 cout<<endl;
 }
 return 0;
 }
 */
