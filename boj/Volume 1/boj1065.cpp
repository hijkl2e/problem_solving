#include <bits/stdc++.h>

using namespace std;

bool solve(int x) {
	if (x < 100) {
		return true;
	}
	string s = to_string(x);
	return s[1] - s[0] == s[2] - s[1];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	int ans{};
	for (int i = 1; i <= N; ++i) {
		if (solve(i)) {
			++ans;
		}
	}
	cout << ans << "\n";
	return 0;
}
