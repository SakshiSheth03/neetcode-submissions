class Solution {
private:
    bool findWord(int i, int j, int& m, int& n, vector<vector<char>>& board, string& word, vector<vector<bool>>& visited, string& str, int idx) {
    if(word.length() == idx) return true;
    if(i<0 || j<0 || i>m-1 || j>n-1) return false;
    if(visited[i][j]) return false;
    if(board[i][j] != word[idx]) return false;
    visited[i][j] = true;
    bool res = findWord(i+1, j, m, n, board, word, visited, str, idx+1) || findWord(i, j+1, m, n, board, word, visited, str, idx+1) || findWord(i-1, j, m, n, board, word, visited, str, idx+1) || findWord(i, j-1, m, n, board, word, visited, str, idx+1);
    visited[i][j] = false;
    return res;        
}
public:
    bool exist(vector<vector<char>>& board, string word) {
        string str;
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(findWord(i, j, m, n, board, word, visited, str, 0)) return true;
            }
        }
        return false;
    }
};
