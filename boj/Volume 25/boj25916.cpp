#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<ll> A(N + 2);
	for (int i = 1; i <= N; ++i) {
		cin >> A[i];
	}
	int S = 1, E = 0;
	ll sum{}, ans{};
	while (E <= N) {
		if (sum < M) {
			sum += A[++E];
		} else {
			sum -= A[S++];
		}
		if (sum <= M) {
			ans = max(ans, sum);
		}
	}
	cout << ans << "\n";
	return 0;
}
