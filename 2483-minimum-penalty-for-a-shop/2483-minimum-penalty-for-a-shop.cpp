class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.length();
        vector<int> prefix(n+1,0);
        int count = 0;
        for(int i = 0; i < n; i++) {
            count += (customers[i] == 'N') ? 1 : 0;
            prefix[i+1] = count;
        }
        count = 0;
        vector<int> suffix(n+1);
        for(int i = n-1; i >= 0; i--) {
            count += (customers[i] == 'Y') ? 1 : 0;
            suffix[i] = count;
        }
        int ans = INT_MAX;
        int hour = 0;
        for(int i=0; i<=n; i++) {
            if(prefix[i] + suffix[i] < ans) {
                ans = prefix[i] + suffix[i];
                hour = i;
            }
        }
        return hour;
    }
};