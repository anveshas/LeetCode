#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        for(int j = 0; j < n; j++){
            if(nums[j] != 0){
                swap(nums[i], nums[j]);
                i++;
            }
        }
    }
};
int main(){
    vector<int> nums = {12, 4, 2, 0, 5, 3, 0};
    moveZeros(nums);
    // cout << 
    return 0;
}