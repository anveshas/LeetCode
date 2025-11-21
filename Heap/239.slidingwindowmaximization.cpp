// TC: O(N) SC: O(K)
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> dq;
        for(int i = 0; i < nums.size(); i++){
            if(!dq.empty() && dq.front() == i - k){
                dq.pop_front();
            }
            while(!dq.empty() && nums[dq.back()] < nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);
            if(i >= k - 1){
                ans.push_back(nums[dq.front()]);
            }
        }
        return ans;
    }
};

// TC: O(N logK) SC: O(K)
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        priority_queue<pair<int, int>> pq;
        for(int i = 0; i < k; i++){
            pq.push({nums[i], i});
        }
        ans.push_back(pq.top().first);
        for(int i = k; i < nums.size(); i++){
            pq.push({nums[i], i});
            while(pq.top().second <= i - k){
                pq.pop();
            }
            ans.push_back(pq.top().first);
        }
        return ans;
    }
};