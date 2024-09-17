//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
int dp[1002][1002];
bool ispallindrome(string& str,int i,int j){
    while(i<j){
        if(str[i]!=str[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
}
int solve(string& str,int i,int j){
    if(i>=j){
        return 0;
    }
    if(ispallindrome(str,i,j)){
        return 0;

    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    
    int ans=INT_MAX;
    for(int k=i;k<=j-1;k++){
        int left;
        int right;
        if(dp[i][k]!=-1){
            left=dp[i][k];
        }else{
            left=solve(str,i,k);
            dp[i][k]=left;
        }
        
        if(dp[k+1][j]!=-1){
            right=dp[k+1][j];
        }else{
            right=solve(str,k+1,j);
            dp[k+1][j]=right;
        }
        
        int temp=1+left+right;
        ans=min(temp,ans);
    }
    return dp[i][j]=ans;
}
    int palindromicPartition(string str)
    {
        memset(dp,-1,sizeof(dp));
        int n=str.size();
        int i=0;
        int j=n-1;
        solve(str,i,j);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends