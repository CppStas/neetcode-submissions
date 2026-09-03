class Solution {
public:
    bool isValid(string s) {
        stack<char> cs;

        for (char ch : s) {
            if (ch == '(' || ch == '[' || ch == '{') {
                cs.push(ch);
            } else {
                if (cs.empty())  return false;
                const char t = cs.top();
                if (t == '(' && ch == ')' || t == '[' && ch == ']' || t == '{' && ch == '}') {
                    cs.pop();continue;
                }
                return false;
            }
        }
        return cs.empty();
    }
};
