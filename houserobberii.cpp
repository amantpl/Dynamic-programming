class Solution {
public:
int solve(vector<int>& nums,int n,int index,vector<int>& dp){
    if(index>=n){
        return 0;
    }

    
    if(dp[index]!=-1){
        return dp[index];
    }
    //exclude the 
    int exclude=solve(nums,n,index+1,dp);

    int include=nums[index] + solve(nums,n,index+2,dp);

    return dp[index]=max(include,exclude);

}
    int rob(vector<int>& nums) {
        int index=0;
        int n=nums.size();
        vector<int> dp1(n,-1);
        vector<int> dp2(n,-1);
        if(n==1) return nums[0];
        int roblast= solve(nums,n,index+1,dp1); // exlcuding the first house

        int robfirst=solve(nums,n-1,index,dp2); //excluding the last house

        return max(robfirst,roblast); 
    }
};