class Solution {
public:
    bool isValid(string s) {
         int top = -1;
        for (char ch : s) {
            if (ch == '(' || ch == '[' || ch == '{') {
                s[++top] = ch;
            } else {
                if (top == -1) return false;
                
                char t = s[top];
                if ((ch == ')' && t == '(') || 
                    (ch == ']' && t == '[') || 
                    (ch == '}' && t == '{')) {
                    top--;
                } else {
                    return false;
                }
            }
        }
        return top == -1;
    }
};
