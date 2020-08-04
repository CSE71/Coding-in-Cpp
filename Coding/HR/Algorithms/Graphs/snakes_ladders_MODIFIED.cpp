// THIS SOLUTION IS FOR WHEN A RANDOM DESTINATION IS GIVEN (NOT THE LAST CELL) AND WE MUST OUTPUT THE NUMBER OF LADDERS AND SNAKES ENCOUNTERED TO REACH THERE.



#include</Users/suryad/Coding/Coding/Coding/stdc++.h>
using namespace std;

struct cell{
    int dist;
    int snakes;
    int ladders;
};

void quickestWayUp(vector<vector<int> > ladders, vector<vector<int> > snakes, int dest) {

    vector<int> g[120];
    vector<int> ind(101,0);
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
        ind[b] = 1;
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

        ind[b] = -1;
    }

    queue<int> q;
    vector<int> visited(101,0);
    //vector<int> dist(101,0);
    struct cell cells[101];

    for(int i=1;i<=100;i++)
    {
        cells[i].dist = 0;
        cells[i].snakes = 0;
        cells[i].ladders = 0;

    }
    q.push(1);
    visited[1] = 1;
    

    while(!q.empty())
    {
        int cur = q.front();
        q.pop();

        for(int i=0;i<int(g[cur].size());i++)
        {
            if(!visited[g[cur][i]])
            {
                q.push(g[cur][i]);
                visited[g[cur][i]] = 1;
                cells[g[cur][i]].dist = cells[cur].dist+1;

                if(ind[g[cur][i]]!=0)
                {
                    if(ind[g[cur][i]]==1)
                    {
                        cout<<"Hello";
                        cells[g[cur][i]].snakes = cells[cur].snakes;
                        cells[g[cur][i]].ladders = cells[cur].ladders+1;
                    }
                    else
                    {
                        cells[g[cur][i]].snakes = cells[cur].snakes+1;
                        cells[g[cur][i]].ladders = cells[cur].ladders;
                    }
                    

                }
                else
                {
                    cells[g[cur][i]].snakes = cells[cur].snakes;
                    cells[g[cur][i]].ladders = cells[cur].ladders;
                }
                
                if(g[cur][i]==dest)
                break;
                
            }

        }

    }

    
    if(cells[dest].dist>0)
    {
        cout<<cells[dest].dist<<endl;
        cout<<cells[dest].ladders<<endl;
        cout<<cells[dest].snakes;
        
    }

    else
    cout<<-1;

}


int main()
{

    int t;
    cin >> t;

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int n;
        cin >> n;


        vector<vector<int> > ladders(n);
        for (int i = 0; i < n; i++) {
            ladders[i].resize(2);

            for (int j = 0; j < 2; j++) {
                cin >> ladders[i][j];
            }

    
        }

        int m;
        cin >> m;
    

        vector<vector<int> > snakes(m);
        for (int i = 0; i < m; i++) {
            snakes[i].resize(2);

            for (int j = 0; j < 2; j++) {
                cin >> snakes[i][j];
            }

          
        }

        int dest;
        cin >> dest;

        quickestWayUp(ladders, snakes, dest);
    }

    

    return 0;
}



// Does not run here. Run on hackerrank. See submission - https://www.hackerrank.com/challenges/the-quickest-way-up/submissions/code/172478550

/*

Sample I/P: 
(1)

1
3
32 62
42 68
12 98
7
99 50
97 25
93 37
79 27
75 19
49 47
67 17
51

(2)

1
3
32 62
42 68
12 98
7
99 50
97 25
93 37
79 27
75 19
49 47
67 17
100

*/