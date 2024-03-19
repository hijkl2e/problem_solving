#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S;
	getline(cin, S);
	S = "(" + S + ")";
	stack<int> st;
	for (char c : S) {
		if (isdigit(c)) {
			st.top() *= (c - '0');
		} else if (c == ')') {
			int sum{};
			while (st.top() != -1) {
				sum += st.top(); st.pop();
			}
			st.top() = sum;
		} else {
			st.push(c == 'H' ? 1 : c == 'C' ? 12 : c == 'O' ? 16 : -1);
		}
	}
	cout << st.top() << "\n";
	return 0;
}
