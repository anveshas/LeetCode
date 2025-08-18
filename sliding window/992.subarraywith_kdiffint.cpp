class Solution {
public:
    int solve(vector<int>& nums, int k){
        int n = nums.size();
        int total = 0;
        int left = 0, right = 0;
        unordered_map<int,int> freq;
        for(int right = 0; right < n; right++) {
            if(freq[nums[right]] == 0) k--;
            freq[nums[right]]++;
            while(k < 0) {
                freq[nums[left]]--;
                if(freq[nums[left]] == 0) k++;
                left++;
            }
            total += (right - left + 1);
        }
        return total;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return solve(nums, k) - solve(nums, k-1);
    }
};