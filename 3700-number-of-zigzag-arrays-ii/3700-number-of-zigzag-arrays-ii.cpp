class Solution {
public:
    long long mod = 1e9+7;
    vector<vector<long long>> multiply(const vector<vector<long long>>& A,const vector<vector<long long>>& B) {
        int n = A.size();
        vector<vector<long long>> ans(n, vector<long long>(n,0));
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                for(int k=0; k<n; k++) {
                    ans[i][j] = (ans[i][j] + A[i][k]*B[k][j])% mod;
                }
            }
        }
        return ans;
    }

    vector<vector<long long>> MatExp(vector<vector<long long>>& x, long long exp) {
        int n = x.size();
        if(exp == 0) {
            vector<vector<long long>> identity(n,vector<long long>(n,0));
            for(int i=0; i<n; i++) identity[i][i] = 1;
            return identity;
        }
        if(exp == 1) return x;
        vector<vector<long long>> half = MatExp(x, exp/2);
        vector<vector<long long>> result = multiply(half, half);

        if(exp%2 == 1) return multiply(result,x);
        return result;
    }

    int zigZagArrays(int n, int l, int r) {
        if(n == 1) return r-l+1;
        int m = r-l+1;
        int total_states = 2*m;
        vector<vector<long long>> T(total_states, vector<long long>(total_states,0));
        for(int x = 0; x < m; x++) {
            int down = x;
            int up = x+m;
            for(int y=0; y < x; y++) {
                T[y][up] = 1;
            }
            for(int y=x+1; y < m; y++) {
                T[y+m][down] = 1;
            }
        }
        vector<long long> V1(total_states,1);
        vector<vector<long long>> T_pow = MatExp(T, n-1);
        long long ans = 0;
        for(int i=0; i<total_states; i++) {
            long long temp = 0;
            for(int j=0; j < total_states; j++) {
                temp = (temp + T_pow[i][j] * V1[j]) % mod;
            }
            ans = (ans + temp)% mod;
        }
        return ans;
    }

};