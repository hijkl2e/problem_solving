#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 998244353;

vector<int> B;

ll solve(int M, ll val, int idx, int cnt) {
	if (B.size() == idx) {
		return (cnt % 2 ? -1 : 1) * (M / val);
	}
	ll ret{};
	ret += solve(M, val * B[idx], idx + 1, cnt + 1);
	ret += solve(M, val, idx + 1, cnt);
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int N{}, M{};
		cin >> N >> M;
		vector<int> A(N);
		for (int i = 0; i < N; ++i) {
			cin >> A[i];
		}
		ll ans = 1;
		for (int i = 1; i < N; ++i) {
			if (A[i - 1] % A[i]) {
				ans = 0;
				break;
			} else if (A[i - 1] == A[i]) {
				ans = ans * (M / A[i]) % MOD;
				continue;
			}
			B.clear();
			int x = A[i - 1] / A[i];
			for (int i = 2; i * i <= x; ++i) {
				if (x % i) {
					continue;
				}
				while (x % i == 0) {
					x /= i;
				}
				B.push_back(i);
			}
			if (x > 1) {
				B.push_back(x);
			}
			ans = ans * solve(M / A[i], 1, 0, 0) % MOD;
		}
		cout << ans << "\n";
	}
	return 0;
}
