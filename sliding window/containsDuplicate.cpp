//using unordered map ----> best solution
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            if (mp.find(nums[i]) != mp.end() && i - mp[nums[i]] <= k) {
                return true;
            }
            mp[nums[i]] = i;
        }
        return false;
    }
};




//using set
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) 
    {
       if(k==0) return false;
       int i=0,j=0;
       int n = nums.size();
       unordered_set<int> st;
       while(j<n)
       {
         if(j-i>k) {
            st.erase(nums[i]);
            i++;
         }

         if(st.find(nums[j])!=st.end()) return true;
         st.insert(nums[j]);
         j++;
       }
       return false; 
    }
};



//using sliding window   ----> giving TLE(on last test case)
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        if(k==0){
            return false;
        }
        int i = 0, j = 1;
        while(j < n){
            if(abs(i-j) <= k){
                if(nums[i] == nums[j]){
                    return true;
                }
                j++;
                if(j >= n){
                    i++;
                    j = i+1;
                }
            }
            else{
                i++;
                j = i + 1;
            }
        }
        return false;
    }
};