class Solution {
 public:
    void helper(string s, string op, vector<string>&vec, int n){
        if(s.length()==0){
            auto itr = find(vec.begin(),vec.end(), op);
            if(itr==vec.end()){
                if(op.length()==n)
            vec.push_back(op);
            }
            return;
        }
        string op1=op;
        string op2=op;
        op1.push_back(s[0]);
        if(islower(s[0])){
            op2.push_back(toupper(s[0]));
        }
        else if(isupper(s[0])){
            op2.push_back(tolower(s[0]));
        }
        s.erase(s.begin()+0);
        helper(s,op1,vec,n);
        helper(s,op2,vec,n);
    }
public:
    vector<string> letterCasePermutation(string S) {
        string op="";
        vector<string>vec;
        helper(S,op,vec,S.length());
        return vec;
    }
};