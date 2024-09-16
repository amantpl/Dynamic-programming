//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
  int solve(string& A,string& B,int n){
      vector<vector<int>> dp(n+1,vector<int>(n+1,0));
      for(int i=1;i<n+1;i++){
          for(int j=1;j<n+1;j++){
              if(A[i-1]==B[j-1]){
                  dp[i][j]=1+dp[i-1][j-1];
              }else{
                  dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
              }
          }
      }
      return dp[n][n];
  }
    int longestPalinSubseq(string A) {
        reverse(A.begin(),A.end());
        string B=A;
        reverse(A.begin(),A.end());
        int n=A.size();
        return solve(A,B,n);
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