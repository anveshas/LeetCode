class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int n = costs.size();
        long long totalCost = 0;

        while(k > 0 && !costs.empty()){
            int s1 = 0, e1 = candidates - 1;
            int e2 = n - 1;
            int s2 = e2 - candidates + 1;
            s2 = max(s2, 0);
            e1 = min(e1, n - 1);

            int mini = INT_MAX, index = -1;

            for (int i = s1; i <= e1; i++) {
                if (costs[i] < mini) {
                    mini = costs[i];
                    index = i;
                }
            }

            for (int i = s2; i <= e2; i++) {
                if (costs[i] < mini) {
                    mini = costs[i];
                    index = i;
                }
            }
            totalCost += mini;

            costs.erase(costs.begin() + index);
            n = costs.size();
            k--;
        }
        return totalCost;
    }
};

//optimized furthur using priority queue


class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int n = costs.size();
        long long totalCost = 0;
        priority_queue<int, vector<int>, greater<int>> leftHeap, rightHeap;

        int left = 0, right = n - 1;

        for (int i = 0; i < candidates && left <= right; ++i) {
            leftHeap.push(costs[left++]);
            if (left <= right) {
                rightHeap.push(costs[right--]);
            }
        }

        while (k-- > 0) {
            if (!leftHeap.empty() && (rightHeap.empty() || leftHeap.top() <= rightHeap.top())) {
                totalCost += leftHeap.top();
                leftHeap.pop();
                if (left <= right) {
                    leftHeap.push(costs[left++]);
                }
            } else if (!rightHeap.empty()) {
                totalCost += rightHeap.top();
                rightHeap.pop();
                if (left <= right) {
                    rightHeap.push(costs[right--]);
                }
            }
        }

        return totalCost;
    }
};