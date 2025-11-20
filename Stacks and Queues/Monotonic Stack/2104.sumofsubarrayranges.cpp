// TC: O(N) SC: O(N)
class Solution {
public:
    long long subArrayRanges(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int> prevgreater(n), nextgreater(n);
        vector<int> prevsmaller(n), nextsmaller(n);
        stack<int>st;

        // PSE
        for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.top()]>=nums[i]) st.pop();
            prevsmaller[i]=st.empty()?-1:st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();

        // NSE
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()]>nums[i]) st.pop();
            nextsmaller[i]=st.empty()?n:st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();

        // PGE
        for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.top()]<=nums[i]) st.pop();
            prevgreater[i] = st.empty()?-1 :st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();

        // NGE
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()]<nums[i]) st.pop();
            nextgreater[i]=st.empty()?n:st.top();
            st.push(i);
        }

        long long res=0;
        for(int i=0;i<n;i++){
            long long maxcount= (long long)(i-prevgreater[i])*(nextgreater[i]-i);
            long long mincount= (long long)(i-prevsmaller[i])*(nextsmaller[i]-i);
            res+=(maxcount-mincount)*nums[i];
        }
        return res;
    }
};