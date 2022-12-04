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
		int M = (N + 1) / 2;
		cout << M << "\n";
		for (int i = 0; i < M; ++i) {
			int x = 3 * i + 1;
			int y = 3 * (N - i);
			cout << x << " " << y << "\n";
		}
	}
	return 0;
}
