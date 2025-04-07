#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	ll ans{}, sum{};
	for (int i = 0; i < M - 1; ++i) {
		sum += A[i];
	}
	for (int i = M - 1; i < N; ++i) {
		sum += A[i];
		ans = max(ans, sum);
		sum -= A[i - M + 1];
	}
	cout << ans << "\n";
	return 0;
}
