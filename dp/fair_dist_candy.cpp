class Solution {
public:
    int n;
    int ans = 1e9;
    void solve(vector<int>& cookies, int ind, int k, vector<int>& rec){
        if(ind >= n){
            int ans1 = *max_element(begin(rec), end(rec));
            ans = min(ans, ans1);
            return;
        }
        
        for(int i = 0; i < k; i++){
            rec[i] += cookies[ind];
            solve(cookies, ind+1, k, rec);
            rec[i] -= cookies[ind];
        }
    }
    int distributeCookies(vector<int>& cookies, int k) {
        n = cookies.size();
        vector<int> rec(k);
        solve(cookies, 0, k, rec);
        return ans;
    }
};