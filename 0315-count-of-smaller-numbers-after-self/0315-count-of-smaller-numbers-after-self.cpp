class Solution {
public:
    vector<int> ans;
    void merge(int l, int mid, int r, vector<pair<int, int>>& arr) {
        vector<pair<int, int>> temp(r - l + 1);
        int i = l;
        int j = mid + 1;
        int k = 0;
        int right_count = 0;
        while (i <= mid && j <= r) {
            if (arr[i].first <= arr[j].first) {
                temp[k] = arr[i];
                ans[arr[i].second] += right_count;
                i++;
            } else {
                temp[k] = arr[j];
                right_count++;
                j++;
            }
            k++;
        }
        while (i <= mid) {
            temp[k] = arr[i];
            ans[arr[i].second] += right_count;
            i++;
            k++;
        }
        while (j <= r) {
            temp[k] = arr[j];
            j++;
            k++;
        }
        for (int idx = 0; idx < k; idx++) {
            arr[l + idx] = temp[idx];
        }
    }
    void mergeSort(int l, int r, vector<pair<int, int>>& arr) {
        if (l >= r)
            return;
        int mid = l + (r - l) / 2;
        mergeSort(l, mid, arr);
        mergeSort(mid + 1, r, arr);
        merge(l, mid, r, arr);
    }

    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> arr(n);
        for (int i = 0; i < n; i++) {
            arr[i] = {nums[i], i};
        }
        ans.assign(n, 0);
        mergeSort(0, n - 1, arr);
        return ans;
    }
};