class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 1;
        if(n == 2) return 2;
        int pos = 0;
        while(n > 0) {
            n = n >> 1;
            pos++;
        }
        return 1 << pos;
    }
};