class Solution {
    public:
        double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
            auto gain = [](int pass, int total) {
                return (double)(pass + 1) / (total + 1) - (double)pass / total;
            };
            
            priority_queue<tuple<double,int,int>> pq;
            for (auto &c : classes) {
                int pass = c[0], total = c[1];
                pq.push({gain(pass, total), pass, total});
            }
            while (extraStudents--) {
                auto [g, pass, total] = pq.top(); pq.pop();
                pass++, total++;
                pq.push({gain(pass, total), pass, total});
            }
            double result = 0.0;
            while (!pq.empty()) {
                auto [g, pass, total] = pq.top(); pq.pop();
                result += (double)pass / total;
            }
            return result / classes.size();
        }
    };