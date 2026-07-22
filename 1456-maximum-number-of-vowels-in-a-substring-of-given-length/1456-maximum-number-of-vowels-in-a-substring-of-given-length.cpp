class Solution {
public:
    bool isVowel(char c) {
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return true;
        return false;
    }
    int maxVowels(string s, int k) {
        int n = s.length();
        vector<int> prefix(n,0);
        prefix[0] = isVowel(s[0]) ? 1 : 0;
        for(int i = 1; i < n; i++) {
            prefix[i] = prefix[i-1] + isVowel(s[i]);
        }
        int ans = prefix[k-1];
        for(int i = 1; i <= n-k; i++) {
            int sum = prefix[i+k-1] - prefix[i-1];
            ans = max(ans,sum);
        }
        return ans;
    }
};