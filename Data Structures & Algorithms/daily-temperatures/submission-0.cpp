class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        const int sz = t.size();
        if (sz == 1) {
            return {0};
        }
        // subrange
        deque<int> s;
        s.push_back(t[sz-1]);

        vector<int> r(sz, 0);
        for (int j=sz - 2; j >=0; --j) {
            if (t[j] >= s.back()) {
                s.clear();
                s.push_back(t[j]);
                continue;
            }

            for (auto it = s.begin(); it != s.end(); ++it) {
                r[j] += 1;
                if (t[j] >= *it) {
                    continue;
                }
                break;
            }
            s.push_front(t[j]);
        }

        return r;
    }
};
 