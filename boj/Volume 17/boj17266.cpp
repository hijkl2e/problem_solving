#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<int> A(M);
	for (int i = 0; i < M; ++i) {
		cin >> A[i];
	}
	int ans = max(A[0], N - A[M - 1]);
	for (int i = 0; i < M - 1; ++i) {
		ans = max(ans, (A[i + 1] - A[i] + 1) / 2);
	}
	cout << ans << "\n";
	return 0;
}
