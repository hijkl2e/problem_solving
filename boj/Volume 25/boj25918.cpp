#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	cin.ignore();
	string S;
	getline(cin, S);
	stack<char> st;
	int ans{};
	for (char c : S) {
		char d = c == '(' ? ')' : '(';
		if (st.size() && st.top() == d) {
			st.pop();
		} else {
			st.push(c);
		}
		ans = max<int>(ans, st.size());
	}
	if (st.size()) {
		ans = -1;
	}
	cout << ans << "\n";
	return 0;
}
