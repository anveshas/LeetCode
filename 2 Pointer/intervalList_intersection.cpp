class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int i = 0, j = 0;
        vector<vector<int>> result;
        while(i < firstList.size() && j < secondList.size()){
            int s1 = firstList[i][0], e1 = firstList[i][1];
            int s2 = secondList[j][0], e2 = secondList[j][1];

            if (e1 >= s2 && e2 >= s1) {
                int start = max(s1, s2);
                int end = min(e1, e2);
                result.push_back({start, end});
            }

            if(e1 < e2){
                i++;
            }
            else{
                j++;
            }
        }
        return result;
    }
};