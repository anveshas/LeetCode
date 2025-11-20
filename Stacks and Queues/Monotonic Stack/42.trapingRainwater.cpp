// TC: O(N) SC:O(1)
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int l_max = 0, r_max = 0, total = 0;
        int l = 0, r = n - 1;
        while(l < r){
            if(height[l] <= height[r]){
                if(l_max > height[l]){
                    total += l_max - height[l];
                }
                else{
                    l_max = height[l];
                }
                l++;
            }
            else{
                if(r_max > height[r]){
                    total += r_max - height[r];
                }
                else{
                    r_max = height[r];
                }
                r--;
            }
        }
        return total;
    }
};


// TC: O(3N) SC: O(2N)

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> prefix(n, 0), suffix(n, 0);
        prefix[0] = height[0];
        suffix[n-1]= height[n-1];
        for(int i = 1; i < n; i++){
            prefix[i] = max(prefix[i-1], height[i]);
        }
        for(int i = n-2; i >= 0; i--){
            suffix[i] = max(suffix[i+1], height[i]);
        }
        int max_water = 0;
        for(int i = 1; i < n-1; i++){
            max_water += min(suffix[i], prefix[i]) - height[i];
        }
        return max_water;
    }
};