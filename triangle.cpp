class Solution {
public:
int solve(vector<vector<int>>& triangle,int n,int i,int j,vector<vector<int>>& dp){
    if(i==n-1){
        return triangle[i][j];
    }

    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    //moving downward
    int down=triangle[i][j]+solve(triangle,n,i+1,j,dp);
    

    //moving rightward
    int right=triangle[i][j] + solve(triangle,n,i+1,j+1,dp);
    

    return dp[i][j]=min(down,right);
}
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        int i=0;
        int j=0;
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return solve(triangle,n,i,j,dp);
    }
};