#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int N{}, K{};
		cin >> N >> K;
		for (int i = 0; i < N; ++i) {
			cout << (i % 2 ? (i / 2 + 1) : (N - i / 2)) << (i == N - 1 ? "\n" : " ");
		}
	}
	return 0;
}
