class Solution {
public:
string solve(string&  str1,string& str2,int n,int m){
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    for(int i=0;i<n+1;i++){
        dp[i][0]=i;
    }
    for(int j=0;j<m+1;j++){
        dp[0][j]=j;
    }

    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            if(str1[i-1]==str2[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }else{
                dp[i][j]=1+min(dp[i-1][j],dp[i][j-1]);
            }
        }
    }

    int i=n;
    int j=m;
    string result="";
    while(i>0 && j>0){
        if(str1[i-1]==str2[j-1]){
            result.push_back(str1[i-1]);
            i--;
            j--;
        }else{
            if(dp[i-1][j]>dp[i][j-1]){
                result.push_back(str2[j-1]);
                j--;
            }else{
                result.push_back(str1[i-1]);
                i--;
            }
        }
    }
    while(i>0){
        result.push_back(str1[i-1]);
        i--;
    }

    while(j>0){
        result.push_back(str2[j-1]);
        j--;
    }
    reverse(result.begin(),result.end());
    return result;
}
    string shortestCommonSupersequence(string str1, string str2) {
        int n=str1.size();
        int m=str2.size();
        return solve(str1,str2,n,m);
    }
};