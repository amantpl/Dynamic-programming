//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  int solve(vector<vector<int>>& arr,int n){
      //base case
      vector<vector<int>> dp(n,vector<int>(4,0));
      
      dp[0][0]=max(arr[0][1],arr[0][2]);
      dp[0][1]=max(arr[0][0],arr[0][2]);
      dp[0][2]=max(arr[0][1],arr[0][0]);
      dp[0][3]=max({arr[0][0],arr[0][1],arr[0][2]});
      
      for(int day=1;day<n;day++){
          for(int last=0;last<4;last++){
              for(int task=0;task<3;task++){
                  if(task!=last){
                      int points=arr[day][task]+dp[day-1][task];
                      dp[day][last]=max(dp[day][last],points);
                  }
              }
          }
      }
      return dp[n-1][3];
  }
    int maximumPoints(vector<vector<int>>& arr, int n) {
        return solve(arr,n);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> arr;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            arr.push_back(temp);
        }

        Solution obj;
        cout << obj.maximumPoints(arr, n) << endl;
    }
    return 0;
}
// } Driver Code Ends