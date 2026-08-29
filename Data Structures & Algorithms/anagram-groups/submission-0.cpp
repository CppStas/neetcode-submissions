class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        const int sz = strs.size();
        vector<vector<string>> res;
        if (sz <= 1) {
            res.push_back(std::move(strs));
            return res;
        }

        unordered_map<string, vector<string>> m;

        for (string & s : strs) {
            string sorted_str = s;
            sort(begin(sorted_str), end(sorted_str));
            m[sorted_str].push_back(move(s));
        }

        for (auto & kv : m) {
            res.push_back(std::move(kv.second));
        }

        return res;
    }
};
