class Solution {
public:
    bool check(int n) {
        bool flag = false;
        while(n > 0) {
            int digit = n%10;
            if(digit == 3 || digit == 4 || digit == 7) return false;
            if(digit == 2 || digit == 5 || digit == 6 || digit == 9) {
                flag = true;
            }
            n = n/10;
        }
        return flag;
    }
    int rotatedDigits(int n) {
        int ans = 0;
        for(int i = 1; i <= n; i++) {
            if(check(i)) ans++;
        }
        return ans;
    }
};