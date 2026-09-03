class Solution {
public:
    bool isValid(string s) {
        stack<char> cs;

        for (char ch : s) {
            if (ch == '(' || ch == '[' || ch == '{') {
                cs.push(ch);
            } else {
                if (cs.empty()) return false;

                const char t = cs.top();
                switch(ch) {
                    case ')':
                        if (t != '(') return false;
                        break;
                    case ']':
                        if (t != '[') return false;
                        break;
                    case '}':
                        if (t != '{') return false;
                        break;
                }
                cs.pop();
            }

        }
        return cs.empty();
    }
};
