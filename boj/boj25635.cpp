#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<ll> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	ll sum = accumulate(A.begin(), A.end(), 0LL);
	ll maxv = *max_element(A.begin(), A.end());
	ll ans = sum - maxv + min(maxv, sum - maxv + 1);
	cout << ans << "\n";
	return 0;
}
