class Solution {
private:
    void addParenthesis(int& n, vector<string>& strs, int open, int close, string& s) {
        if(open==close && open==n) {
            strs.push_back(s);
            return;
        }
        if(open<n) {
            s+="(";
            addParenthesis(n, strs, open+1, close, s);
            s.pop_back();
        }
        if(close<open) {
            s+=")";
            addParenthesis(n, strs, open, close+1, s);
            s.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> strs;
        string s;
        addParenthesis(n, strs, 0, 0, s);
        return strs;
    }
};
