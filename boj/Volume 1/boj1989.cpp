#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ii = pair<int, int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<ll> A(N + 1);
	for (int i = 1; i <= N; ++i) {
		cin >> A[i];
	}
	vector<ll> B(N + 1);
	partial_sum(A.begin(), A.end(), B.begin());
	vector<ii> C(N);
	for (int i = 0; i < N; ++i) {
		C[i] = {A[i + 1], i + 1};
	}
	sort(C.rbegin(), C.rend());
	set<int> S;
	for (int i = 1; i <= N; ++i) {
		S.insert(S.end(), i);
	}
	ll ans = -1;
	int p1{}, p2{};
	for (auto &p : C) {
		int l = 1, r = N;
		auto it = S.find(p.second);
		if (it != S.begin()) {
			l = *prev(it) + 1;
		}
		if (next(it) != S.end()) {
			r = *next(it) - 1;
		}
		ll res = (B[r] - B[l - 1]) * A[p.second];
		if (ans < res) {
			ans = res;
			p1 = l, p2 = r;
		}
		S.erase(it);
	}
	cout << ans << "\n";
	cout << p1 << " " << p2 << "\n";
	return 0;
}
