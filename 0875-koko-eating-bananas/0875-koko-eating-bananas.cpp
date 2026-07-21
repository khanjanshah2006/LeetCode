class Solution {
public:
    bool isPossible(vector<int>& piles, int h, int k) {
        long long hours = 0;
        for(int num : piles) {
            hours += (num+k-1)/k;
        }
        if(hours <= h) return true;
        return false;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());
        int ans = r;
        while(l <= r) {
            int mid = l + (r-l)/2;
            if(isPossible(piles,h,mid)) {
                ans = mid;
                r = mid-1;
            }else {
                l = mid+1;
            }
        }
        return ans;
    }
};