#include <bits/stdc++.h>

using namespace std;

using ll = long long;

struct Trie {
	Trie() {
		memset(next, -1, sizeof next);
	}
	void insert(ll x, int i) {
		++cnt;
		if (i == 60) {
			return;
		}
		int j = (x >> i) & 1;
		if (next[j] == -1) {
			next[j] = trie_cnt++;
		}
		node[next[j]].insert(x, i + 1);
	}
	int solve(ll x, int i) {
		return min(cnt, i < 60 ? node[next[(x >> i) & 1]].solve(x, i + 1) + (i ? 1 : 0) : cnt);
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
	Trie::trie_cnt = 1;
	Trie::node.resize(12000001);
	Trie &root = Trie::node[0];
	int N{};
	cin >> N;
	vector<ll> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	for (int i = 0; i < N; ++i) {
		root.insert(A[i], 0);
	}
	int ans{};
	for (int i = 0; i < N; ++i) {
		ans = max(ans, root.solve(A[i], 0));
	}
	cout << ans << "\n";
	return 0;
}
