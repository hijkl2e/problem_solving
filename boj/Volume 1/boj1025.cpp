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
	int ans = -1;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			for (int k = -i; i + k < N; ++k) {
				for (int l = -j; j + l < M; ++l) {
					int r = i, c = j;
					int x{};
					do {
						x = 10 * x + A[r][c] - '0';
						int y = sqrt(x);
						if (y * y == x) {
							ans = max(ans, x);
						}
						r += k, c += l;
					} while (0 <= r && r < N && 0 <= c && c < M && (k || l));
				}
			}
		}
	}
	cout << ans << "\n";
	return 0;
}
