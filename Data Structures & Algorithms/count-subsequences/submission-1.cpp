class Solution {
public:
    int f(string &s, string &t, vector<vector<int>> &dp, int i1, int i2){
        //cout<<i1<<" "<<i2<<"\n";
        if(dp[i1][i2]!=-1){
            return dp[i1][i2];
        }
        if(i1==0){
            if(i2==0 && s[i1]==t[i2]){
                return dp[i1][i2]=1;
            }
            else{
                return dp[i1][i2]=0;
            }
        }
        else if(i2==0){
            if(s[i1]==t[i2]){
                return dp[i1][i2]=1+f(s, t, dp, i1-1, i2);
            }
            else{
                return dp[i1][i2]=f(s, t, dp, i1-1, i2);
            }
        }
        
        
        
        
        if(s[i1]==t[i2]){
            int take=f(s, t, dp, i1-1, i2-1);
            int notTake=f(s, t, dp, i1-1, i2);
            return dp[i1][i2]=take+notTake;
        }
        else{
            return dp[i1][i2]=f(s, t, dp, i1-1, i2);
        }
        
    }

    int numDistinct(string s, string t) {
        vector<vector<int>> dp(s.size(), vector<int>(t.size(), -1));
    
        int ans=f(s, t, dp, s.size()-1, t.size()-1);
        return ans;
    }
};
