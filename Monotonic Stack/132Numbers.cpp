class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        if(n < 3) return false;
        stack<int> monotonic_stack;
        int third = INT_MIN;
        for(int i = n-1; i >= 0; i--){
            if(nums[i] < third){
                return true;
            }
            while(!monotonic_stack.empty() && monotonic_stack.top() < nums[i]){
                third = monotonic_stack.top();
                monotonic_stack.pop();
            }
            monotonic_stack.push(nums[i]);
        }
        return false;
    }
};