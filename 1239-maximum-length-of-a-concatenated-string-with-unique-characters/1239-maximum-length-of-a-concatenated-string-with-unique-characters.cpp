class Solution {
public:
    
    bool unique(string &s){
        unordered_set<char> se;
        for(int i=0; i<s.size(); i++){
            if(se.find(s[i]) == se.end()) se.insert(s[i]);
            else return false;
        }
        return true;
    }
    
    int solve(vector<string> &arr, int i, string &ans){
        if(i == arr.size()) return 0;
        string tmp = ans + arr[i];
        if(unique(ans) && unique(tmp)) return max(int(arr[i].size()) + solve(arr, i+1, tmp), solve(arr, i+1, ans));
        return solve(arr, i+1, ans);
    }
    public:
    int maxLength(vector<string>& arr) {
        string helper;
        return solve(arr, 0, helper);        
    }
};