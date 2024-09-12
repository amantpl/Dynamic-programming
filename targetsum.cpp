class Solution {
public:
int solve(vector<int>& nums,int n,int sum){
    vector<vector<int>> dp(n+1,vector<int> (sum+1,0));
    for(int i=0;i<n+1;i++){
        dp[i][0]=1;
    }
    for(int i=1;i<n+1;i++){
        for(int j=0;j<sum+1;j++){
            if(nums[i-1]<=j){
                dp[i][j]=(dp[i-1][j-nums[i-1]] + dp[i-1][j]);
            }else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[n][sum];
}
    int findTargetSumWays(vector<int>& nums, int target) {
        int totalsum=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            totalsum+=nums[i];
        }
        if((totalsum-target)%2!=0 || totalsum<target){
            return 0;
        }
        int targetsum=(totalsum-target)/2;
        return solve(nums,n,targetsum);
    }
};