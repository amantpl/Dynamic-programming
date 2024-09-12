//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  int modulo=1e9+7;
  int solve(int n,vector<int>& arr,int sum){
      vector<vector<int>> dp(n+1,vector<int>(sum+1,0));
      for(int i=0;i<n+1;i++){
          dp[i][0]=1;
      }
      
      for(int i=1;i<n+1;i++){
          for(int j=0;j<sum+1;j++){
              if(arr[i-1]<=j){
                  dp[i][j]=(dp[i-1][j-arr[i-1]] + dp[i-1][j])%modulo;
              }else{
                  dp[i][j]=dp[i-1][j];
              }
          }
      }
      return dp[n][sum]%modulo;
  }
    int countPartitions(int n, int d, vector<int>& arr) {
        int totalsum=0;
        for(int i=0;i<n;i++){
            totalsum+=arr[i];
        }
        
        int target=(totalsum-d)/2;
        if((totalsum-d)%2!=0 || totalsum<d){
            return 0;
        }
        return solve(n,arr,target);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends