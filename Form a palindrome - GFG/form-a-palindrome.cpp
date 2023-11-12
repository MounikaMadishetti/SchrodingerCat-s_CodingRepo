//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int findMinInsertions(string a){
        // code here 
        int n = a.length();
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
};

//{ Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        Solution ob;
        cout<<ob.findMinInsertions(S)<<endl;
    }
    return 0;
}

// } Driver Code Ends