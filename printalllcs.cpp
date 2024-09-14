//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
vector<vector<unordered_set<string>>> memo;
  void printlcs(string& s,string& t,int i,int j,string currentlcs,set<string>& result,vector<vector<int>>& dp){
      if(i==0 || j==0){
          reverse(currentlcs.begin(),currentlcs.end());
          result.insert(currentlcs);
          return ;
      }
      if(memo[i][j].find(currentlcs)!=memo[i][j].end()){
          return ;
      }
      
      memo[i][j].insert(currentlcs);
      
      if(s[i-1]==t[j-1]){
          currentlcs.push_back(s[i-1]);
          printlcs(s,t,i-1,j-1,currentlcs,result,dp);
      }else{
          if(dp[i-1][j]==dp[i][j]){
              printlcs(s,t,i-1,j,currentlcs,result,dp);
          }
          
          if(dp[i][j-1]==dp[i][j]){
              printlcs(s,t,i,j-1,currentlcs,result,dp);
          }
      }
  }
  vector<string> solve(string s,string t,int n,int m){
      vector<vector<int>> dp(n+1,vector<int> (m+1,0));
      memo=vector<vector<unordered_set<string>>>(n+1,vector<unordered_set<string>>(m+1));
      for(int i=1;i<n+1;i++){
          for(int j=1;j<m+1;j++){
              if(s[i-1]==t[j-1]){
                  dp[i][j]=1+dp[i-1][j-1];
              }else{
                  dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
              }
          }
      }
      int i=n;
      int j=m;
      string currentlcs="";
      set<string> result;
      //recursion for finding all lcs
      printlcs(s,t,i,j,currentlcs,result,dp);
      vector<string> lcs(result.begin(),result.end());
      return lcs;
      
  }
    vector<string> all_longest_common_subsequences(string s, string t) {
        int n=s.size();
        int m=t.size();
        return solve(s,t,n,m);
    }
};


//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        vector<string> ans = ob.all_longest_common_subsequences(s, t);
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends