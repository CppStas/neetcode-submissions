class Solution {
public:
    static bool isAlphaNum(char c) {
        return (c >= 'a' && c <= 'z') ||
               (c >= 'A' && c <= 'Z') ||
               (c >= '0' && c <= '9');
    }

    static bool areEqual(char lhs, char rhs) {
        return (lhs | 0x20) == (rhs | 0x20);
    }

    bool isPalindrome(string s) {
        int lhs = 0;
        int rhs = static_cast<int>(s.size()) - 1;

        while (lhs < rhs) {
            if (!isAlphaNum(s[lhs])) { ++lhs; continue; }
            if (!isAlphaNum(s[rhs])) { --rhs; continue; }
            if (!areEqual(s[lhs], s[rhs])) return false;
            ++lhs;
            --rhs;
        }
        return true;
    }
};
