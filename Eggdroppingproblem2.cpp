//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int dp[1002][1002];
    int solve(int n,int k){
        if(k==1 || k==0){
            return k;
        }
        if(n==1){
            return k;
        }
        if(dp[n][k]!=-1){
            return dp[n][k];
        }
        int mini=INT_MAX;
        for(int i=1;i<=k;i++){
            int low,high;
            if(dp[n-1][i-1]!=-1){
                low=dp[n-1][i-1];
            }else{
                low=solve(n-1,i-1);
                dp[n-1][i-1]=low;
            }
            
            if(dp[n][k-i]!=-1){
                high=dp[n][k-i];
            }else{
                high=solve(n,k-i);
                dp[n][k-i]=high;
            }
            
            int temp=1+max(low,high);
            
            mini=min(mini,temp);
        }
        return dp[n][k]=mini;
    }
    int eggDrop(int n, int k) 
    {
        memset(dp,-1,sizeof(dp));
        return solve(n,k);
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;
        Solution ob;
        //calling function eggDrop()
        cout<<ob.eggDrop(n, k)<<endl;
    }
    return 0;
}

// } Driver Code Ends