class Solution {
public:

    long long nCr(int n, int r, long long limit) {
        if(r < 0 || r > n) return 0;
        if(r == 0|| r == n) return 1;
        r = min(r, n-r);
        long long ans = 1;
        for(int i = 1; i <= r; i++) {
            ans = ans * (n-i+1) / i;
            if(ans >= limit) return limit;
        }
        return ans;
    }

    long long possibleways(vector<int>& freq, int len, long long limit) {
        long long ways = 1;
        int curLen = len;
        for(int i = 0; i < 26; i++) {
            if(freq[i] <= 0) continue;
            ways *= nCr(curLen, freq[i], limit);
            if(ways >= limit) return limit;
            curLen -= freq[i];
        }
        return ways;
    }
    string kthPermutation(string s, int k) {
        int n = s.length();
        vector<int> freq(26,0);
        for(char ch: s) {
            freq[ch-'a']++;
        }
        k--;
        string result = "";
        for(int pos = 0; pos < n; pos++) {
            bool placed = false;
            for(int c = 0; c < 26; c++) {
                if(freq[c] == 0) continue;
                freq[c]--;
                long long ways = possibleways(freq,n-1-pos, k+1);
                if(k < ways) {
                    result.push_back(c + 'a');
                    placed = true;
                    break;
                }else {
                    k -= ways;
                    freq[c]++;
                }
            }
            if(!placed) return "";
        }
        return result;
    }
    string smallestPalindrome(string s, int k) {
        int n = s.length();
        string half = s.substr(0, n / 2);
        string mid = (n % 2 == 1) ? string(1, s[n / 2]) : "";
        vector<int> freq(26, 0);
        for (char c : half) freq[c - 'a']++;
        if (k > possibleways(freq, half.length(), k)) return "";
        string leftHalf = kthPermutation(half, k);
        string rightHalf = leftHalf;
        reverse(rightHalf.begin(), rightHalf.end());
        return leftHalf + mid + rightHalf;
    }
};