//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    int longestPalinSubseq(string a) {
        //code here
        int n = a.length();
        int dp[n+1][n+1];
        string b = a;
        reverse(b.begin(), b.end());
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
        return dp[n][n];
    }
};

//{ Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends