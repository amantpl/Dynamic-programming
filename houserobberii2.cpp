class Solution {
public:
int solve(vector<int>& nums,int start,int end){
    if(end==start) return nums[start];
    vector<int> dp(end-start+1,0);


    dp[0]=nums[start];
    dp[1]=max(nums[start],nums[start+1]);

    for(int i=2;i<end-start+1;i++){
        dp[i]=max(dp[i-1],dp[i-2]+nums[start+i]);
    }

    return dp[end-start];
}
    int rob(vector<int>& nums) {
        int index=0;
        int n=nums.size();
        if(n==1) return nums[0];
        int roblast= solve(nums,1,n-1); // exlcuding the first house

        int robfirst=solve(nums,0,n-2); //excluding the last house

        return max(robfirst,roblast); 
    }
};