class Solution {
public:
	typedef pair<int,int> p;
    vector<int> getOrder(vector<vector<int>>& tasks) {
        priority_queue<p,vector<p>,greater<p>> job_queue;
        priority_queue<p,vector<p>,greater<p>> ready_queue;
        int n = tasks.size();
        for(int i = 0; i < n; i++) {
        	job_queue.push({tasks[i][0],i}); // arrival time , index
        }
        vector<int> ans;
        int completed = 0;
        long long latestEndTime = 0;
        while(completed != n) {
        	while(!job_queue.empty() && job_queue.top().first <= latestEndTime) {
        		int idx = job_queue.top().second;
        		ready_queue.push({tasks[idx][1],idx});
        		job_queue.pop();
        	}

            if(ready_queue.empty()) {
        		int latestArrivalTime = job_queue.top().first;
        		int index;
        		while(!job_queue.empty() && job_queue.top().first == latestArrivalTime) {
        			index = job_queue.top().second;
        			ready_queue.push({tasks[index][1], index});
        			job_queue.pop();
        		}
        		latestEndTime = latestArrivalTime;
        	}
        	

        	ans.push_back(ready_queue.top().second);
        	latestEndTime += ready_queue.top().first;
        	ready_queue.pop();
        	completed++;
        }
        return ans;
    }
};