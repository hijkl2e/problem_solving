#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ii = pair<ll, ll>;

vector<string> A;
vector<ll> B;

vector<ii> solve(int s, int e) {
	vector<ii> C(1 << (e - s));
	for (int i = 0; i < C.size(); ++i) {
		auto &[x, y] = C[i];
		for (int j = 0; j < e - s; ++j) {
			if (i & (1 << j)) {
				x += B[s + j];
				y += A[s + j].size();
			}
		}
	}
	return C;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	cin.ignore();
	A.resize(N);
	for (int i = 0; i < N; ++i) {
		getline(cin, A[i]);
	}
	B.resize(N);
	for (int i = 0; i < N; ++i) {
		ll x = 1LL << 39;
		for (char c : A[i]) {
			if (x < (1LL << 39) || c != A[i][0]) {
				x /= 2;
			}
			B[i] += (c == 'B' ? 1 : -1) * x;
		}
	}
	vector<ii> C = solve(0, N / 2);
	vector<ii> D = solve(N / 2, N);
	sort(C.begin(), C.end());
	sort(D.rbegin(), D.rend());
	ll ans{};
	int p1{}, p2{};
	while (p1 < C.size() && p2 < D.size()) {
		auto &[x1, y1] = C[p1];
		auto &[x2, y2] = D[p2];
		if (x1 + x2 < 0) {
			++p1;
		} else if (x1 + x2 > 0) {
			++p2;
		} else {
			ans = max(ans, y1 + y2);
			++p1;
		}
	}
	cout << ans << "\n";
	return 0;
}
