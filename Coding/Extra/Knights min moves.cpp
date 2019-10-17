//

//  Coding
//
//  Created by Surya Dheeshjith on 12/07/19.
//  Copyright © 2019 Surya Dheeshjith. All rights reserved.

// Minimum moves of a knight to reach the opponent on a N x N square chessboard.
#include</Users/suryad/Coding/Coding/Coding/stdc++.h>
#define pii pair<int,int>
using namespace std;

struct cell{
    int x;
    int y;
    int dist;
    cell(){}
    cell(int xi,int yi,int disti)
    {
        x = xi;
        y = yi;
        dist = disti;
    }
};

bool isInside(int x,int y, int n)
{
    if(x>=1 && x<=n && y>=1 && y<=n)
        return true;
    
    return false;
}



int minMoves(pii kp, pii op,int n)
{
    int dx[] = {-2,-1,1,2,-2,-1,1,2};
    int dy[] = {-1,-2,-2,-1,1,2,2,1};
    queue<cell> q;
    q.push(cell(kp.first,kp.second,0));
    
    int visit[n+1][n+1];
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            visit[i][j]=0;
    }
    
    visit[kp.first][kp.second]=1;
    
    cell t;
    int x,y;
    
    while(!q.empty())
    {
        t = q.front();
        q.pop();
        
        if(t.x==op.first && t.y==op.second)
            return t.dist;
        
        for(int i=0;i<8;i++)
        {
            x = t.x + dx[i];
            y = t.y + dy[i];
            
            if(!visit[x][y] && isInside(x,y,n))
            {
                q.push(cell(x,y,t.dist+1));
                visit[x][y]=1;
            }
        }
        
    }
    return -1;
}


int main()
{
    int n;
    cin>>n;
    pii kp; // Knight position
    cin>>kp.first>>kp.second;
    pii op; // Opponent pos
    cin>>op.first>>op.second;
    cout<<minMoves(kp,op,n);
    
}


