class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int l = 0, r = n-1;
        int max_water = INT_MIN;
        while(l < r){
            int window_size = r - l;
            int water = 0;
            if(height[l] < height[r]){
                water = height[l] * window_size;
                l++;
            }
            else{
                water = height[r] * window_size;
                r--;
            }
            max_water = max(max_water, water);
        }
        return max_water;
    }
};