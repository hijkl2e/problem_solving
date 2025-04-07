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
		if (N == 3) {
			cout << "NO\n";
			continue;
		}
		cout << "YES\n";
		if (N % 2 == 0) {
			for (int i = 0; i < N; ++i) {
				cout << (i % 2 ? -1 : 1) << (i == N - 1 ? "\n" : " ");
			}
		} else {
			int k = N / 2;
			for (int i = 0; i < N; ++i) {
				cout << (i % 2 ? -k : (k - 1)) << (i == N - 1 ? "\n" : " ");
			}
		}
	}
	return 0;
}
