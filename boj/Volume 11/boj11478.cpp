#include <bits/stdc++.h>

using namespace std;

int trie_cnt;

struct Trie {
	Trie() : next(26) {
		++trie_cnt;
	}
	void insert(string &s, int i) {
		if (i == s.size()) {
			return;
		}
		int j = s[i] - 'a';
		if (next[j] == nullptr) {
			next[j] = new Trie();
		}
		next[j]->insert(s, i + 1);
	}
	vector<Trie *> next;
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string s;
	getline(cin, s);
	Trie *root = new Trie();
	for (int i = 0; i < s.size(); ++i) {
		root->insert(s, i);
	}
	cout << trie_cnt - 1 << "\n";
	return 0;
}
