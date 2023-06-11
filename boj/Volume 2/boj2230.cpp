#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll INF = 4e18;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<ll> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	sort(A.begin(), A.end());
	ll ans = INF;
	for (int i = 0, j = 0; i < N; ++i) {
		while (j < N && A[j] - A[i] < M) {
			++j;
		}
		if (j == N) {
			break;
		}
		ans = min(ans, A[j] - A[i]);
	}
	cout << ans << "\n";
	return 0;
}
