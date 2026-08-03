class Solution {
public:
	int n;
	vector<vector<int>> dp;

	int solve(int i, int rem, vector<int>& stones) {
		if(i == n) return 0;
		if(rem == 0) return 0;
		if(dp[i][rem] != -1) return dp[i][rem];
		int skip = solve(i+1,rem, stones);
		int take = 0;
		if(stones[i] <= rem) {
			take = stones[i] + solve(i+1,rem-stones[i],stones);
		}
		return dp[i][rem] = max(take,skip);
	}

    int lastStoneWeightII(vector<int>& stones) {
        n = stones.size();
        int total = accumulate(stones.begin(),stones.end(),0);
        int target = total/2;
        dp.assign(n+1,vector<int>(target+1,-1));
        int s1 = solve(0,target,stones);
        return abs(2*s1 - total);
    }
};