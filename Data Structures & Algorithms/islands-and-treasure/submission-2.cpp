class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        for(int row=0; row<m; row++) {
            for(int col=0; col<n; col++) {
                if(grid[row][col] == 0) {
                    q.push({row, col});
                    vis[row][col] = true;
                }
            }
        }
        vector<vector<int>> dirs = {{0,1}, {1,0}, {0, -1}, {-1, 0}};
        int dist = 0;
        while(!q.empty()) {
            int size = q.size();
            for(int i=0; i<size; i++) {
                int row = q.front().first;
                int col = q.front().second;
                q.pop();
                for(auto& dir: dirs) {
                    int nr = row + dir[0];
                    int nc = col + dir[1];
                    if(nr>=0 && nr<m && nc>=0 && nc<n && !vis[nr][nc] && grid[nr][nc] > 0) {
                        q.push({nr, nc});
                        vis[nr][nc] = true;
                        grid[nr][nc] = dist + 1;
                    }
                }
            }
            dist++;
        }
    }
};
