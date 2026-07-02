class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n1;
        int n2;
        int count1, count2;
        count1 = count2 = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] == n1) {
                count1++;
            } else if (nums[i] == n2) {
                count2++;
            } else if (count1 == 0) {
                n1 = nums[i];
                count1++;
            } else if (count2 == 0) {
                n2 = nums[i];
                count2++;
            } else {
                count1--;
                count2--;
            }
        }
        count1 = count2 = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == n1)
                count1++;
            if (nums[i] == n2)
                count2++;
        }
        vector<int> ans;
        if (count1 > n / 3)
            ans.push_back(n1);
        if (count2 > n / 3)
            ans.push_back(n2);
        return ans;
    }
};