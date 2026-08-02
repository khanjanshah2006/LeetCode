class Solution {
public:
    bool possible(long long x, vector<int>& monsters, vector<long long>& bonus) {
        int n = monsters.size();
        for(int i = 0; i < n; i++) {
            if(x + bonus[i] < monsters[i]) return false;
            x = x - monsters[i];
            if(x < 0) x = 0;
        }
        return true;
    }

    long long minInitialStrength(vector<int>& monsters, vector<vector<int>>& boosts) {
        int n = monsters.size();
        vector<long long> diff(n+1,0);
        for(auto& it: boosts) {
            diff[it[0]] += it[2];
            diff[it[1]+1] -= it[2];
        }
        vector<long long> bonus(n,0);
        bonus[0] = diff[0];
        for(int i = 1; i < n; i++) {
            bonus[i] = bonus[i-1] + diff[i];
        }
        long long l = 0;
        long long h = accumulate(monsters.begin(),monsters.end(),0LL);
        long long ans = h;
        while(l <= h) {
            long long mid = l + (h-l)/2;
            if(possible(mid,monsters,bonus)) {
                ans = mid;
                h = mid-1;
            }else {
                l = mid+1;
            }
        }
        return ans;
    }
};