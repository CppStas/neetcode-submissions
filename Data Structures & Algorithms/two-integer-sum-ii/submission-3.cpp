class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int sz = numbers.size();
        if (sz == 0) return {1,2};
        
        auto f = numbers.begin();
        int prev = *f - 1;
        while(f != numbers.end()) {
            if (*f == prev) {
                ++f;
                continue;
            } else {
                prev = *f;
            }
            auto s = f + 1;
            while (s != numbers.end()) {
                if (*f + *s == target) {
                    return {
                        static_cast<int>(std::distance(numbers.begin(), f) + 1),
                        static_cast<int>(std::distance(numbers.begin(), s) + 1)};
                }
                ++s;
            }
            ++f;
        }
        return {};
    }
};
