class Solution {
public:
    typedef long long ll;
    int minAdjacentSwaps(vector<int>& arr, int a, int b) {
        int n = arr.size();
        ll mod = 1e9+7;
        for(int i = 0; i < n; i++) {
            if(arr[i] < a) arr[i] = 0;
            else if (arr[i] > b) arr[i] = 2;
            else arr[i] = 1;
        }
        ll ans = 0;
        vector<int> freq(3,0);
        freq[arr[0]]++;
        for(int i = 1; i < n; i++) {
            for(int j = arr[i]+1; j < 3; j++) {
                ans  = (ans + freq[j]) % mod;
            }
            freq[arr[i]]++;
        }
        return ans % mod;
    }
};