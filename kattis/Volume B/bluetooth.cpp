#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<int> A(4, 8);
	int N{};
	cin >> N;
	while (N--) {
		string s;
		char c{};
		cin >> s >> c;
		int idx{};
		if (isdigit(s[0])) {
			reverse(s.begin(), s.end());
			idx = 2;
		}
		idx += s[0] == '-';
		if (c == 'm') {
			A[idx] = max(A[idx] - 1, 0);
		} else {
			A[idx] = 0;
		}
	}
	int ans = min(A[0], A[1]) ? 0 : min(A[2], A[3]) ? 1 : 2;
	cout << ans << "\n";
	return 0;
}
