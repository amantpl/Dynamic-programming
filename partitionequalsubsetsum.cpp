//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
void solve(int N,int arr[],int sum1,int sum2,int index,int& ans){
    if(sum1==sum2){
        ans=1;
        return ;
    }
    if(index==N){
        return ;
    }
    
    //Exclude the element
    solve(N,arr,sum1,sum2,index+1,ans);
    
    //Include the element
    sum1=sum1+arr[index];
    sum2=sum2-arr[index];
    solve(N,arr,sum1,sum2,index+1,ans);
    
}
    int equalPartition(int N, int arr[])
    {
        int index=0;
        int sum1=0;
        int sum2=0;
        for(int i=0;i<N;i++){
            sum2+=arr[i];
        }

        int ans=0;
        solve(N,arr,sum1,sum2,index,ans);
        return ans;
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