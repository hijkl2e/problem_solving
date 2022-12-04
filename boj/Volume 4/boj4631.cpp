#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	for (int tc = 1; cin >> N, N; ++tc) {
		cout << "SET " << tc << "\n";
		stack<string> st;
		for (int i = 0; i < N; ++i) {
			string s;
			cin >> s;
			if (i % 2) {
				st.push(s);
			} else {
				cout << s << "\n";
			}
		}
		while (st.size()) {
			cout << st.top() << "\n";
			st.pop();
		}
	}
	return 0;
}
