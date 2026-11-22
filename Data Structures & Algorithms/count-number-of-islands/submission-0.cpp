class Solution {
private:
    void bfs(vector<vector<char>>&grid, vector<vector<bool>>& vis, int row, int col) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q; // row-col pair
        q.push({row, col});
        vis[row][col] = true;
        while(!q.empty()) {
            // {row-1, col}, {row+1, col}, {row, col-1}, {row, col+1}      
            row = q.front().first;
            col = q.front().second;
            q.pop(); 
            if(row-1 >= 0 && !vis[row-1][col] && grid[row-1][col]=='1') {
                q.push({row-1, col});
                vis[row-1][col]=true;
            } 
            if(row+1 < m && !vis[row+1][col] && grid[row+1][col]=='1') {
                q.push({row+1, col});
                vis[row+1][col]=true;
            } 
            if(col-1 >= 0 && !vis[row][col-1] && grid[row][col-1]=='1') {
                q.push({row, col-1});
                vis[row][col-1]=true;
            } 
            if(col+1<n && !vis[row][col+1] && grid[row][col+1]=='1') {
                q.push({row, col+1});
                vis[row][col+1]=true;
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
