class Solution {
public:
int solve(vector<int>& nums,int n){
    vector<int> dp(n,0);

    if(n==0) return 0;
    if(n==1) return nums[0];

    dp[0]=nums[0];
    dp[1]=max(nums[0],nums[1]);

    //Table
    for(int i=2;i<n;i++){
        dp[i]=max(dp[i-1],dp[i-2]+nums[i]);
    }

    return dp[n-1];
}
    int rob(vector<int>& nums) {
        int n=nums.size();
        return solve(nums,n);
    }
};