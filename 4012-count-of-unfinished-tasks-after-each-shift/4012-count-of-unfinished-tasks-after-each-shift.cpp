class Solution {
public:
    vector<int> countTasks(vector<int>& tasks, vector<int>& shifts) {
        int n = tasks.size();
        vector<long long> pre(n);
        pre[0] = tasks[0];
        for(int i = 1; i < n; i++) {
            pre[i] = pre[i-1] + tasks[i];
        }
        long long shiftSum = 0;
        vector<int> ans;
        int N = shifts.size();
        for(int i = 0; i < N; i++) {
            shiftSum += shifts[i];
            int idx = upper_bound(pre.begin(),pre.end(),shiftSum) - pre.begin();
            if(idx == n) {
                ans.push_back(0);
                shiftSum = 0;
            }else {
                ans.push_back(n-idx);
            }
        }
        return ans;
    }
};