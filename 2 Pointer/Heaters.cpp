class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(heaters.begin(), heaters.end());
        int n = houses.size();
        int radius = 0;
        for(int house: houses){
            auto it = lower_bound(heaters.begin(), heaters.end(), house);
            int dist1 = (it == heaters.end()) ? INT_MAX : *it - house;
            int dist2 = (it == heaters.begin()) ? INT_MAX : house - *(--it);
            radius = max(radius, min(dist1, dist2));
        }
        return radius;
    }
};


//optimized

class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(heaters.begin(), heaters.end());
        int n = houses.size();
        int radius = 0;
        for(int house: houses){
            auto it = lower_bound(heaters.begin(), heaters.end(), house);
            int dist1 = (it == heaters.end()) ? INT_MAX : *it - house;
            int dist2 = (it == heaters.begin()) ? INT_MAX : house - *(--it);
            radius = max(radius, min(dist1, dist2));
        }
        return radius;
    }
};


//binary search

class Solution {
public:
    bool isValidRadius(int radius,vector<int>houses,vector<int>heaters){
        int i=0;
        int j=0;
        while(i<houses.size() && j<heaters.size()){
            if(abs(heaters[j]-houses[i])<=radius) i++;
            else j++;
        }
        return i==houses.size();
    }
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int left=0;
        int right=1*1e9;
        sort(houses.begin(),houses.end());
        sort(heaters.begin(),heaters.end());
        int radius=0;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(isValidRadius(mid,houses,heaters)){
                radius=mid;
                right=mid-1;
            }else{
                left=mid+1;
            }
        }
        return radius;
    }
};