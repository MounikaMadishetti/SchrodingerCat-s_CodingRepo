class Solution {
    void solve(string op, int open, int close, vector<string> &vec) {
        if(open==0&&close ==0){
            vec.push_back(op);return;
        }
        if(open !=0) {
            string op1 = op;
            op1.push_back('(');
            solve(op1,open-1,close,vec);
        } 
        if(close > open) {
             string op2 = op;
            op2.push_back(')');
            solve(op2,open,close-1,vec);
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string>vec;
        solve("", n, n, vec);
        return vec;
    }
};