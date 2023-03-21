#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int solve(string &s, int mod) {
	int ret{};
	for (char c : s) {
		ret = (10 * ret + c - '0') % mod;
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	string M;
	cin >> N >> M;
	vector<int> A(N + 1);
	for (int i = 1; i <= N; ++i) {
		cin >> A[i];
	}
	vector<int> B(N + 1);
	for (int i = 1; i <= N; ++i) {
		B[i] = solve(M, i);
	}
	vector<ll> C;
	deque<bool> vst(N + 1);
	int Q{};
	cin >> Q;
	while (Q--) {
		int q{};
		cin >> q;
		if (q == 1) {
			int a{}, b{};
			cin >> a >> b;
			swap(A[a], A[b]);
			continue;
		}
		fill(vst.begin(), vst.end(), false);
		ll ans{};
		for (int i = 1; i <= N; ++i) {
			if (vst[i]) {
				continue;
			}
			C.clear();
			int j = i;
			while (!vst[j]) {
				vst[j] = true;
				C.push_back(j);
				j = A[j];
			}
			int x = B[C.size()];
			for (int i = x; i < C.size(); ++i) {
				ans += C[i] * C[i - x];
			}
			x = C.size() - x;
			for (int i = x; i < C.size(); ++i) {
				ans += C[i] * C[i - x];
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
