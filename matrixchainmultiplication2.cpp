//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
int dp[1002][1002];
int solve(int N,int arr[],int i,int j){
    if(i>=j){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int mini=INT_MAX;
    for(int k=i;k<=j-1;k++){
        int temp=solve(N,arr,i,k) + solve(N,arr,k+1,j) + arr[i-1]*arr[k]*arr[j];
        if(temp<mini){
            mini=temp;
        }
    }
    return dp[i][j]=mini;
}
    int matrixMultiplication(int N, int arr[])
    {
        memset(dp,-1,sizeof(dp));
        int i=1;
        int j=N-1;
        return solve(N,arr,i,j);
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
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends