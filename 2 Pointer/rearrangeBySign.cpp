class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n);
        
        int pos=0,neg=1,curr=0;
        while(curr<n){
            if(nums[curr]>0){
                ans[pos]=nums[curr];
                pos=pos+2;
                curr++;
            }
            else{
                ans[neg]=nums[curr];
                neg+=2;
                curr++;
            }
            
        }

        return ans;
    }
};


// using deque

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        deque<int> n;
        deque<int> p;
        for(int i=0;i<nums.size();i++){
            if(nums[i] <0) n.push_back(nums[i]);
            else p.push_back(nums[i]);
        }
        for(int i=0;i<nums.size();i++){
            if(i%2 ==0){
                nums[i]=p.front();
                p.pop_front();
            }
            else{
                nums[i]=n.front();
                n.pop_front();
            }
        }
        return nums;
    }
};


// bad code, but has O(1) space

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        int cnt_pos = nums[0] > 0;
        for (int i = 1; i < n; ++i) {
            int num = nums[i];
            int is_pos = num > 0;
            int target_idx = is_pos ? cnt_pos * 2 : 1 + (i - cnt_pos) * 2;
            for (int j = i; j > target_idx; --j) {
                nums[j] = nums[j - 1];
            }
            nums[min(target_idx, i)] = num;
            cnt_pos += is_pos;
        }
        return nums;
    }
};