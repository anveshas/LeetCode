class Solution {
    public:
        int minOperations(vector<int>& nums, int x) {
            int n = nums.size();
            int total = accumulate(nums.begin(), nums.end(), 0);
            int target = total - x;
    
            if (target < 0) return -1;
            if (target == 0) return n;
    
            int sum = 0, left = 0, max_len = -1;
            for (int right = 0; right < n; right++) {
                sum += nums[right];
                while(sum > target && left <= right){
                    sum -= nums[left];
                    left++;
                }
    
                if(sum == target){
                    max_len = max(max_len, right - left + 1);
                }
            }
    
            if(max_len == -1){
                return -1;
            }
            return n - max_len;
        }
    };