#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int M{};
	cin >> M;
	vector<int> A(M);
	for (int i = 0; i < M; ++i) {
		int h{}, m{};
		char c{};
		cin >> h >> c >> m;
		A[i] = 60 * (h % 12) + m;
	}
	int ans = M;
	deque<bool> B(720);
	for (int i = 0; i < 720; ++i) {
		fill(B.begin(), B.end(), false);
		for (int j = 0; j < M; ++j) {
			int t = ((A[j] - i * j) % 720 + 720) % 720;
			B[t] = true;
		}
		ans = min(ans, accumulate(B.begin(), B.end(), 0));
	}
	cout << ans << "\n";
	return 0;
}
