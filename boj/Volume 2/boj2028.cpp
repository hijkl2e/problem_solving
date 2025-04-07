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
		int x = 1;
		while (x <= N) {
			x *= 10;
		}
		cout << (N * N % x == N ? "YES" : "NO") << "\n";
	}
	return 0;
}
