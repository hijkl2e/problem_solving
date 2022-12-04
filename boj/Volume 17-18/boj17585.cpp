#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	deque<bool> A(N);
	for (int i = 0; i < N; ++i) {
		char c{};
		cin >> c;
		A[i] = c == 'T';
	}
	stack<bool> st;
	char c{};
	while (cin >> c) {
		if (c == '*') {
			bool x = st.top(); st.pop();
			st.top() &= x;
		} else if (c == '+') {
			bool x = st.top(); st.pop();
			st.top() |= x;
		} else if (c == '-') {
			st.top() ^= true;
		} else {
			st.push(A[c - 'A']);
		}
	}
	cout << (st.top() ? "T" : "F") << "\n";
	return 0;
}
