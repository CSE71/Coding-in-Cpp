
//  Created by Surya Dheeshjith on 02/07/19.
//  Copyright © 2019 Surya Dheeshjith. All rights reserved.


//Rat Maze

// (0,0) --- > (n-1,n-1)
void paths(int i,int j,int m[MAX][MAX],int n,string s,vector<string> &res)
{
    if(i<0 || j<0 || i>=n || j>=n || m[i][j]==0 || m[i][j] ==-1)
    return;
    
    else if(i==n-1 && j==n-1)
    res.push_back(s);
    
    else
    {
        m[i][j]=-1;// To avoid looping
        paths(i+1,j,m,n,s+'D',res);
        paths(i,j-1,m,n,s+'L',res);
        paths(i,j+1,m,n,s+'R',res);
        paths(i-1,j,m,n,s+'U',res);
        m[i][j]=1;// Backtrack
    }
}
vector<string> printPath(int m[MAX][MAX], int n)
{
    //Your code here
    vector<string> res;
    paths(0,0,m,n,"",res);
    return res;
}
