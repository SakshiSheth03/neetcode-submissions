class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0; i<9; i++) {
            for(int j=0; j<9; j++) {
                char num = board[i][j];
                if(num=='.') continue;
                for(int k=0; k<9; k++) {
                    if(board[i][k]==num && k!=j) return false;
                    if(board[k][j]==num && k!=i) return false;
                }
                for(int x=(i/3)*3; x<((i/3)*3 + 3); x++) {
                    for(int y=(j/3)*3; y<((j/3)*3 + 3); y++) {
                        if(i==x && j==y) continue;
                        if(num==board[x][y]) return false;
                    }
                }
            }
        }
        return true;
    }
};
