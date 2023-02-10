#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	cin.ignore();
	vector<string> A(N);
	for (int i = 0; i < N; ++i) {
		getline(cin, A[i]);
	}
	int ans = 32;
	for (int i = 0; i < N - 7; ++i) {
		for (int j = 0; j < M - 7; ++j) {
			int cnt{};
			for (int k = 0; k < 8; ++k) {
				for (int l = 0; l < 8; ++l) {
					if (((k + l) % 2) ^ (A[i + k][j + l] == 'B')) {
						++cnt;
					}
				}
			}
			ans = min(ans, min(cnt, 64 - cnt));
		}
	}
	cout << ans << "\n";
	return 0;
}
