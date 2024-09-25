class Solution {
public:
int solve(vector<vector<int>>& grid,int n,int m,int i,int j,vector<vector<int>>& dp){
    if(i==n-1 && j==m-1){
        return grid[i][j];
    }


    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    //moving downward
    int downsum=INT_MAX;
    if(i<n-1){
        downsum=grid[i][j]+solve(grid,n,m,i+1,j,dp);
    }

    //moving upward
    int rightsum=INT_MAX;
    if(j<m-1){
        rightsum=grid[i][j]+solve(grid,n,m,i,j+1,dp);
    }

    return dp[i][j]=min(rightsum,downsum);
}
    int minPathSum(vector<vector<int>>& grid) {
        int i=0;
        int j=0;
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return solve(grid,n,m,i,j,dp);
    }
};