//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  const int modulo=1e9+7;
  
    long long int topDown(int n) {
        vector<long long int> t(n+1);
        t[0]=0;
        t[1]=1;
        for(int i=2;i<n+1;i++){
            t[i]=(t[i-1]+t[i-2])%modulo;
        }
        return t[n];
    }
    long long int solve(int n,vector<long long int>& dp){
        if(n<=1){
            return n;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        
        return dp[n]=(solve(n-1,dp)+solve(n-2,dp))%modulo;
    }
    
    long long int bottomUp(int n) {
        vector<long long int> dp(n+1,-1);
        return solve(n,dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;
        long long int topDownans = obj.topDown(n);
        long long int bottomUpans = obj.bottomUp(n);
        if (topDownans != bottomUpans) cout << -1 << "\n";
        cout << topDownans << "\n";
    }
}
// } Driver Code Ends