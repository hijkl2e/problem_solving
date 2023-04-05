#include <bits/stdc++.h>

using namespace std;

using ll = long long;

struct Trie {
	Trie() {
		memset(next, -1, sizeof next);
	}
	void insert(string &s, int i, int x) {
		cnt += x;
		if (i == s.size()) {
			return;
		}
		int j = s[i] - 'a';
		if (next[j] == -1) {
			next[j] = trie_cnt++;
		}
		node[next[j]].insert(s, i + 1, x);
	}
	void find(string &s, int i, vector<int> &A) {
		A[i] += cnt;
		if (i == s.size()) {
			return;
		}
		int j = s[i] - 'a';
		if (next[j] != -1) {
			node[next[j]].find(s, i + 1, A);
		}
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
	Trie::trie_cnt = 2;
	Trie::node.resize(1000005);
	Trie &pre = Trie::node[0];
	Trie &suf = Trie::node[1];
	int Q{};
	cin >> Q;
	while (Q--) {
		string cmd;
		cin >> cmd;
		if (cmd == "add" || cmd == "delete") {
			char c{};
			string s;
			cin >> c >> s;
			if (c == 'A') {
				pre.insert(s, 0, cmd == "add" ? 1 : -1);
			} else {
				reverse(s.begin(), s.end());
				suf.insert(s, 0, cmd == "add" ? 1 : -1);
			}
		} else {
			string s;
			cin >> s;
			vector<int> A(s.size() + 1);
			vector<int> B(s.size() + 1);
			pre.find(s, 0, A);
			reverse(s.begin(), s.end());
			suf.find(s, 0, B);
			ll ans{};
			for (int i = 1; i < A.size() - 1; ++i) {
				ans += 1LL * A[i] * B[s.size() - i];
			}
			cout << ans << "\n";
		}
	}
	return 0;
}
