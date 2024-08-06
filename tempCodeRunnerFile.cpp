#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int l = 0, r = n-1;
        int left_max = INT_MIN, right_max = INT_MIN;
        int ans = 0;
        while(l < r){
            left_max = max(left_max, height[l]);
            right_max = max(right_max, height[r]);
            if(left_max < right_max){
                ans += left_max - height[l];
                l++; 
            }
            else{
                ans += right_max - height[r];
                r--;
            }
        }
        return ans;
    }
};

int main() {
    Solution obj1;
    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << "Trapped water: " << obj1.trap(height) << endl;
    return 0;
}