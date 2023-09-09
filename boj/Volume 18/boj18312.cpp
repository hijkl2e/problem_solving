#include <bits/stdc++.h>

using namespace std;

bool solve(int x, int y) {
	return x % 10 == y || x / 10 == y;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, K{};
	cin >> N >> K;
	int ans{};
	for (int i = 0; i <= N; ++i) {
		for (int j = 0; j < 60; ++j) {
			for (int k = 0; k < 60; ++k) {
				if (solve(i, K) || solve(j, K) || solve(k, K)) {
					++ans;
				}
			}
		}
	}
	cout << ans << "\n";
	return 0;
}
