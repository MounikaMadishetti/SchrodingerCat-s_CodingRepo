class Solution {
public:
    static bool cmp(pair<int,int> &a,pair<int,int> &b){
        return a.second>b.second;
    }
    public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        vector<pair<int,int>> v;
        for(int i=0;i<plantTime.size();i++){
            v.push_back({plantTime[i],growTime[i]});
        }
        sort(v.begin(),v.end(),cmp);
        int start=0;
        int ans=0;
        for(auto it:v){
            start+=it.first;
            ans=max(ans,start+it.second);
        }
        return ans;
    }
};