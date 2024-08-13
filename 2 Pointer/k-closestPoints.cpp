class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        int left = 0, right = n - 1;

        while (right - left >= k) {
            if (abs(arr[left] - x) > abs(arr[right] - x)) {
                left++;
            } else {
                right--;
            }
        }

        vector<int> result;
        for(int i = left; i < left + k; i++){
            result.push_back(arr[i]);
        }
        return result;
    }
};