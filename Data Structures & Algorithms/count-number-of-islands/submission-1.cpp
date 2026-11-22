class Solution {
private:
    void bfs(vector<vector<char>>&grid, vector<vector<bool>>& vis, int row, int col) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q; // row-col pair
        q.push({row, col});
        vis[row][col] = true;
        vector<vector<int>> directions = {{-1,0}, {0, 1}, {1, 0}, {0, -1}};
        while(!q.empty()) {
            // {row-1, col}, {row+1, col}, {row, col-1}, {row, col+1}      
            row = q.front().first;
            col = q.front().second;
            q.pop(); 
            for(auto direction: directions) {
                int nrow = row + direction[0];
                int ncol = col + direction[1];
                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && !vis[nrow][ncol] && grid[nrow][ncol]=='1') {
                    vis[nrow][ncol] = true;
                    q.push({nrow, ncol});
                }
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(); // rows
        int n = grid[0].size(); // cols
        vector<vector<bool>> vis(m, vector<bool>(n, false)); // marks visited
        int cnt=0; // no of islands
        for(int row = 0; row<m; row++) {
            for(int col = 0; col<n; col++) {
                if(grid[row][col] == '1' && !vis[row][col]) {
                    bfs(grid, vis, row, col);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
