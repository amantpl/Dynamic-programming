class Solution {
public:
int solve(vector<vector<int>>& obstacleGrid,int n,int m,int i,int j,vector<vector<int>>& dp){
    if(i==n-1 && j==m-1){
        return 1;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int paths=0;
    //movving downward
    if(i<n-1 && obstacleGrid[i+1][j]!=1){
        paths+=solve(obstacleGrid,n,m,i+1,j,dp);
    }

    //moving rightward
    if(j<m-1 && obstacleGrid[i][j+1]!=1){
        paths+=solve(obstacleGrid,n,m,i,j+1,dp);
    }

    return dp[i][j]=paths;
}
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n=obstacleGrid.size();
        int m=obstacleGrid[0].size();
        int i=0;
        int j=0;
        if(obstacleGrid[i][j]==1){
            return 0;
        }
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return solve(obstacleGrid,n,m,i,j,dp);
    }
};