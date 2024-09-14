//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  int solve(string str1,string str2,int n,int m){
      vector<vector<int>> dp(n+1,vector<int> (m+1,0));
      int max_len=INT_MIN;
      for(int i=1;i<n+1;i++){
          for(int j=1;j<m+1;j++){
              if(str1[i-1]==str2[j-1]){
                  dp[i][j]=1+dp[i-1][j-1];
                  max_len=max(max_len,dp[i][j]);
              }
          }
      }
      return max_len == INT_MIN ? 0:max_len;
  }
    int longestCommonSubstr(string str1, string str2) {
        int n=str1.size();
        int m=str2.size();
        return solve(str1,str2,n,m);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr(s1, s2) << endl;
    }
}
// } Driver Code Ends