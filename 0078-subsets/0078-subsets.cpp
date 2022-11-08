class Solution {
    void helper(vector<int>a, vector<vector<int>> &vec, vector<int>op) {
        if(a.size()==0) {
            vec.push_back(op);
            return;
        }
        vector<int> op1=op;
        vector<int>op2=op;
        op2.push_back(a[0]);
        a.erase(a.begin()+0);
        helper(a,vec,op1);
        helper(a,vec,op2);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>vec;
        vector<int>op;
        helper(nums,vec,op);
        return vec;
    }
};