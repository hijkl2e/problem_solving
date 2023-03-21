#include <bits/stdc++.h>

using namespace std;

struct Trie {
	void insert(int x, int i) {
		if (i == -1) {
			return;
		}
		int j = (x >> i) & 1;
		if (next[j] == -1) {
			next[j] = trie_cnt++;
		}
		node[next[j]].insert(x, i - 1);
	}
	int find(int x, int i) {
		if (i == -1) {
			return 0;
		}
		int j = ((x >> i) & 1) ^ 1;
		if (next[j] == -1) {
			j ^= 1;
		}
		return (j << i) | node[next[j]].find(x, i - 1);
	}
	int next[2]{-1, -1};
	static int trie_cnt;
	static vector<Trie> node;
};

int Trie::trie_cnt;
vector<Trie> Trie::node;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int N{};
		cin >> N;
		vector<int> A(N);
		for (int i = 0; i < N; ++i) {
			cin >> A[i];
		}
		Trie::trie_cnt = 1;
		Trie::node.assign(32 * N, Trie());
		Trie &root = Trie::node[0];
		int ans{}, x{};
		for (int i = 0; i < N; ++i) {
			root.insert(x, 30);
			x ^= A[i];
			ans = max(ans, x ^ root.find(x, 30));
		}
		cout << ans << "\n";
	}
	return 0;
}
