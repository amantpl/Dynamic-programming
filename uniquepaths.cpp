class Solution {
public:
int solve(int m,int n,int i,int j,vector<vector<int>>& dp){
    if(i==m-1 && j==n-1){
        return 1;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }

    int paths=0;
    //moving downward
    if(i<m-1){
        paths+=solve(m,n,i+1,j,dp);
    }

    //moving right
    if(j<n-1){
        paths+=solve(m,n,i,j+1,dp);
    }

    return dp[i][j]=paths;
}
    int uniquePaths(int m, int n) {
        int i=0;
        int j=0;
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return solve(m,n,i,j,dp);
    }
};