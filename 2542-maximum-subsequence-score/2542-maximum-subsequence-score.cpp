class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums2.size();
        vector<pair<int, int>> arr(n);
        for (int i = 0; i < n; i++) {
            arr[i] = {nums2[i], nums1[i]};
        }
        sort(arr.begin(), arr.end(),
             [](const pair<int, int>& a, const pair<int, int>& b) {
                 return a.first > b.first;
             });
        priority_queue<int,vector<int>, greater<int>> pq;
        long long ans = 0;
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            sum += arr[i].second;
            pq.push(arr[i].second);
            if(pq.size() > k) {
                int top = pq.top();
                sum -= top;
                pq.pop();
            }
            if(pq.size() == k) {
                ans = max(ans, sum*arr[i].first);
            }
        }
        return ans;
    }
};