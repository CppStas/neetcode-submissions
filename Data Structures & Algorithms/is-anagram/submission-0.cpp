class Solution {
public:
    bool isAnagram(string s, string t) {
        const auto sz = s.size();
        if (sz != t.size()) return false;
        std::unordered_map<char, int> m;
        for (int i{}; i < sz; ++i) {
            ++m[s[i]];
        }
        for (int i{}; i < sz; ++i) {
            const char cc = t[i];
            --m[cc];
            if (m[cc] < 0) return false;
        }   

        return true;
    }
};
