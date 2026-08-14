class SegmentTree{
public:
	int n;
	vector<long long> tree;
	SegmentTree(vector<int>& arr){
		n = arr.size();
		tree.assign(4*n,0);
		build(1,0,n-1,arr);
	}

	void build(int node, int l, int r, vector<int>& arr) {
		if(l == r) {
			tree[node] = arr[l];
			return;
		}
		int mid = l + (r-l)/2;
		build(2*node, l, mid, arr);
		build(2*node+1, mid+1, r, arr);
		tree[node] = tree[2*node] + tree[2*node+1];
	}

	void update(int node, int l, int r, int idx, int val) {
		if(l == r) {
			tree[node] = val;
			return;
		}
		int mid = l + (r-l)/2;
		if(idx <= mid) {
			update(2*node, l, mid, idx, val);
		}else {
			update(2*node+1, mid+1, r, idx, val);
		}
		tree[node] = tree[2*node] + tree[2*node+1];
	}

	long long queryRange(int node, int l, int r, int ql, int qr) {
		if(qr < l || r < ql) return 0;
		if(ql <= l && qr >= r) return tree[node];
		int mid = l + (r-l)/2;
		return queryRange(2*node, l, mid, ql, qr) + queryRange(2*node+1, mid+1, r, ql, qr);
	}

	long long query(int ql, int qr) {
		if(qr-ql+1 >= 3) return queryRange(1,0,n-1,ql+1,qr-1);
		return 0;
	}

	void updateIdx(int idx, int val) {
		update(1,0,n-1,idx,val);
	}
};
class Solution {
public:
    vector<int> countOfPeaks(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> peak(n,0);
        for(int i = 1; i < n-1; i++) {
        	if((nums[i] > nums[i-1]) && (nums[i] > nums[i+1])) {
        		peak[i] = 1;
        	}
        }
        SegmentTree st(peak);
        vector<int> ans;
        for(auto q: queries) {
        	int queryType = q[0];
        	if(queryType == 1) {
        		// count peak elements
        		ans.push_back(st.query(q[1],q[2]));
        	}else {
        		int idx = q[1];
        		int val = q[2];
        		nums[idx] = val;
        		for(int i = idx-1; i <= idx+1; i++) {
        			if(i <= 0 || i >= n-1) continue;
        			bool ispeak = (nums[i] > nums[i-1]) && (nums[i] > nums[i+1]);
        			if(peak[i] != ispeak) {
        				peak[i] = ispeak;
        				st.updateIdx(i,ispeak);
        			}
        		}
        	}
        }
        return ans;
    }
};