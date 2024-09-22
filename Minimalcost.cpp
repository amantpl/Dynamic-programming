//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  int solve(vector<int>& arr,int&k,int index,vector<int>& dp){
      if(index==arr.size()-1){
          return 0;
      }
      if(dp[index]!=-1){
          return dp[index];
      }
      int ans=INT_MAX;
      for(int i=1;i<=k;i++){
          //taking i steps
          if(index+i<arr.size()){
              int step=abs(arr[index+i]-arr[index]) + solve(arr,k,index+i,dp);
              ans=min(ans,step);
          }
      }
      
      return dp[index]=ans;
  }
    int minimizeCost(vector<int>& arr, int& k) {
        // Code here
        int index=0;
        vector<int> dp(arr.size(),-1);
        return solve(arr,k,index,dp);
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.minimizeCost(arr, k);
        cout << res << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends