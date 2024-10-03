class Solution {
public:
    string decodeAtIndex(string s, int k) {
        long long size = 0;
        for (char c : s) {
            if (isdigit(c)) {
                size *= (c - '0');
            } else {
                size++;
            }
        }
        for (int i = s.size() - 1; i >= 0; --i) {
            k %= size;
            if (k == 0 && isalpha(s[i])) {
                return string(1, s[i]);
            }

            if (isdigit(s[i])) {
                size /= (s[i] - '0');
            } else {
                size--;
            }
        }
        return "";
    }
};


// memory exceed
class Solution {
public:
    string decodeAtIndex(string s, int k) {
        int n = s.size();
        string str = "", temp = "";
        for(int i = 0; i < n; i++){
            while(i < n && isalpha(s[i])){
                temp += s[i];
                str += s[i];
                i++;
            }
            if(i < n && isdigit(s[i])){
                int num = s[i] - '0';
                num = num - 1;
                while(num--){
                    str += temp;
                }
                temp = str;
            }
            // else {
            //     str += temp;
            // }
        }
        for(char ch: str){
            cout<< ch << " ";
        }
        if(str.size() >= k){
            return string(1, str.at(k - 1));
        }
        return "";
    }
};