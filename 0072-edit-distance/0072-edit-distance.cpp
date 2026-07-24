class Solution {
public:
    int n1,n2;
    vector<vector<int>> dp;
    int solve(string& s1, string& s2, int i, int j) {
        if(i >= n1) {
            return n2-j;
        }
        if(j >= n2) {
            return n1-i;
        }
        if(dp[i][j] != -1) return dp[i][j];
        if(s1[i] == s2[j]) {
            return dp[i][j] = solve(s1,s2,i+1,j+1);
        }
        return dp[i][j] = 1 + min(solve(s1,s2,i+1,j+1) , 
            min(solve(s1,s2,i+1,j),solve(s1,s2,i,j+1)));
    }

    int minDistance(string word1, string word2) {
        n1 = word1.length();
        n2 = word2.length();
        dp.assign(n1+1, vector<int>(n2+1, -1));
        return solve(word1, word2, 0,0);
    }
};