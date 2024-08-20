// TC - O(n)
// sc - O(n)
class Solution {
public:
    string reverseWords(string s) {
        string str = "";
        stack<string> st;
        int n = s.size();
        for(int i = 0; i < n; i++){
            if(s[i] == ' '){
                // st.push(str);
                // str = "";
                if (!str.empty()) {
                    st.push(str);
                    str = "";
                }
            }
            else{
                str += s[i];
            }
        }
        if (!str.empty()) {
            st.push(str);
        }
        string result = "";
        while (!st.empty()) {
            result += st.top();
            st.pop();
            if (!st.empty()) {
                result += " ";
            }
        }

        return result;
    }
};

// TC - O(n)
// SC - O(1)
class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        int i = 0, l = 0, r = 0;
        int n = s.size();
        while(i < n){
            while(i < n && s[i] == ' '){
                i++;
            }
            while(i < n && s[i] != ' '){
                s[r++] = s[i++];
            }
            if(l < r){
                reverse(s.begin() + l, s.begin() + r);
                s[r++] = ' ';
                l = r;
            }
            i++;
        }
        if(r > 0){
            s.resize(r - 1);
        }
        return s;
    }
};