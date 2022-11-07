//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


// } Driver Code Ends
/*You are required to complete this method*/

class Solution{
    public: 
    int maxA(int a[], int n) {
        int i=0, area = 0, maxArea=0;
        stack<int>stk;
        while(i<n) {
            if(stk.size()==0||a[stk.top()] <= a[i]) {
                stk.push(i);i++;
            } else {
                int t = stk.top();
                stk.pop();
                if(stk.size()==0) 
                area = a[t]*i;
                else 
                area = a[t]*(i-stk.top()-1);
               
            }
             maxArea = max(area, maxArea);
        }
        while(!stk.empty()) {
                int t = stk.top();
                stk.pop();
                if(stk.size()==0) 
                area = a[t]*i;
                else 
                area = a[t]*(i-stk.top()-1);
                maxArea = max(area, maxArea);
            }
            return maxArea;
    }
  public:
    int maxArea(int M[MAX][MAX], int n, int m) {
        int a[m];
        for(int i=0;i<m;i++) 
        a[i]=M[0][i];
        int currArea = 0,maxArea=0;
        currArea = maxA(a,m);
        maxArea = max(currArea, maxArea);
        
        for(int i=1;i<n;i++) {
            for(int j=0;j<m;j++) {
                
                if(M[i][j]==0)
                a[j]=0;
                else a[j]=a[j]+M[i][j];
            }
            currArea = maxA(a,m);
             maxArea = max(currArea, maxArea);
        }
        return maxArea;
    }
};


//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}

// } Driver Code Ends