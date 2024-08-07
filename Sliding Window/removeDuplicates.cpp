class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        int l = 1, r = 1;
        while(l <= r && r < n){
            if (nums[r] != nums[r - 1]) {
                nums[l] = nums[r];
                l++;
            }
            r++;
        }
        return l;
    }
};