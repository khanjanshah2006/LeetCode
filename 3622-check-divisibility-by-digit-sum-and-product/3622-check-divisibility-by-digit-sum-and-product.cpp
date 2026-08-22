class Solution {
public:
    bool checkDivisibility(int n) {
        int N = n;
        long long product = 1;
        long long sum = 0;
        while(n > 0) {
            int digit = n%10;
            product *= digit;
            sum += digit;
            n /= 10;
        }
        long long check = sum + product;
        return (N % check == 0);
    }
};