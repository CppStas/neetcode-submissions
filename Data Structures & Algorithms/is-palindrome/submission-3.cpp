class Solution {
public:
    inline bool isAlphaNum(char c) {
        return  c >= 'a' && c <= 'z' ||
                c >= 'A' && c <= 'Z' ||
                c >= '0' && c <= '9';
    }
    inline bool areEqual(char lhs, char rhs) {
        lhs = lhs >= 'a' ? lhs - ('a' - 'A') : lhs;
        rhs = rhs >= 'a' ? rhs - ('a' - 'A') : rhs;
        return lhs == rhs;
    }

    bool isPalindrome(string s) {
        const int sz = s.size();
        if (sz == 1) return true;

        auto lhs = s.begin();
        auto rhs = s.end() - 1;

        while (lhs <= rhs) {
            if (isAlphaNum(*lhs)) {
                while(!isAlphaNum(*rhs)) {
                    --rhs;
                }
                if (!areEqual(*lhs, *rhs)) return false;
                --rhs;
            }
            ++lhs;
        }
        return true;
    }
};
