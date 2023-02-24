#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll INF = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<ll> A(N - 1);
	for (int i = 0; i < N - 1; ++i) {
		cin >> A[i];
	}
	vector<ll> B(N);
	for (int i = 0; i < N; ++i) {
		cin >> B[i];
	}
	ll ans{}, minv = INF;
	for (int i = 0; i < N - 1; ++i) {
		minv = min(minv, B[i]);
		ans += minv * A[i];
	}
	cout << ans << "\n";
	return 0;
}
