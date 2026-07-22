class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        vector<int> temp;
        int n  = nums.size();
        for(int i = 0; i < n; i++) {
            auto it = lower_bound(temp.begin(),temp.end(),nums[i]) - temp.begin();
            if(it == temp.size()) {
                temp.push_back(nums[i]);
            } else {
                temp[it] = nums[i];
            }
        }
        if(temp.size() >= 3) return true;
        return false;
    }
};