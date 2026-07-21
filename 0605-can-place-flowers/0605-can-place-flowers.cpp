class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int ans = 0;
        int sz = flowerbed.size();
        for(int i = 0; i < sz; i++) {
            bool left = (i == 0 || flowerbed[i-1] == 0);
            bool right = (i == sz-1 || flowerbed[i+1] == 0);
            if(left && right && flowerbed[i] == 0) {
                flowerbed[i] = 1;
                ans++;
            }
        }
        return (ans >= n);
    }
};