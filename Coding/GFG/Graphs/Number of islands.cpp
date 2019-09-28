//
//  Coding
//
//  Created by Surya Dheeshjith on 02/07/19.
//  Copyright © 2019 Surya Dheeshjith. All rights reserved.


//Number of islands

int row[] = {-1,-1,-1,0,0,1,1,1};
int col[] = {-1,0,1,-1,1,-1,0,1};

int isSafe(int i,int j,vector<int> A[], vector<vector<bool>> &vis,int N, int M)
{
    return i>=0 && i<N && j>=0 && j<M && !vis[i][j] && A[i][j];
}
void dfs(int i,int j,vector<int> A[], vector<vector<bool>> &vis,int N, int M)
{
    vis[i][j] = true;
    for(int k=0;k<8;k++)
    {
        if(isSafe(i+row[k],j+col[k],A,vis,N,M))
        {
            dfs(i+row[k],j+col[k],A,vis,N,M);
        }
    }
}

int findIslands(vector<int> A[], int N, int M)
{
    
    vector<vector<bool>> vis(N,vector<bool>(M,false));
    // Your code here
    int count =0;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            if(!vis[i][j] && A[i][j])
            {
                dfs(i,j,A,vis,N,M);
                count++;
            }
        }
    }
    return count;
    
}

