class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int p1 = nums[nums[0]], p2 = nums[nums[nums[0]]];
        int slow = p1, fast = p2;
        while(slow != fast){
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        fast = nums[0];
        while(slow != fast){
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};