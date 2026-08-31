class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int64_t total = 1;
        bool has_zero = false;
        bool two_zeroes = false;
        for (auto n : nums) {
            if (n==0) {
                if (has_zero) two_zeroes = true;
                has_zero = true;
                continue;
            }
            total *=n;
        }

        for (auto & n : nums) {
            if (has_zero) {
                n = n == 0
                    ? (two_zeroes ? 0 : total)
                    : 0;
                continue;
            }
            n = total / n;
        }

        return nums;
    }
};
 