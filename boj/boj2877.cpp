#include <bits/stdc++.h>

using namespace std;

string solve(int step, int len, int K) {
	if (step == len) {
		return "";
	} else if (K <= (1 << (len - step - 1))) {
		return "4" + solve(step + 1, len, K);
	} else {
		return "7" + solve(step + 1, len, K - (1 << (len - step - 1)));
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int K{};
	cin >> K;
	string ans;
	for (int i = 1;; ++i) {
		if (K <= (1 << i)) {
			ans = solve(0, i, K);
			break;
		}
		K -= 1 << i;
	}
	cout << ans << "\n";
	return 0;
}
