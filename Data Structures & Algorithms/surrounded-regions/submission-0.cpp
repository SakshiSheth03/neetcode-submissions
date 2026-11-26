class Solution {
private:
    void dfs(int row, int col, vector<vector<char>>& board, vector<vector<bool>>& vis, vector<pair<int, int>>& dirs) {
        vis[row][col] = true;
        int m = board.size();
        int n = board[0].size();
        for(auto& dir: dirs) {
            int nr = row + dir.first;
            int nc = col + dir.second;
            if(nr>=0 && nr<m && nc>=0 && nc<n && !vis[nr][nc] && board[nr][nc] == 'O') {
                dfs(nr, nc, board, vis, dirs);
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        vector<pair<int, int>> dirs = {{0,1}, {1,0}, {0, -1}, {-1, 0}};
        for(int i=0; i<m; i++) {
            // m rows
            if(board[i][0]=='O' && !vis[i][0]) {
                dfs(i, 0, board, vis, dirs);
            }
            if(board[i][n-1]=='O' && !vis[i][n-1]) {
                dfs(i, n-1, board, vis, dirs);
            }            
        }
        for(int i=0; i<n; i++) {
            // n cols
            if(board[0][i]=='O' && !vis[0][i]) {
                dfs(0, i, board, vis, dirs);
            }
            if(board[m-1][i]=='O' && !vis[m-1][i]) {
                dfs(m-1, i, board, vis, dirs);
            }            
        }
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(board[i][j]=='O' && !vis[i][j]) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};
