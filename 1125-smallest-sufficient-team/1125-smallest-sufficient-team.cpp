class Solution {
public:
    vector<vector<int>> dp;
    int target;
    int n;
    int solve(int i, int mask, vector<int>& bitmasks) {
        if(mask == target) return 0;
        if (i == n) return 61;
        if(dp[i][mask] != -1) return dp[i][mask];
        int nottake = solve(i+1, mask, bitmasks);
        int take = 1 + solve(i+1, mask | bitmasks[i], bitmasks);
        return dp[i][mask] = min(take,nottake);
    }

    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        vector<int> bitmasks;
        n = people.size();
        target = (1 << req_skills.size()) - 1;
        dp.assign(n+1,vector<int>(target+1,-1));
        unordered_map<string,int> mp;
        for(int i=0; i< req_skills.size(); i++) {
            mp[req_skills[i]] = i;
        }
        for(auto skills: people) {
            int mask = 0;
            for(auto skill : skills) {
                if(mp.find(skill) != mp.end()) {
                    mask = mask | (1 << (mp[skill]));
                }
            }
            bitmasks.push_back(mask);
        }
        solve(0,0,bitmasks);
        vector<int> ans;
        int mask = 0;
        for(int i=0 ;i<n && mask != target; i++) {
            if(dp[i][mask] != dp[i+1][mask]) {
                ans.push_back(i);
                mask = mask | bitmasks[i];
            }
        }
        return ans;
    } 
};