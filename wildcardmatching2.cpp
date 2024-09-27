class Solution {
public:
int isallstars(string& p,int j){
    for(int i=0;i<j;i++){
        if(p[i]!='*'){
            return 0;
        }
    }
    return 1;
}
bool solve(string& s,string& p,int n,int m){
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    dp[0][0]=1;

    for(int j=1;j<m+1;j++){
        dp[0][j]=isallstars(p,j);
    }

    for(int i=1;i<n+1;i++){
        dp[i][0]=0;
    }
    
    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            if(s[i-1]==p[j-1] || p[j-1]=='?'){
                dp[i][j]=dp[i-1][j-1];
            }else if(p[j-1]=='*'){
                dp[i][j]=dp[i-1][j] || dp[i][j-1];
            }else{
                dp[i][j]=0;
            }
        }
    }

    return dp[n][m];

}
    bool isMatch(string s, string p) {
        int n=s.size();
        int m=p.size();
        return solve(s,p,n,m);
    }
};