class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        int n =nums.size();
        int cnt = 0;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n - 2; i++){
            int j = i + 1, k = n - 1;
            while(j < k){
                int sum = nums[i] + nums[j] + nums[k];
                if(sum < target) {
                    cnt += (k - j);
                    j++;
                }
                else{
                    k--;
                }
            }
        }
        return cnt;
    }
};