#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int N{};
		cin >> N;
		for (int i = 0; i < N; ++i) {
			int x{};
			if (i % 2) {
				x = N - i / 2;
			} else {
				x = (N + 1) / 2 - i / 2;
			}
			cout << x << (i == N - 1 ? "\n" : " ");
		}
	}
	return 0;
}
