#include<bits/stdc++.h>
using namespace std;
class FenwickTree {
    int n;
    vector<int> tree;
public:
    FenwickTree(int n): n(n), tree(n+1,0){}
    void update(int i, int val) {
        for(; i <= n; i += i&(-i)) {
            tree[i] += val;
        }
    }

    int query(int i) {
        int ans = 0;
        for(; i > 0 ; i -= i&(-i)) {
            ans += tree[i];
        }
        return ans;
    }

    int rangeSum(int l, int r) {
        return query(r)-query(l-1);
    }
};

class Solution {
public:
	vector<int> compressed(vector<long long>& arr) {
	    int n = arr.size();
	    map<long long,int> mp;
	    for(long long val: arr) {
	        mp[val] = 0;
	    }
	    int rank = 1;
	    for(auto& pair: mp) {
	        pair.second = rank++;
	    }
	    vector<int> ans(n);
	    for(int i = 0; i < n; i++) {
	        ans[i] = mp[arr[i]];
	    }
	    return ans;
	}
	long long countInversions(vector<long long>& arr) {
	    int n = arr.size();
	    if(n <= 1) return 0;
	    long long ans = 0;
	    vector<int> nums = compressed(arr);
	    FenwickTree bit(n);
	    for(int i = 0; i < n; i++) {
	        int less = bit.query(nums[i]-1);
	        int greater = i - less;
	        ans += greater;
	        bit.update(nums[i],1);
	    }
	    return ans;
	}

    long long countRatioSubarrays(vector<int>& nums, int a, int b) {
  		int n = nums.size();
  		for(int i = 0; i < n; i++) {
  			if(nums[i]%2 == 0) nums[i] = b;
  			else nums[i] = -a;
  		}  
  		vector<long long> pre(n+1);
  		pre[0] = 0;
  		for(int i = 0; i < n; i++) {
  			pre[i+1] = pre[i] + nums[i];
  		}
  		return countInversions(pre);
    }
};