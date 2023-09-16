//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int equalPartition(int n, int arr[])
    {int s=0;
       
        for(int i=0;i<n;i++) {
            s=s+arr[i];
        }
        if(s%2!=0) return 0;
        int w = s/2;
         int dp[n+1][w+1];
        for(int i=0;i<n+1;i++) {
            for(int j=0;j<w+1;j++) {
                if(i==0||j==0)
                dp[i][j]=0;
                else if(arr[i-1]<=j)
                dp[i][j]=max(dp[i-1][j], arr[i-1]+dp[i-1][j-arr[i-1]]);
                else 
                dp[i][j]=dp[i-1][j];
            }
        }
        return dp[n][w]==w;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends