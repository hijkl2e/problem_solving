#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	for (int tc = 0; tc < T; ++tc) {
		if (tc) {
			cout << "\n";
		}
		int N{};
		cin >> N;
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				cout << (i == 0 || i == N - 1 || j == 0 || j == N - 1 ? '#' : 'J');
			}
			cout << "\n";
		}
	}
	return 0;
}
