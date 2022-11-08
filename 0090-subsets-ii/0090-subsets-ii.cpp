class Solution {
    public: 
    void helper(vector<int>a, set<vector<int>>&s, vector<int>op) {
        if(a.size()==0) {
            sort(op.begin(),op.end());
            s.insert(op);
            return;
        }
        vector<int>op1=op;
        vector<int>op2=op;
        op2.push_back(a[0]);
        a.erase(a.begin()+0);
        helper(a,s,op1);
        helper(a,s,op2);
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
           vector<vector<int>>vec;
        vector<int>op;
        set<vector<int>>s;
        helper(nums,s,op);
        for(auto& ele: s)
  {
    vec.push_back(ele);
  }
        return vec;
    }
};