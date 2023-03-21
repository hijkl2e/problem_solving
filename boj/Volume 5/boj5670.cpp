#include <bits/stdc++.h>

using namespace std;

struct Trie {
	Trie() {
		memset(next, -1, sizeof next);
	}
	void insert(string &s, int i) {
		if (i == s.size()) {
			++cnt;
			return;
		}
		int j = s[i] - 'a';
		if (next[j] == -1) {
			next[j] = trie_cnt++;
			++cnt;
		}
		node[next[j]].insert(s, i + 1);
	}
	int find(string &s, int i) {
		if (i == s.size()) {
			return 0;
		}
		int j = s[i] - 'a';
		return (cnt > 1) + node[next[j]].find(s, i + 1);
	}
	int cnt{};
	int next[26]{};
	static int trie_cnt;
	static vector<Trie> node;
};

int Trie::trie_cnt;
vector<Trie> Trie::node;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	while (cin >> N) {
		Trie::trie_cnt = 1;
		Trie::node.assign(80 * min(N, 12500) + 1, Trie());
		Trie &root = Trie::node[0];
		cin.ignore();
		vector<string> A(N);
		for (int i = 0; i < N; ++i) {
			getline(cin, A[i]);
		}
		root.cnt = 1;
		for (int i = 0; i < N; ++i) {
			root.insert(A[i], 0);
		}
		int sum{};
		for (int i = 0; i < N; ++i) {
			sum += root.find(A[i], 0);
		}
		double ans = sum * 1.0 / N;
		cout << fixed << setprecision(2);
		cout << ans << "\n";
	}
	return 0;
}
