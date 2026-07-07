class Solution {
public:
    int n;
    vector<int> dp;
    unordered_set<string> st;
    int solve(int i, string& s) {
        if(i == n) return 0;
        if(dp[i] != -1) return dp[i];
        int ans = 1 + solve(i+1,s);
        for(int l = 1; l <= n-i; l++) {
            string temp = s.substr(i,l);
            if(st.find(temp) != st.end()) {
                ans = min(ans, solve(i+l,s));
            }
        }
        return dp[i] = ans;
    }


    int minExtraChar(string s, vector<string>& dictionary) {
        n = s.length();
        dp.assign(n+1,-1);
        for(auto& s: dictionary) {
            st.insert(s);
        }
        return solve(0,s);
    }
};