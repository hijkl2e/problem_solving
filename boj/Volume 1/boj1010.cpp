#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int N{}, M{};
		cin >> N >> M;
		N = min(N, M - N);
		int ans = 1;
		for (int i = 0; i < N; ++i) {
			ans *= M - i;
			ans /= i + 1;
		}
		cout << ans << "\n";
	}
	return 0;
}
