#include<iostream>
#include</Users/suryad/Coding/Coding/Coding/stdc++.h>
using namespace std;

// Complete the knightlOnAChessboard function below.
vector<vector<int>> knightlOnAChessboard(int n) {

    vector<vector<int>> ans(n-1, vector<int> (n-1,-1));
    queue<pair<int,int>> q;
    pair<int,int> cur;
    
    int x,y;
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<n;j++)
        {
            q.empty();
            vector<vector<int>> visited(n,vector<int> (n,0));
            vector<vector<int>> dist(n, vector<int> (n,0));
            q.push(make_pair(0,0));
            visited[0][0]=1;
            dist[0][0] =0;

            while(!q.empty())
            {
                cur = q.front();
                q.pop();
                for(int a=-1;a<2;a+=2)
                {
                    for(int b=-1;b<2;b+=2)
                    {
                        x = cur.first + a*i;
                        y = cur.second + b*j;

                        if(x>=0 && x<n && y>=0 && y<n && !visited[x][y])
                        {
                            q.push(make_pair(x,y));
                            visited[x][y]=1;
                            dist[x][y] = dist[cur.first][cur.second]+1;
                        }
                    }
                }

                for(int a=-1;a<2;a+=2)
                {
                    for(int b=-1;b<2;b+=2)
                    {
                        x = cur.first + a*j;
                        y = cur.second + b*i;

                        if(x>=0 && x<n && y>=0 && y<n && !visited[x][y])
                        {
                            q.push(make_pair(x,y));
                            visited[x][y]=1;
                            dist[x][y] = dist[cur.first][cur.second]+1;
                        }
                    }
                }
                
            }

            ans[i][j] = dist[n-1][n-1];
        }

    }

    return ans;


}


int main()
{
    int n;
    cin>>n;
    vector<vector<int>> a;
    a = knightlOnAChessboard(n)

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}