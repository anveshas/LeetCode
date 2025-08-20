class Solution {
    public:
        long long zeroFilledSubarray(vector<int>& nums) {
            int n = nums.size();
            long long cnt = 0;
            int left = 0;
    
            while (left < n) {
                if (nums[left] != 0) {
                    left++;
                    continue;
                }
    
                int right = left;
                long long streak = 0;
                while (right < n && nums[right] == 0) {
                    streak++;
                    cnt += streak;
                    right++;
                }
                left = right;
            }
            return cnt;
        }
    };