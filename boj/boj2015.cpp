#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll N{}, K{};
	cin >> N >> K;
	vector<ll> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	vector<ll> psum(N);
	partial_sum(A.begin(), A.end(), psum.begin());
	map<ll, ll> freq;
	++freq[0];
	ll ans{};
	for (int i = 0; i < N; ++i) {
		auto it = freq.find(psum[i] - K);
		if (it != freq.end()) {
			ans += it->second;
		}
		++freq[psum[i]];
	}
	cout << ans << "\n";
	return 0;
}
