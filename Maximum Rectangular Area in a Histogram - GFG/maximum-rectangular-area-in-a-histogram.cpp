//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long a[], int n)
    {
        // Your code here
        stack<int>stk;
        int i=0;
        long long area = 0, maxArea = 0;
        while(i<n) {
            if(stk.size()==0 ||a[stk.top()] < a[i]) {
                stk.push(i);
                i++;
            } else {
                int t = stk.top();stk.pop();
                if(stk.size()==0) {
                    area = a[t]*i;
                } else {
                    area = a[t]*(i-stk.top()-1);
                }
                maxArea = max(area, maxArea);
            }
        }
        while(!stk.empty()) {
                int t = stk.top();stk.pop();
                if(stk.size()==0) {
                    area = a[t]*i;
                } else {
                    area = a[t]*(i-stk.top()-1);
                }
                maxArea = max(area, maxArea);
            }
            return maxArea;
    }
};


//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}

// } Driver Code Ends