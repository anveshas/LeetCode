class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string result = "";
        int i = 0 ;
        int j = 0 ;
        while(i<word1.length() && j<word2.length()){
            result.push_back(word1[i]);
            result.push_back(word2[j]);
            i++;j++;
        }



        for(;i < word1.length();i++){
            result.push_back(word1[i]);
        }
        for(;j < word2.length();j++){
            result.push_back(word2[j]);
        }

        return result;
    }
};