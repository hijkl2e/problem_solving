#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, K{};
	cin >> N >> K;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	int ans = -INF;
	for (int i = 0; i <= N - K; ++i) {
		ans = max(ans, accumulate(A.begin() + i, A.begin() + i + K, 0));
	}
	cout << ans << "\n";
	return 0;
}
