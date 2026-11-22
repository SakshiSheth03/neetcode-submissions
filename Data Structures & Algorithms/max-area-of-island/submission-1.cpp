class Solution {
private: 
    int dfs(int row, int col, vector<vector<int>>& grid, vector<vector<bool>>& vis) {
        int m = grid.size();
        int n = grid[0].size();

        if(row < 0 || row >= m || col < 0 || col >= n ||
           grid[row][col] == 0 || vis[row][col]) {
            return 0;
        }

        vis[row][col] = true; 

        int cnt = 1;

        cnt += dfs(row - 1, col, grid, vis);
        cnt += dfs(row + 1, col, grid, vis);
        cnt += dfs(row, col - 1, grid, vis);
        cnt += dfs(row, col + 1, grid, vis);

        return cnt;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        int maxi = 0;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j]==1 && !vis[i][j]) {
                    maxi = max(maxi, dfs(i, j, grid, vis));
                }
            }
        }
        return maxi;
    }
};
