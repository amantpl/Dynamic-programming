class Solution {
public:
int solve(string& s,string& t,int n,int m){
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            if(s[i-1]==t[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[n][m];
}
    bool isSubsequence(string s, string t) {
        int n=s.size();
        int m=t.size();
        int lcs_len=solve(s,t,n,m);
        if(lcs_len==n){
            return true;
        }
        return false;
    }
};