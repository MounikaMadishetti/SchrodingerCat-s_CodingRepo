class Solution {
     public:
    int maxH(int a[], int n) {
        int i=0;
        int maxArea=0;
        int area=0;
        stack<int>stk;
        while(i<n) {
            if(stk.size()==0||a[stk.top()]<=a[i]) {
                stk.push(i);
                i++;
            } else {
                int t = stk.top();
                stk.pop();
                if(stk.empty()) {
                    area = a[t] * i;
                } else {
                    area = a[t]*(i-stk.top()-1);
                }
                maxArea = max(area, maxArea);
            }
        }
        while(!stk.empty()) {
            int t = stk.top();
            stk.pop();
            if(stk.empty()) {
                area = a[t]*i;
            } else {
                area = a[t]*(i-stk.top()-1);
            }
            maxArea=max(area, maxArea);
        }
        return maxArea;
    }
public:
    int maximalRectangle(vector<vector<char>>& M) {
       
        int n =M.size();
        int m=M[0].size();
         int a[m];
        int maxArea = 0;
        
        for(int i=0;i<m;i++) {
            a[i]=int(M[0][i]-'0');
        }
        int currArea=maxH(a, m);
        maxArea=max(currArea, maxArea);
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++) {
                if(int(M[i][j]-'0')==0){
                    a[j]=0;
                } else {
                    a[j]=a[j]+int(M[i][j]-'0');
                }
            }
             currArea=maxH(a, m);
            maxArea=max(maxArea, currArea);
        }
        return maxArea;
    }
};