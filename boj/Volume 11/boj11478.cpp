#include <bits/stdc++.h>

using namespace std;

struct Trie {
	Trie() {
		memset(next, -1, sizeof next);
	}
	void insert(string &s, int i) {
		if (i == s.size()) {
			return;
		}
		int j = s[i] - 'a';
		if (next[j] == -1) {
			next[j] = trie_cnt++;
		}
		node[next[j]].insert(s, i + 1);
	}
	int next[26]{};
	static int trie_cnt;
	static vector<Trie> node;
};

int Trie::trie_cnt;
vector<Trie> Trie::node;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string s;
	getline(cin, s);
	Trie::trie_cnt = 1;
	Trie::node.resize(1000001);
	Trie &root = Trie::node[0];
	for (int i = 0; i < s.size(); ++i) {
		root.insert(s, i);
	}
	cout << Trie::trie_cnt - 1 << "\n";
	return 0;
}
