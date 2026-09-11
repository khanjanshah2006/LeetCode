class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        vector<int> digit(10,0);
        for(int i: digits) {
            digit[i]++;
        }
        int ans = 0;
        for(int i = 100; i <= 998; i+=2) {
            unordered_map<int,int> mp;
            int num = i;
            mp[num%10]++; num/=10;
            mp[num%10]++; num/=10;
            mp[num%10]++;
            bool flag = true;
            for(auto& it: mp) {
                int n = it.first;
                int f = it.second;
                if(digit[n] < f) {
                    flag = false;
                    break;
                }
            }
            if(flag) ans++;
        }
        return ans;
    }
};