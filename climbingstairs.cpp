class Solution {
public:
int solve(int n){
    vector<int> dp(n+10,0);
    dp[0]=1;
    dp[1]=1;
    dp[2]=2;
    for(int i=3;i<n+1;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
}
    int climbStairs(int n) {
        return solve(n);
    }
};