#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S;
	getline(cin, S);
	stack<char> st;
	for (char c : S) {
		if (isupper(c)) {
			cout << c;
		} else if (c == '(') {
			st.push(c);
		} else if (c == ')') {
			while (st.top() != '(') {
				cout << st.top(); st.pop();
			}
			st.pop();
		} else {
			while (st.size() && (st.top() == '*' || st.top() == '/')) {
				cout << st.top(); st.pop();
			}
			while (st.size() && (st.top() == '+' || st.top() == '-') && (c == '+' || c == '-')) {
				cout << st.top(); st.pop();
			}
			st.push(c);
		}
	}
	while (st.size()) {
		cout << st.top(); st.pop();
	}
	cout << "\n";
	return 0;
}
