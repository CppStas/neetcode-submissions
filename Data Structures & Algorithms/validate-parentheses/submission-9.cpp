class Solution {
public:
    bool isValid(string s) {
        string cs;
        cs.reserve(s.length() / 2); 

        for (char ch : s) {
            if (ch == '(' || ch == '[' || ch == '{') {
                cs.push_back(ch);
            } else {
                if (cs.empty()) return false;
                char t = cs.back();
                if ((ch == ')' && t == '(') || 
                    (ch == ']' && t == '[') || 
                    (ch == '}' && t == '{')) {
                    cs.pop_back();
                } else {
                    return false;
                }
            }
        }
        return cs.empty();
    }
};
