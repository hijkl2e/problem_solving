#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	int ans = -INF, minv = INF;
	for (int i = 0; i <= M; ++i) {
		minv = min(minv, A[i]);
		ans = max(ans, A[N + i - M - 1] - minv);
	}
	cout << ans << "\n";
	return 0;
}
