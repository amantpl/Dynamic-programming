//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
  int solve(int arr[],int n,int sum){
      int dp[n+1][sum+1];
      for(int i=0;i<n+1;i++){
          dp[i][0]=1;
      }
      for(int j=1;j<sum+1;j++){
          dp[0][j]=0;
      }
      for(int i=1;i<n+1;i++){
          for(int j=1;j<sum+1;j++){
              if(arr[i-1]<=j){
                  dp[i][j]=(dp[i-1][j-arr[i-1]] || dp[i-1][j]);
              }else{
                  dp[i][j]=dp[i-1][j];
              }
          }
      }
      
      int maxsubsetsum=0;
      for(int j=sum;j>=0;j--){
          if(dp[n][j]==1){
              maxsubsetsum=j;
              break;
          }
      }
      
      return 2*maxsubsetsum;
  }
	int minDifference(int arr[], int n)  { 
	    int sum=0;
	    for(int i=0;i<n;i++){
	        sum+=arr[i];
	    }
	    
	    int closestsum= solve(arr,n,sum/2);
	    return sum-closestsum;
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends