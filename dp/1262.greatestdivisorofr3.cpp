// DP
class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>> dp(n + 1, vector<int>(3, -1e9));
        dp[n][0] = 0;
        dp[n][1] = -1e9;
        dp[n][2] = -1e9;

        for (int ind = n - 1; ind >= 0; ind--) {
            for (int rem = 0; rem < 3; rem++) {
                int x = nums[ind] % 3;
                int not_take = dp[ind + 1][rem];
                int take = dp[ind + 1][(rem - x + 3) % 3];
                if (take > -1e9) take += nums[ind];

                dp[ind][rem] = max(take, not_take);
            }
        }
        return dp[0][0];
    }
};

// DP only recurrence
class Solution {
public:
    int solve(vector<int>& nums, int ind, int rem, vector<vector<int> >& dp) {
        if (ind == nums.size()) {
            return (rem == 0 ? 0 : INT_MIN);
        }
        if (dp[ind][rem] != -1) return dp[ind][rem];
        int x = nums[ind] % 3;

        int not_take = solve(nums, ind + 1, rem, dp);
        int take = solve(nums, ind + 1, (rem - x + 3) % 3, dp);
        if (take != INT_MIN) take += nums[ind];
        return dp[ind][rem] = max(take, not_take);
    }
    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int> > dp(n, vector<int> (3, -1));
        int ans = solve(nums, 0, 0, dp);
        return max(0, ans);
    }
};



class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int sum = 0;
        vector<int> r1, r2;

        for (int x : nums) {
            sum += x;
            if (x % 3 == 1) r1.push_back(x);
            else if (x % 3 == 2) r2.push_back(x);
        }

        sort(r1.begin(), r1.end());
        sort(r2.begin(), r2.end());

        if (sum % 3 == 0) return sum;
        int ans = 0;

        if (sum % 3 == 1) {
            int remove1 = (r1.size() >= 1 ? r1[0] : INT_MAX);
            int remove2 = (r2.size() >= 2 ? r2[0] + r2[1] : INT_MAX);
            ans = sum - min(remove1, remove2);
        } else {
            int remove1 = (r2.size() >= 1 ? r2[0] : INT_MAX);
            int remove2 = (r1.size() >= 2 ? r1[0] + r1[1] : INT_MAX);
            ans = sum - min(remove1, remove2);
        }

        if(ans < 0){
            return 0;
        }

        return ans;
    }
};