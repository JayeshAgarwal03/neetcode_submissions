class Solution {
public:
    int f(string &s, string &t, vector<vector<int>> &dp, int i, int j){
        if(j==0){
            return dp[i][j]=1;
        }
        else if(i==0){
            return dp[i][j]=0;
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }


        if(s[i-1]==t[j-1]){
            int take=f(s, t, dp, i-1, j-1);
            int notTake=f(s, t, dp, i-1, j);
            return dp[i][j]=take+notTake;
        }
        else{
            return dp[i][j]=f(s, t, dp, i-1, j);
        }
    }
    int numDistinct(string s, string t) {
        vector<vector<int>> dp(s.size()+1, vector<int>(t.size()+1, -1));
        int ways=f(s, t, dp, s.size(), t.size());
        return ways;
    }
};
