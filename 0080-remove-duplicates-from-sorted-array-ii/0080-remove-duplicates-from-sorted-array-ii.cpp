class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int index = 0;
        int i = 0;
        int n = nums.size();
        while(i < n) {
            int dup = nums[i];
            nums[index] = dup;
            if(i < n-1 && nums[i+1] == dup) {
                nums[index+1] = dup;
                index++;
            }
            while(i < n && nums[i] == dup) {
                i++;
            }
            index++;
        }
        return index;
    }
};