class Solution {
public:
    bool isValid(string s) {
        int n = s.length();
        if(n%2 != 0) return false;
        stack<char> stk;
        stk.push(s[0]);
        for(int i=1; i<n; i++) {
            char c = s[i];
            if(c=='{' || c=='(' || c=='[') stk.push(c);
            if(c=='}') {
                if(!stk.empty() && stk.top()=='{') stk.pop();
                else return false;
            } else if(c==']') {
                if(!stk.empty() && stk.top()=='[') stk.pop();
                else return false;
            } else if(c==')') {
                if(!stk.empty() && stk.top()=='(') stk.pop();
                else return false;
            }
        }
        return stk.empty();
    }
};
