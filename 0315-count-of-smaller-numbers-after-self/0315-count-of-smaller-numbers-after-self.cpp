class Solution {
public:
    vector<int> bit;
    int sum(int i) {
        int ans = 0;
        while(i > 0) {
            ans += bit[i];
            i -= (i & -i);
        }
        return ans;
    }
    void update(int i, int x) {
        while(i < 20002) {
            bit[i] += x;
            i += (i & -i);
        }
    }
    vector<int> countSmaller(vector<int>& nums) {
        bit.assign(20002,0);
        int n = nums.size();
        vector<int> ans(n);
        for(int i=n-1; i>= 0; i--) {
            ans[i] = sum(nums[i]+10000);
            update(nums[i]+10001, 1);
        }
        return ans;
    }
};