class Solution {
public:
int solve(vector<int>& nums,int index,int n,vector<int>& dp){
    if(index>=n){
        return 0;
    }

    if(dp[index]!=-1){
        return dp[index];
    }
    //exclude the current element
    int exclude=solve(nums,index+1,n,dp);

    //include the current element
    int include=nums[index]+ solve(nums,index+2,n,dp);

    return dp[index]=max(include,exclude);
}
    int rob(vector<int>& nums) {
        int index=0;
        int n=nums.size();
        vector<int> dp(n,-1);
        return solve(nums,index,n,dp);
    }
};