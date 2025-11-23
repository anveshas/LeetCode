// Using Stacks
class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.size();
        stack<char> st;
        for(char ch: s){
            if (ch != ')') {
                st.push(ch);
            }else{
                string temp = "";
                while(!st.empty() && st.top() != '('){
                    temp += st.top();
                    st.pop();
                }
                st.pop();
                for (char c : temp) {
                    st.push(c);
                }
            }
        }
        string ans;
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};