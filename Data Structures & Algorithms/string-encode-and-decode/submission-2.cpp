class Solution {
public:

    string encode(vector<string>& strs) {
        const int sz = strs.size();
        if (sz == 0) return {};

        std::string ec(sz+1, 0);
        ec[0] = sz;
        for (int i{}; i < sz; ++i) {
            const int k = strs[i].size();
            ec[i+1] = k;
            for (int j{}; j < k; ++j) {
                ec.push_back(strs[i][j]);
            }
        }
        return ec;
    }

    vector<string> decode(string s) {
        const int sz = s.size();
        if (sz == 0) return {};

        vector<string> res;
        const int substr_sz = static_cast<int>(s[0]);

        for (int i{}, j{substr_sz+1}; i < substr_sz; ++i) {
            int k = static_cast<int>(s[i+1]);
            if (k < 0) k += 256;
            std::string ss(k, 0);
            for (int m=0; m < k; ++j, ++m) {
                ss[m]=s[j];
            }
            res.push_back(std::move(ss));
        }
        return res;
    }
};
