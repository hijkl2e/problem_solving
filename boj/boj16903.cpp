#include <bits/stdc++.h>

using namespace std;

struct Trie {
	Trie() {
		memset(next, -1, sizeof next);
	}
	void insert(int x, int i, int z) {
		cnt += z;
		if (i == -1) {
			return;
		}
		int j = (x >> i) & 1;
		if (next[j] == -1) {
			next[j] = trie_cnt++;
		}
		node[next[j]].insert(x, i - 1, z);
	}
	int solve(int x, int i) {
		if (i == -1) {
			return 0;
		}
		int j = ((x >> i) & 1) ^ 1;
		if (next[j] == -1 || node[next[j]].cnt == 0) {
			j ^= 1;
		}
		return (j << i) | node[next[j]].solve(x, i - 1);
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
	Trie::node.resize(6000001);
	Trie &root = Trie::node[0];
	root.insert(0, 29, 1);
	int M{};
	cin >> M;
	while (M--) {
		int q{}, x{};
		cin >> q >> x;
		if (q == 3) {
			cout << (root.solve(x, 29) ^ x) << "\n";
		} else {
			root.insert(x, 29, q == 1 ? 1 : -1);
		}
	}
	return 0;
}
