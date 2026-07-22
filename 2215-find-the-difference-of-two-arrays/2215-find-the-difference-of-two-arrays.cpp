class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> st(nums2.begin(), nums2.end());
        vector<int> ans0;
        for(int num: nums1) {
            if(st.find(num) == st.end()) {
                ans0.push_back(num);
                st.insert(num);
            }
        }
        st.clear();
        for(int num: nums1) st.insert(num);
        vector<int> ans1;
        for(int num: nums2) {
            if(st.find(num) == st.end()) {
                ans1.push_back(num);
                st.insert(num);
            }
        }
        return {ans0, ans1};
    }
};