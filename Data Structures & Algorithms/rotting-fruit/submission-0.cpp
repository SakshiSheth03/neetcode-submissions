class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j]==2) {
                    q.push({i, j});
                }
            }
        }  
        int time = 0;
        vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        while(!q.empty()) {
            int size = q.size();
            for(int k=0; k<size; k++) {
                int row = q.front().first;
                int col = q.front().second;
                q.pop();
                for(auto& dir: dirs) {
                    int nr = row + dir.first;
                    int nc = col + dir.second;
                    if(nr>=0 && nr<m && nc>=0 && nc<n && grid[nr][nc]==1)  {
                        q.push({nr, nc});
                        grid[nr][nc] = 2;
                    }
                }
            }
            if(!q.empty()) time++;
        }
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j]==1) {
                    return -1;
                }
            }
        }
        return time;
    }
};
