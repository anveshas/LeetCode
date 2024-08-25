class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if (k < 0) return 0;
        
        unordered_map<int, int> mp;
        int cnt = 0;
        
        for (int num : nums) {
            mp[num]++;
        }
        
        for (const auto& [num, count] : mp) {
            if (k == 0) {
                if (count > 1) {
                    cnt++;
                }
            } 
            else {
                if (mp.find(num + k) != mp.end()) {
                    cnt++;
                }
            }
        }
        
        return cnt;
    }
};