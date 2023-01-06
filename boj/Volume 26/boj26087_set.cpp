#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ii = pair<int, int>;

const ll MOD = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, Q{};
	cin >> N >> Q;
	vector<ll> F(N + 1);
	F[0] = F[1] = 1;
	for (int i = 2; i <= N; ++i) {
		F[i] = (F[i - 1] + F[i - 2]) % MOD;
	}
	F[0] = 0;
	vector<ii> A(Q);
	for (int i = Q - 1; i >= 0; --i) {
		cin >> A[i].first >> A[i].second;
	}
	set<int> S;
	for (int i = 1; i <= N; ++i) {
		S.insert(S.end(), i);
	}
	vector<int> B(N + 1);
	for (auto &[u, v] : A) {
		auto it = S.lower_bound(u);
		while (it != S.end() && *it <= v) {
			B[*it] = *it - u + 1;
			it = S.erase(it);
		}
	}
	for (int i = 1; i <= N; ++i) {
		cout << F[B[i]] << (i == N ? "\n" : " ");
	}
	return 0;
}
