//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
int solve(int N,int arr[],int sum2){
    int dp[N+1][sum2+1];
    for(int i=0;i<N+1;i++){
        dp[i][0]=1;
    }
    for(int j=1;j<sum2+1;j++){
        dp[0][j]=0;
    }
    for(int i=1;i<N+1;i++){
        for(int j=1;j<sum2+1;j++){
            if(arr[i-1]<=j){
                dp[i][j]=(dp[i-1][j-arr[i-1]] || dp[i-1][j]);
            }else{
                dp[i][j]=dp[i-1][j];
            }
        }
        
    }
    return dp[N][sum2];
    
}
    int equalPartition(int N, int arr[])
    {
        int sum2=0;
        for(int i=0;i<N;i++){
            sum2+=arr[i];
        }
       if(sum2%2!=0){
           return 0;
       }
        return solve(N,arr,sum2/2);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends