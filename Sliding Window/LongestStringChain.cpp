class Solution {
public:
    static bool comp(const string& str1, const string& str2){
        return str1.size() < str2.size();
    }
    bool checkPrecdence(string& str1, string& str2){
        int i = 0;
        for(int j = 0; j < str2.size(); j++){
            if(str1[i] == str2[j]){
                i++;
            }
        }
        return i == str1.size();
    }
    int solve(int index, vector<string> &words, vector<int>& dp){
        if(dp[index] != -1){
            return dp[index];
        }
        int ans = 0;
        int len = words[index].size();
        for(int i = index+1; i < words.size() && len + 1 >= words[i].size(); i++){
            if(words[i].size() == len + 1 && checkPrecdence(words[index], words[i])){
                ans = max(ans, 1 + solve(i, words, dp));
            }
        }
        return dp[index] = ans;
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), comp);
        vector<int> dp(words.size(), -1);
        int ans = 1;
        for(int i = 0; i < words.size(); i++){
            ans = max(ans, 1 + solve(i, words, dp));
        }
        return ans;
    }
};