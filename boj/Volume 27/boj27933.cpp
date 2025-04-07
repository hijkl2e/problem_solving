#include <bits/stdc++.h>

using namespace std;

using ll = long long;

string S;
vector<int> B;
vector<ll> C, L, R;

ll solve(int l, int r, char c) {
	ll ret{};
	int s = B[l], e = B[r];
	bool f1{}, f2{};
	if (S[l] == (c ^ 18)) {
		++s, f1 = true;
	}
	if (S[r] == c) {
		--e, f2 = true;
	}
	if (0 <= s && s < e && e < B.size()) {
		ret = (f1 ? 0 : R[l]) + (f2 ? 0 : L[r]) + C[e + f2 - 1] - C[s - f1];
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	cin.ignore();
	getline(cin, S);
	vector<ll> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	B.resize(N);
	for (int i = 0; i < N; ++i) {
		if (i && S[i] == S[i - 1]) {
			C.back() = max(C.back(), A[i]);
		} else {
			C.push_back(A[i]);
		}
		B[i] = C.size() - 1;
	}
	partial_sum(C.begin(), C.end(), C.begin());
	L.resize(N);
	R.resize(N);
	for (int i = 0; i < N; ++i) {
		L[i] = max(i && S[i] == S[i - 1] ? L[i - 1] : 0, A[i]);
	}
	for (int i = N - 1; i >= 0; --i) {
		R[i] = max(i < N - 1 && S[i] == S[i + 1] ? R[i + 1] : 0, A[i]);
	}
	int T{};
	cin >> T;
	while (T--) {
		int l{}, r{};
		cin >> l >> r;
		--l, --r;
		ll ans_x = solve(l, r, 'Y');
		ll ans_y = solve(l, r, 'K');
		cout << (ans_x > ans_y ? "Y" : ans_x < ans_y ? "K" : "YK") << " " << max(ans_x, ans_y) << "\n";
	}
	return 0;
}
