class Solution {
public:
    vector<int> bit;

    long long sum(int i) {
        long long ans = 0;
        while(i > 0) {
            ans += bit[i];
            i -= (i & -i);
        }
        return ans;
    }
    void update(int i, int val, int n) {
        while(i <= n) {
            bit[i] += val;
            i += (i & -i);
        }
    }

    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> prefix(n+1,0);
        prefix[0] = 0;
        for(int i=0; i<n; i++) {
            if(nums[i] == target) {
                prefix[i+1] = prefix[i] + 1; 
            }else {
                prefix[i+1] = prefix[i] - 1; 
            }
        }
        map<int,int> mp;
        for(auto& num: prefix) mp[num];
        int ctr = 1;
        for(auto& it: mp) {
            it.second = ctr;
            ctr++;
        }
        for(auto& num: prefix) num = mp[num];
        bit.assign(mp.size()+1,0);
        update(prefix[0],1,mp.size());
        long long ans = 0;
        for(int i=1; i<=n ;i++) {
            ans += sum(prefix[i]-1);
            update(prefix[i],1,mp.size());
        }
        return ans;
    }
};