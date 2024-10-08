class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = n-1;
        while(i < j){
            if(nums[i] & 1 && !(nums[j] & 1)){
                swap(nums[i], nums[j]);
            }
            if(nums[j] % 2 == 1){
                j--;
            }
            if (nums[i] % 2 == 0) {
                i++; 
            }
        }
        return nums;
    }
};