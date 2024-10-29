#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S;
	getline(cin, S);
	stack<int> st;
	for (char c : S) {
		if (isdigit(c)) {
			st.push(c - '0');
			continue;
		}
		int y = st.top(); st.pop();
		int x = st.top(); st.pop();
		if (c == '+') {
			st.push(x + y);
		} else if (c == '-') {
			st.push(x - y);
		} else if (c == '*') {
			st.push(x * y);
		} else if (c == '/') {
			st.push(x / y);
		}
	}
	cout << st.top() << "\n";
	return 0;
}
