class Solution {
public:
    int f(string &text1, string &text2, vector<vector<int>> &dp, int i1, int i2){
        if(i1==0 || i2==0){
            return dp[i1][i2]=0;
        }
        
        if(dp[i1][i2]!=-1){
            return dp[i1][i2];
        }
        
        if(text1[i1-1]==text2[i2-1]){
            return dp[i1][i2]=1+f(text1, text2, dp, i1-1, i2-1);
        }
        else{
            int c1=f(text1, text2, dp, i1, i2-1);
            int c2=f(text1, text2, dp, i1-1, i2);
            return dp[i1][i2]=max(c1, c2);
        }
        
    }
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size()+1, vector<int>(text2.size()+1, -1));

        return f(text1, text2, dp, text1.size(), text2.size());
    }
};
