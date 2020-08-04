// https://www.hackerrank.com/challenges/the-quickest-way-up/problem


/*
SOLUTION (https://medium.com/free-code-camp/the-perfect-programming-interview-problem-8431cdeab2a7)

We want to find the minimum number of moves of reaching the destination starting from the initial point on the grid. This boils down to
finding the shortest path in an unweighted graph. You can either say this graph is unweighted, or you can say that all the edges are of
equal weights. Hence the weights can be ignored. Finding the shortest path in an unweighted graph is a pretty standard problem. The most
standard algorithm for solving it is the breadth first search algorithm. We don’t need any special state in our graph for breadth first search
like we needed in the case of dynamic programming. We can definitely have multiple ways of reaching a particular node from the starting position.
However, the first route that is discovered in the breadth first search algorithm is the shortest one. That is the basis for the algorithm.
*/


// THIS SOLUTION IS FOR THE TYPICAL PROBLEM
int quickestWayUp(vector<vector<int>> ladders, vector<vector<int>> snakes) {

    vector<int> g[120];
    int a,b;
    for(int i=1;i<=100;i++)
    {
        for(int j=i+1;j<=i+6;j++)
        {
            if(j<=100)
            g[i].push_back(j);
        }
    }

    for(int i=0;i<int(ladders.size());i++)
    {
        a = ladders[i][0];
        b = ladders[i][1];
        for(int j=a-6;j<=a;j++)
        {
            if(j>=1)
            g[j].push_back(b);
        }
    }

    for(int i=0;i<int(snakes.size());i++)
    {
        a = snakes[i][0];
        b = snakes[i][1];
        for(int j=a-6;j<=a;j++)
        {
            if(j>=1)
            g[j].push_back(b);
        }
        g[a].clear();
        g[a].push_back(b);
    }

    queue<int> q;
    vector<int> visited(101,0);
    vector<int> dist(101,0);
    q.push(1);
    visited[1] = 1;
    dist[1] = 0;

    while(!q.empty())
    {
        int cur = q.front();
        q.pop();

        for(int i=0;i<g[cur].size();i++)
        {
            if(!visited[g[cur][i]])
            {
                q.push(g[cur][i]);
                visited[g[cur][i]] = 1;
                dist[g[cur][i]] = dist[cur]+1;
            }

        }

    }

    if(dist[100]>0)
    return dist[100];

    else
    return -1;
}
