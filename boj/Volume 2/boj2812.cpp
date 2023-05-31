#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, K{};
	cin >> N >> K;
	cin.ignore();
	string S;
	getline(cin, S);
	stack<char> st;
	for (char c : S) {
		while (st.size() && st.top() < c && K-- > 0) {
			st.pop();
		}
		st.push(c);
	}
	while (K-- > 0) {
		st.pop();
	}
	string ans;
	while (st.size()) {
		ans += st.top();
		st.pop();
	}
	reverse(ans.begin(), ans.end());
	cout << ans << "\n";
	return 0;
}
