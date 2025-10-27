class Solution {
public:
    bool isBeautiful(const vector<int>& count) {
        for (int d = 1; d <= 7; ++d) {
            if (count[d] != 0 && count[d] != d)
                return false;
        }
        return true;
    }

    void generate(long num, vector<int>& count, vector<int>& list) {
        if (num > 0 && isBeautiful(count)) {
            list.push_back((int)num);
        }
        if (num > 1224444) return;

        for (int d = 1; d <= 7; ++d) {
            if (count[d] < d) {
                count[d]++;
                generate(num * 10 + d, count, list);
                count[d]--;
            }
        }
    }

    int nextBeautifulNumber(int n) {
        vector<int> list;
        vector<int> count(10, 0);
        generate(0, count, list);
        sort(list.begin(), list.end());
        for (int num : list) {
            if (num > n) return num;
        }
        return -1;
    }
};


// TLE
class Solution {
public:
    bool isBalanced(int x) {
        string s = to_string(x);
        unordered_map<char, int> freq;
        for (char c : s) freq[c]++;
        for (auto [digit, count] : freq) {
            int d = digit - '0';
            if (count != d) return false;
        }
        return true;
    }

    int nextBeautifulNumber(int n) {
        for (int i = n + 1; ; ++i) {
            if (isBalanced(i)) return i;
        }
    }
};