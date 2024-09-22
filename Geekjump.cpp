//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  int solve(vector<int>& height,int n,int index,vector<int>& dp){
      if(index==n-1){
          return 0;
      }
      
      //taking one steps
      if(dp[index]!=-1){
          return dp[index];
      }
      int onestep=INT_MAX;
      if(index+1<n){
          onestep=abs(height[index+1]-height[index]) + solve(height,n,index+1,dp);
      }

      //taking two steps
      int twostep=INT_MAX;
      if(index+2<n){
          twostep=abs(height[index+2]-height[index]) + solve(height,n,index+2,dp);
      }
      
      return dp[index]=min(onestep,twostep);

  }
    int minimumEnergy(vector<int>& height, int n) {
        // Code here
        int index=0;
        vector<int> dp(n,-1);
        return solve(height,n,index,dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimumEnergy(arr, N) << "\n";
    }
    return 0;
}
// } Driver Code Ends