class Solution {
public:
    long long sumAndMultiply(int n) {
        long long sum = 0;
        long long x = 0;
        int p = 1;
        while(n > 0) {
            int digit = (n%10);
            if(digit != 0) {
                x += (long long)digit * p;
                sum += digit;
                p = p*10;
            }
            n = n/10;
        }
        return x*sum;
    }
};