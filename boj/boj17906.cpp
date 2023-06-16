#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ii = pair<int, int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<ll> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	sort(A.rbegin(), A.rend());
	vector<ii> B(M);
	for (int i = 0; i < M; ++i) {
		cin >> B[i].second >> B[i].first;
	}
	sort(B.rbegin(), B.rend());
	ll ans{};
	for (int i = 0, j = 0; i < N && j < M; ++i) {
		ans += A[i] * B[j].first;
		if (--B[j].second == 0) {
			++j;
		}
	}
	cout << ans << "\n";
	return 0;
}
