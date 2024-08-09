class Solution {
public:
    int compress(vector<char>& chars) {
        int i = 0;
        int n = chars.size();

        string ans = "";
        while (i < n) {
            char ch = chars[i];
            int cnt = 0;
            while (i < n && chars[i] == ch) {
                cnt++;
                i++;
            }

            if (cnt > 1) {
                ans += to_string(cnt);
            }
        }
        chars.clear();
        for (char ch : ans) {
            chars.push_back(ch);
        }

        return ans.size();
    }
};