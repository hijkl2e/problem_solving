#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 998244353;

ll pow(ll x, ll y) {
	ll ret = 1;
	while (y) {
		if (y % 2) {
			ret = ret * x % MOD;
		}
		x = x * x % MOD;
		y /= 2;
	}
	return ret;
}

struct Trie {
	Trie() {
		memset(next, -1, sizeof next);
	}
	void insert(int x, int i, int y) {
		cnt += y;
		if (i == -1) {
			return;
		}
		int j = (x >> i) & 1;
		if (next[j] == -1) {
			next[j] = trie_cnt++;
		}
		node[next[j]].insert(x, i - 1, y);
	}
	int query(int x, int i, int k) {
		if (i == -1) {
			return cnt * (k + 1);
		}
		int ret{};
		int j = (x >> i) & 1;
		if (next[j ^ 1] != -1) {
			ret += (2 * k + 3) * node[next[j ^ 1]].cnt;
		}
		ret += node[next[j]].query(x, i - 1, k + j);
		return ret;
	}
	int cnt{};
	int next[2]{};
	static int trie_cnt;
	static vector<Trie> node;
};

int Trie::trie_cnt;
vector<Trie> Trie::node;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	Trie::node.resize(7000007);
	int T{};
	cin >> T;
	while (T--) {
		ll N{};
		cin >> N;
		vector<int> A(N);
		for (int i = 0; i < N; ++i) {
			cin >> A[i];
		}
		sort(A.begin(), A.end());
		Trie &root = Trie::node[Trie::trie_cnt++];
		ll ans{};
		for (int i = 0, j = 1; i < N; i = j++) {
			while (j < N && A[i] == A[j]) {
				++j;
			}
			root.insert(A[i], 30, j - i);
			ans += 1LL * (j - i) * root.query(A[i], 30, 0);
		}
		ans = ans % MOD * pow(N * N % MOD, MOD - 2) % MOD;
		cout << ans << "\n";
	}
	return 0;
}
