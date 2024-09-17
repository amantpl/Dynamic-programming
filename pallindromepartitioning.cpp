//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
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
    int ans=INT_MAX;
    for(int k=i;k<=j-1;k++){
        int temp=solve(str,i,k) + solve(str,k+1,j) + 1;
        ans=min(ans,temp);
    }
    return ans;
}
    int palindromicPartition(string str)
    {
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