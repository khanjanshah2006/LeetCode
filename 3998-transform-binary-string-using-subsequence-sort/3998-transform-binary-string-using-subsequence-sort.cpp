class Solution {
public:
    vector<bool> transformStr(string s, vector<string>& strs) {
        int n = s.length();
        int c1 = 0;
        vector<int> prefix(n+1,0);
        for(int i = 0; i < n; i++) {
            prefix[i+1] = prefix[i] + ((s[i] == '1') ? 1 : 0);
        }
        c1 = prefix[n];
        vector<bool> ans;
        for(auto& q: strs) {
            int c_1 = 0;
            int c_0 = 0;
            int c_2 = 0;
            for(int i = 0; i < n; i++) {
                if(q[i] == '1') c_1++;
                else if(q[i] == '0') c_0++;
                else c_2++;
            }
            if(c_1 > c1 || c_0 > (n-c1)) {
                ans.push_back(false);
                continue;
            }
            int needOne = c1 - c_1;
            int toconvert = c_2 - needOne;
            int sum = 0;
            bool flag = true;
            for(int i = 0; i < n; i++) {
                int bit;
                if(q[i] == '1') bit = 1;
                else if(q[i] == '0') bit = 0;
                else {
                    if(toconvert > 0) {
                        bit = 0;
                        toconvert--;
                    } else {
                        bit = 1;
                    }
                }
                sum += bit;
                if(sum > prefix[i+1]) {
                    flag = false;
                    break;
                }
            }
            ans.push_back(flag);
        }
        return ans;
    }
};