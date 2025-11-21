class Solution {
public:
    string decodeString(string s) {
        stack<string> st;
        string ans = "", curr = "";
        string num = "";

        for(char ch : s){
            if(isdigit(ch)){
                num += ch;
                continue;
            }
            
            if(ch == '['){
                st.push(curr);
                st.push(num);
                curr = "";
                num = "";
                continue;
            }
            if(ch == ']'){
                string number = st.top(); st.pop();
                string prev = st.top(); st.pop();

                int k = stoi(number);
                string temp = "";
                while(k--) temp += curr;

                curr = prev + temp;
                continue;
            }
            curr += ch;
        }
        return curr;
    }
};