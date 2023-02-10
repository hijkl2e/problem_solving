#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll INF = 4e18;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll N{}, D{};
	cin >> N >> D;
	vector<ll> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	ll ans = INF;
	for (int k = 0; k < 2; ++k) {
		vector<ll> B(N);
		for (int i = 0; i < N; ++i) {
			B[i] = i * D - A[i];
		}
		ans = min(ans, *max_element(B.begin(), B.end()) - *min_element(B.begin(), B.end()));
		reverse(A.begin(), A.end());
	}
	cout << ans / 2 << "." << (ans % 2 ? 5 : 0) << "\n";
	return 0;
}
