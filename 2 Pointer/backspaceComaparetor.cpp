class Solution {
public:
    string solve(string s, stack<char> st){
        for(char ch: s){
            if(ch == '#' && !st.empty()){
                st.pop();
            }else if(ch=='#'){
                continue;
            }else{
                st.push(ch);
            }
        }
        string str = "";
        while(!st.empty()){
            str += st.top();
            st.pop();
        }
        return str;
    }
    bool backspaceCompare(string s, string t) {
        stack<char> st;
        if(solve(s, st) == solve(t, st)){
            return true;
        }
        return false;
    }
};