class Solution {
public:
    int maximumLength(vector<int>& nums) {
        map<long long, int> mp;
        for (auto& num : nums)
            mp[num]++;
        int ans = 0;
        int c1 = mp[1];
        if (c1 % 2 == 0)
            ans = max(ans, c1 - 1);
        else
            ans = max(ans, c1);
        mp.erase(1);
        for (auto& pr : mp) {
            long long n = pr.first;
            int f = pr.second;
            // mp.erase(n);
            if (f == 1) {
                ans = max(ans, 1);
                continue;
            }
            int temp = 2;
            n = n*n;
            while (mp.find(n) != mp.end()) {
                int freq = mp[n];
                if (freq == 1) {
                    temp++;
                    break;
                } else {
                    temp += 2;
                }
                // mp.erase(n);
                n = n * n;
            }
            if (temp % 2 == 0)
                temp--;
            ans = max(ans, temp);
        }
        return ans;
    }
};