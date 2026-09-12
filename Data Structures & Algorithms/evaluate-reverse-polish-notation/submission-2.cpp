class Solution {
public:
	int evalRPN(vector<string>& tokens) {
		const int sz = tokens.size();
		if (sz == 1) return std::stoi(tokens[0]);

		stack<int> s;
		for (int i{}; i < sz; ++i) {
			char c = tokens[i].at(0);
			if (tokens[i].size() == 1 && (c == '+' || c == '-' ||c == '*' || c == '/')) {
				int rhs = s.top();
				s.pop();
				int lhs = s.top();
				s.pop();

				switch (c) {
				case '+':
				{

					int res = lhs + rhs;
					s.push(res);
				}
				break;
				case '-': {
					int res = lhs - rhs;
					s.push(res);
				}
						break;
				case '*': {
					int res = lhs * rhs;
					s.push(res);
				}
						break;
				case '/': {
					int res = lhs / rhs;
					s.push(res);
				}
						break;
				}
			}
			else {
				int v = stoi(tokens[i]);
				s.push(v);
			}

		}
		return s.top();
	}
};