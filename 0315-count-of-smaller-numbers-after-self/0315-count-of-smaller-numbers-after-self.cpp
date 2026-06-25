class Solution {
public:
    vector<int> tree;
    int sum(int node, int s, int e, int l, int r) {
        if(r < s || l > e) {
            return 0;
        }
        if(l<=s && r>= e) {
            return tree[node];
        }
        int mid = s + (e-s)/2;
        int left = sum(2*node, s, mid, l,r);
        int right = sum(2*node+1,mid+1,e,l,r);
        return left + right;
    }
    void update(int node, int s, int e, int i, int x) {
        if(s == e) {
            tree[node] += x;
            return;
        }
        int mid = s + (e-s)/2;
        if(i <= mid) {
            update(2*node, s, mid, i,x);
        }else {
            update(2*node+1, mid+1,e, i,x);
        }
        tree[node] = tree[2*node] + tree[2*node + 1];
    }
    vector<int> countSmaller(vector<int>& nums) {
        tree.assign(4*20001 ,0);
        int n = nums.size();
        vector<int> ans(n);
        for(int i=n-1; i>= 0; i--) {
            ans[i] = sum(1,0,20000,0,nums[i]+9999);
            update(1,0,20000,nums[i]+10000, 1);
        }
        return ans;
    }
};