//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
int minDeletions(string str, int n);

int main(){
    int t;
    cin >> t;
    while(t--){
        
        int n;
        cin >> n;
        string s;
        cin >> s;
        cout << minDeletions(s, n) << endl;

    }
return 0;
}
// } Driver Code Ends


int minDeletions(string a, int n) { 
    //complete the function here 
    string b = a;
    reverse(b.begin(), b.end());
    int dp[n+1][n+1];
    for(int i=0;i<n+1;i++) {
        for(int j=0;j<n+1;j++) {
            if(i==0||j==0)
            dp[i][j]=0;
            else if(a[i-1]==b[j-1])
            dp[i][j]=1+dp[i-1][j-1];
            else 
            dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return n-dp[n][n];
} 