class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        set<int> st;
        for (int i = 0; i < n; i++) {
            st.insert(nums[i]);
        }
        vector<int> arr;
        for (auto& it : st)
            arr.push_back(it);

        int ans = INT_MAX;
        int sz = arr.size();
        for (int i = 0; i < sz; i++) {
            auto it = upper_bound(arr.begin(), arr.end(), arr[i] + n - 1) -
                      arr.begin();
            int num_present = it - i;
            int req = n - num_present;
            ans = min(ans, req);
        }
        return ans;
    }
};