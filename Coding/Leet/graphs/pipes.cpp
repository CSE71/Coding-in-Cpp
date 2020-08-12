//https://leetcode.com/contest/weekly-contest-181/problems/check-if-there-is-a-valid-path-in-a-grid/

vector<vector<vector<int>>> key = { {{0,-1},{0,1}},
                                    {{-1,0},{1,0}},
                                    {{0,-1},{1,0}},
                                    {{1,0},{0,1}},
                                    {{0,-1},{-1,0}},
                                    {{-1,0},{0,1}}};

class Solution {
public:



    bool hasValidPath(vector<vector<int>>& grid) {

        int m = int(grid.size());
        int n = int(grid[0].size());
        vector<vector<int>> visited(m,vector<int>(n,0));

        int nx,ny;
        queue<pair<int,int>> bfs;
        bfs.push(make_pair(0,0));
        visited[0][0]=1;

        while(!bfs.empty())
        {
            pair<int,int> p = bfs.front();
            bfs.pop();

            int type = grid[p.first][p.second];
            type--;
            for(auto x : key[type])
            {
                nx = p.first+x[0]; ny = p.second+x[1];
                if(nx<0 || nx>=m || ny<0 || ny>=n || visited[nx][ny]==1)
                    continue;

                int new_type = grid[nx][ny];
                new_type--;
                for(auto y : key[new_type])
                {
                    if(p.first==nx+y[0] && p.second == ny+y[1])
                    {

                        visited[nx][ny]=1;
                        bfs.push(make_pair(nx,ny));
                    }
                }
            }
        }

        return visited[m-1][n-1];



    }
};
