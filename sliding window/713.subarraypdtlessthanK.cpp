// TC: O(N) SC: O(1)
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) return 0;

        long long product = 1;
        int left = 0, count = 0;

        for (int right = 0; right < nums.size(); right++) {
            product *= nums[right];
            while (product >= k){
                product /= nums[left];
                left++;
            }

            count += right - left + 1;
        }
        return count;
    }
};

// TC: O(N^2) SC: O(1)
class Solution {
public:
    int solve(vector<int>& nums, int k, int ind){
        long long p = 1; 
        int count = 0;
        for(int i = ind; i < nums.size(); i++){
            p *= nums[i];
            if(p >= k) break;
            count++;
        }
        return count;
    }

    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k <= 1) return 0;
        int count = 0;
        for(int i = 0; i < nums.size(); i++){
            count += solve(nums, k, i);
        }
        return count;
    }
};