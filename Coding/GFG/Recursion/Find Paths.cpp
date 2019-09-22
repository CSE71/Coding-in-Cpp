
//  Created by Surya Dheeshjith on 02/07/19.
//  Copyright © 2019 Surya Dheeshjith. All rights reserved.


//Find paths from 0,0 to m-1,n-1
#include<iostream>
using namespace std;
int count =0;
void findpaths(int i, int j, int m, int n)
{
    if(i>=m || j>=n)
    return;
    
    if(i==m-1 && j==n-1)
    {
        count++;
        return;
    }
    findpaths(i+1,j,m,n);
    findpaths(i,j+1,m,n);
}
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        //Enter code here
        int m,n;
        cin>>m>>n;
        findpaths(0,0,m,n);
        cout<<count<<endl;
        count=0;
    }
}
