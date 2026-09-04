class Solution {
public:
    inline bool isAlphaNum(char c) noexcept {
        return  c >= 'a' && c <= 'z' ||
                c >= 'A' && c <= 'Z' ||
                c >= '0' && c <= '9';
    }
    inline bool areEqual(char lhs, char rhs) noexcept {
        lhs = lhs >= 'a' ? lhs - ('a' - 'A') : lhs;
        rhs = rhs >= 'a' ? rhs - ('a' - 'A') : rhs;
        return lhs == rhs;
    }

    bool isPalindrome(string s) {
        auto lhs = s.begin();
        auto rhs = s.end() - 1;

        while (lhs < rhs) {
            while (!isAlphaNum(*lhs)) {
                ++lhs;
            }
            while(!isAlphaNum(*rhs)) {
                --rhs;
            }
            if (lhs < rhs && !areEqual(*lhs, *rhs)) return false;
            ++lhs;
            --rhs;
        }
        return true;
    }
};
