#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string N, M;
	getline(cin, N);
	getline(cin, M);
	if (N.size() < M.size()) {
		N = string(M.size() - N.size(), '0') + N;
	}
	string ans;
	ans += N.substr(0, N.size() - M.size() + 1);
	ans += ".";
	ans += N.substr(N.size() - M.size() + 1);
	while (true) {
		if (ans.back() == '0') {
			ans.erase(ans.size() - 1);
		} else if (ans.back() == '.') {
			ans.erase(ans.size() - 1);
			break;
		} else {
			break;
		}
	}
	cout << ans << "\n";
	return 0;
}
