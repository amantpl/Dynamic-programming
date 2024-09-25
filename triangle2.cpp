class Solution {
public:
int solve(vector<vector<int>>& triangle,int n){
    vector<vector<int>> dp(n,vector<int>(n,0));

    dp[0][0]=triangle[0][0];


    for(int i=0;i<n;i++){
        for(int j=0;j<i+1;j++){

            if(i==0 && j==0) continue;
            int up=INT_MAX;
            int diagonal=INT_MAX;

            if(j<i){
                up=dp[i-1][j] + triangle[i][j];
            }

            if(j>0){
                diagonal=dp[i-1][j-1]+triangle[i][j];
            }

            dp[i][j]=min(up,diagonal);
        }
    }
    int mintotal=INT_MAX;
    for(int j=0;j<n;j++){
        mintotal=min(mintotal,dp[n-1][j]);
    }
    return mintotal;
}
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        return solve(triangle,n);
    }
};