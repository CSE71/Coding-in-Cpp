//
//  Coding
//
//  Created by Surya Dheeshjith on 02/07/19.
//  Copyright © 2019 Surya Dheeshjith. All rights reserved.


//Largest number possible given no. of digits and sum of digits
#include<iostream>
using namespace std;

string findnum(int n,int sum)
{
    int no =9;
    string res=""; // As even long long int couldnt handle 
    int i=n;
    if(sum==0 || n*9<sum)
    return "-1";
    while(i>0)
    {
        if(sum>=no)
        {
            res+=to_string(no);
            sum-=no;
        }
        else if(sum<no && sum>0)
        {
            res+=to_string(sum);
            sum=0;
        }
        else
        {
            res += to_string(0);
        }
        i--;
    }
    return res;
}
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        //Enter code here
        int n;
        int k;
        cin>>n>>k;
        cout<<findnum(n,k)<<endl;
    }
}
