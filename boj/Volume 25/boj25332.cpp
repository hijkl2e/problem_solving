#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<ll> A(N);
	vector<ll> B(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	for (int i = 0; i < N; ++i) {
		cin >> B[i];
	}
	for (int i = 0; i < N; ++i) {
		A[i] -= B[i];
	}
	vector<ll> psum(N);
	partial_sum(A.begin(), A.end(), psum.begin());
	map<ll, ll> freq;
	++freq[0];
	ll ans{};
	for (int i = 0; i < N; ++i) {
		ans += freq[psum[i]]++;
	}
	cout << ans << "\n";
	return 0;
}
