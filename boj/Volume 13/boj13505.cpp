#include <bits/stdc++.h>

using namespace std;

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
	int solve(int x, int i) {
		if (i == -1) {
			return 0;
		}
		int j = ((x >> i) & 1) ^ 1;
		if (next[j] == -1) {
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
	Trie::node.resize(3000001);
	Trie &root = Trie::node[0];
	int N{};
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	for (int i = 0; i < N; ++i) {
		root.insert(A[i], 29);
	}
	int ans{};
	for (int i = 0; i < N; ++i) {
		ans = max(ans, root.solve(A[i], 29) ^ A[i]);
	}
	cout << ans << "\n";
	return 0;
}
