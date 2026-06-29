class Solution {
public:
    bool isVowel(char c) {
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return true;
        return false;
    }

    long long countOfSubstrings(string word, int k) {
        int n = word.length();
        int lastOcc = n;
        vector<int> nextCons(n);
        for(int i = n-1; i >= 0; i--) {
            nextCons[i] = lastOcc;
            if(!isVowel(word[i])) lastOcc = i;
        }
        unordered_map <char,int> mp;
        int i = 0; int j = 0;
        int count = 0;
        long long ans = 0;
        while(j < n) {
            char ch = word[j];
            if(isVowel(ch)) mp[ch]++;
            else count++;

            while(count > k) {
                char c = word[i];
                if(isVowel(c)) {
                    mp[c]--;
                    if(mp[c] == 0) mp.erase(c);
                }else {
                    count--;
                }
                i++;
            }

            while(i < n && mp.size() == 5 && count == k) {
                char c = word[i];
                ans += nextCons[j] - j;

                if(isVowel(c)) {
                    mp[c]--;
                    if(mp[c] == 0) mp.erase(c);
                } else count--;
                i++;
            }
            j++;
        }
        return ans;
    }
};