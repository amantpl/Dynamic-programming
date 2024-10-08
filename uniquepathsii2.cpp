class Solution {
public:
int solve(vector<vector<int>>& obstacleGrid,int n,int m){
    vector<vector<int>> dp(n,vector<int>(m,0));

    dp[0][0]=1;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==0 && j==0){
                continue;
            }
            int up=0;
            int left=0;

            if(i>0 && obstacleGrid[i-1][j]!=1){
                up=dp[i-1][j];
            }

            if(j>0 && obstacleGrid[i][j-1]!=1){
                left=dp[i][j-1];
            }

            dp[i][j]=up+left;
        }

    }
    return dp[n-1][m-1];
}
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n=obstacleGrid.size();
        int m=obstacleGrid[0].size();
        int i=0;
        int j=0;
        if(obstacleGrid[i][j]==1){
            return 0;
        }
        if(obstacleGrid[n-1][m-1]==1){
            return 0;
        }
        return solve(obstacleGrid,n,m);
    }
};