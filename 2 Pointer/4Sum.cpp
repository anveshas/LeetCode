class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;

        for(int i=0; i < n-3; i++){
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            for(int j = i+1; j < n-2; j++){
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;

                int k = j+1;
                int l = n-1;

                long long sum_of_two = (long long)nums[i] + (long long)nums[j];
                long long remaining = (long long)target - (long long)sum_of_two;

                while(k < l){
                    long long sum_kl = (long long)nums[k] + (long long)nums[l];
                    
                    if(sum_kl == remaining){
                        ans.push_back({nums[i], nums[j], nums[k], nums[l]});
                        while (k < l && nums[k] == nums[k + 1]) k++;
                        while (k < l && nums[l] == nums[l - 1]) l--;
                        k++;
                        l--;
                    }
                    else if(sum_kl < remaining){
                        k++;
                    }
                    else{
                        l--;
                    }
                }
            }
        }
        return ans;
    }
};