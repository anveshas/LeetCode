class Solution {
public:
    string reverseWords(string s) {
        int i = 0;
        int n = s.size();
        string ans = "";
        stack<char> st;
        while(i < n){
            if(s[i] == ' '){
                string str = "";
                while(!st.empty()){   
                    str += st.top();
                    st.pop();
                }
                ans += str;
                ans += " ";
            }
            else{
                st.push(s[i]);
            }
            i++;
        }
        while(!st.empty()){   
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};