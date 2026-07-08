class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.length();
        long long mod = 1e9+7;

        vector<long long> prefix(n+1,0);
        for(int i = 0; i < n; i++) {
            prefix[i+1] = prefix[i] + (s[i] - '0');
        }

        vector<int> cntOfNonZero(n+1,0);
        for(int i = 0; i < n; i++) {
            if(s[i] > '0') cntOfNonZero[i+1] = cntOfNonZero[i]+1;
            else cntOfNonZero[i+1] = cntOfNonZero[i];
        }

        vector<long long> X(n+1,0);
        for(int i = 0; i < n; i++) {
            if(s[i] > '0') {
                X[i+1] = (X[i]*10 + (s[i]-'0'))% mod;
            } else {
                X[i+1] = X[i];
            }
        }

        vector<long long> pow(n+1,1);
        for(int i = 1; i <= n; i++) {
            pow[i] = (pow[i-1]*10) % mod;
        }
        vector<int> ans;
        for(auto& query: queries) {
            int l = query[0];
            int r = query[1];
            int numBefore = cntOfNonZero[l];
            int numCnt = cntOfNonZero[r+1];
            long long before = X[l];
            long long after = X[r+1];

            int substrLen = numCnt - numBefore;
            if(substrLen == 0) {ans.push_back(0); continue;}

            long long x = (after - (before*pow[substrLen] % mod) + mod )% mod;     
            long long sum = prefix[r+1] - prefix[l];

            ans.push_back((int)((x*sum)%mod));
        }
        return ans;
    }
};