class Solution {
private: 
    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& vis, int row, int col, vector<pair<int, int>>& dirs, set<pair<int, int>>& mySet) {
        int m = heights.size();
        int n = heights[0].size();
        for(auto& dir: dirs) {
            int nr = row + dir.first;
            int nc = col + dir.second;
            if(nr>=0 && nr<m && nc>=0 && nc<n && !vis[nr][nc] && heights[nr][nc]>=heights[row][col]) {
                mySet.insert({nr, nc});
                vis[nr][nc] = true;
                dfs(heights, vis, nr, nc, dirs, mySet);
            }
        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        set<pair<int, int>> paci;
        set<pair<int, int>> atla;
        vector<pair<int, int>> dirs = {{0,1}, {1,0}, {0,-1}, {-1,0}};
        vector<vector<bool>> visPaci(m, vector<bool>(n, false));
        vector<vector<bool>> visAtla(m, vector<bool>(n, false));
        for(int i=0; i<m; i++) {
            paci.insert({i, 0});
            visPaci[i][0] = true;
            dfs(heights, visPaci, i, 0, dirs, paci);
            atla.insert({i, n-1});
            visAtla[i][n-1] = true;
            dfs(heights, visAtla, i, n-1, dirs, atla);
        }
        for(int j=0; j<n; j++) {
            paci.insert({{0, j}});
            visPaci[0][j]= true;
            dfs(heights, visPaci, 0, j, dirs, paci);
            atla.insert({m-1, j});
            visAtla[m-1][j] = true;
            dfs(heights, visAtla, m-1, j, dirs, atla);
        }
        vector<vector<int>> ans;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(paci.count({i,j}) && atla.count({i,j})) {
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
};
