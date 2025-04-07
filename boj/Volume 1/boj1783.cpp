#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	int ans{};
	if (N == 1) {
		ans = 1;
	} else if (N == 2) {
		ans = min((M + 1) / 2, 4);
	} else {
		ans = max(min(M, 4), M - 2);
	}
	cout << ans << "\n";
	return 0;
}
