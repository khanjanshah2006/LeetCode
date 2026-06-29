class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if(n == 0) return true;
        int len = flowerbed.size();
        for(int i=0; i< len; i++) {
            if(flowerbed[i] == 1) continue;
            bool left = true;
            bool right = true;
            if(i >= 1 && flowerbed[i-1] == 1) left = false;
            if(i < len-1 && flowerbed[i+1] == 1) right = false;
            if(left && right) {
                n--;
                flowerbed[i] = 1;
            }
            if(n == 0) return true;
        }
        return false;
    }
};