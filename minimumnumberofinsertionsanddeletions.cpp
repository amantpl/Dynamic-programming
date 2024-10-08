//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	int solve(string& str1,string& str2,int n,int m){
	    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
	    for(int i=1;i<n+1;i++){
	        for(int j=1;j<m+1;j++){
	            if(str1[i-1]==str2[j-1]){
	                dp[i][j]=1+dp[i-1][j-1];
	            }else{
	                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
	            }
	        }
	    }
	    return dp[n][m];
	}
	int minOperations(string str1, string str2) 
	{ 
	    int n=str1.size();
	    int m=str2.size();
	    int lcs_len=solve(str1,str2,n,m);
	    int deletion_count=n-lcs_len;
	    int insertion_count=m-lcs_len;
	    int ans=insertion_count+deletion_count;
	    return ans;
	} 
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends