class Solution {
private:
    void bfs(vector<vector<int>>& grid, int row, int col, vector<vector<int>>& dirs, int dist) {
        int m = grid.size();
        int n = grid[0].size();
        queue<vector<int>> q;
        q.push({row, col, dist});
        while(!q.empty()) {
            int r = q.front()[0];
            int c = q.front()[1];
            int d = q.front()[2];
            q.pop();
            for(auto& dir: dirs) {
                int nr = r + dir[0];
                int nc = c + dir[1];
                int nd = d + 1;
                if(nr>=0 && nr<m && nc>=0 && nc<n && grid[nr][nc]>nd) {
                    grid[nr][nc] = nd;
                    q.push({nr, nc, nd});
                }
            }
        }
    }
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dirs = {{0,1}, {1,0}, {0, -1}, {-1, 0}};
        for(int row=0; row<m; row++) {
            for(int col=0; col<n; col++) {
                if(grid[row][col] == 0) {
                    bfs(grid, row, col, dirs, 0);
                }
            }
        }
    }
};
