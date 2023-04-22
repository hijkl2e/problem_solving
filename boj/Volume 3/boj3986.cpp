#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	cin.ignore();
	int ans{};
	while (N--) {
		string S;
		getline(cin, S);
		stack<char> st;
		for (char c : S) {
			if (st.size() && st.top() == c) {
				st.pop();
			} else {
				st.push(c);
			}
		}
		if (st.empty()) {
			++ans;
		}
	}
	cout << ans << "\n";
	return 0;
}
