#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	cin.ignore();
	vector<string> A(N);
	for (int i = 0; i < N; ++i) {
		getline(cin, A[i]);
	}
	int minx = 1e9, maxx{};
	int miny = 1e9, maxy{};
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (A[i][j] == '.') {
				continue;
			}
			minx = min(minx, i);
			maxx = max(maxx, i);
			miny = min(miny, j);
			maxy = max(maxy, j);
		}
	}
	int ans{};
	if (minx != maxx) {
		ans += min(maxx, N - minx - 1);
	}
	if (miny != maxy) {
		ans += min(maxy, N - miny - 1);
	}
	cout << ans << "\n";
	return 0;
}
