#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

const int MOD = 9901;

class UF {
public:
	UF(int N) : par(N), sz(N, 1) {
		for (int i = 0; i < N; ++i) {
			par[i] = i;
		}
	}
	int root(int x) {
		return par[x] == x ? x : (par[x] = root(par[x]));
	}
	bool same(int x, int y) {
		return root(x) == root(y);
	}
	bool unite(int x, int y) {
		x = root(x);
		y = root(y);
		if (x == y) {
			return false;
		}
		if (sz[x] < sz[y]) {
			swap(x, y);
		}
		par[y] = x;
		sz[x] += sz[y];
		return true;
	}
	int size(int x) {
		return sz[root(x)];
	}
private:
	vector<int> par, sz;
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<int> fact(301);
	fact[0] = 1;
	for (int i = 1; i < fact.size(); ++i) {
		fact[i] = i * fact[i - 1] % MOD;
	}
	int T{};
	cin >> T;
	for (int tc = 1; tc <= T; ++tc) {
		int N{}, K{};
		cin >> N >> K;
		vector<ii> E(K);
		for (auto &[u, v] : E) {
			cin >> u >> v;
		}
		vector<int> A(N + 1);
		vector<int> B(4);
		int ans = 4951 * fact[N - 1] % MOD;
		for (int i = 1; i < (1 << K); ++i) {
			fill(A.begin(), A.end(), 0);
			fill(B.begin(), B.end(), 0);
			UF uf(N + 1);
			int cc{};
			for (int j = 0; j < K; ++j) {
				if (i & (1 << j)) {
					auto &[u, v] = E[j];
					++A[u], ++A[v];
					if (!uf.unite(u, v)) {
						++cc;
					}
				}
			}
			int pc = __builtin_popcount(i);
			for (int j = 1; j <= N; ++j) {
				++B[min(A[j], 3)];
			}
			if (B[3]) {
				continue;
			} else if (cc) {
				if (cc == 1 && pc == N) {
					ans += pc % 2 ? -1 : 1;
				}
				continue;
			}
			int cnt = (fact[N - pc - 1] << (B[1] / 2 - 1)) % MOD;
			ans += (pc % 2 ? -1 : 1) * cnt;
		}
		ans = (ans % MOD + MOD) % MOD;
		cout << "Case #" << tc << ": " << ans << "\n";
	}
	return 0;
}
