#include <bits/stdc++.h>

using namespace std;

using ll = long long;

struct Trie {
	Trie() {
		memset(next, -1, sizeof next);
	}
	void insert(int x, int i) {
		++cnt;
		if (i == -1) {
			return;
		}
		int j = (x >> i) & 1;
		if (next[j] == -1) {
			next[j] = trie_cnt++;
		}
		node[next[j]].insert(x, i - 1);
	}
	int solve(int x, int y, int i) {
		if (i == -1) {
			return 0;
		}
		int ret{};
		int j = (x >> i) & 1;
		int k = (y >> i) & 1;
		if (k && next[j] != -1) {
			ret += node[next[j]].cnt;
		}
		if (next[j ^ k] != -1) {
			ret += node[next[j ^ k]].solve(x, y, i - 1);
		}
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
	Trie::trie_cnt = 1;
	Trie::node.resize(2000001);
	Trie &root = Trie::node[0];
	int N{}, K{};
	cin >> N >> K;
	vector<int> A(N + 1);
	for (int i = 1; i <= N; ++i) {
		cin >> A[i];
	}
	for (int i = 1; i <= N; ++i) {
		A[i] ^= A[i - 1];
	}
	ll ans{};
	for (int i = 0; i <= N; ++i) {
		ans += root.solve(A[i], K, 19);
		root.insert(A[i], 19);
	}
	cout << ans << "\n";
	return 0;
}
