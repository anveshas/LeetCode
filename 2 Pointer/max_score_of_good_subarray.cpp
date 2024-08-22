class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        int score = nums[k], mini = nums[k];
        int left = k, right = k;
        while(left > 0 || right < n-1){
            if (left == 0 || (right < nums.size() - 1 && nums[right + 1] > nums[left - 1])) {
                right++;
            } else {
                left--;
            }
            mini = min(mini, min(nums[left], nums[right]));
            score = max(score, mini * (right - left + 1));
        }
        return score;
    }
};