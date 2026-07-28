class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int total = accumulate(gas.begin(),gas.end(),0);
        int spend = accumulate(cost.begin(),cost.end(),0);
        if(spend > total) return -1;
        int totalgas = 0;
        int totalspend = 0;
        int ans = 0;
        for(int i = 0; i < n; i++) {
            totalgas += gas[i] - cost[i];
            if(totalgas < 0) {
                totalgas = 0;
                ans = i+1;
            } 
        }
        return ans;
    }
};