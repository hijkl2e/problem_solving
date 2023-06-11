#include <bits/stdc++.h>

using namespace std;

struct Trie {
	void insert(string &s, int i) {
		if (i == s.size()) {
			end = true;
			return;
		}
		int j = s[i] - 'a';
		if (go[j] == 0) {
			go[j] = trie_cnt++;
		}
		node[go[j]].insert(s, i + 1);
	}
	bool end{};
	int go[26]{};
	int fail{};
	static int trie_cnt;
	static vector<Trie> node;
};

int Trie::trie_cnt;
vector<Trie> Trie::node;

Trie &node(int x) {
	return Trie::node[x];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	Trie::trie_cnt = 1;
	Trie::node.resize(100005);
	Trie &root = Trie::node[0];
	int N{};
	cin >> N;
	cin.ignore();
	while (N--) {
		string s;
		getline(cin, s);
		root.insert(s, 0);
	}
	queue<int> q;
	for (int i = 0; i < 26; ++i) {
		if (root.go[i]) {
			q.push(root.go[i]);
		}
	}
	while (q.size()) {
		Trie &t = node(q.front()); q.pop();
		for (int i = 0; i < 26; ++i) {
			if (t.go[i] == 0) {
				continue;
			}
			int &f = node(t.go[i]).fail;
			f = t.fail;
			while (f && node(f).go[i] == 0) {
				f = node(f).fail;
			}
			f = node(f).go[i];
			node(t.go[i]).end |= node(f).end;
			q.push(t.go[i]);
		}
	}
	int Q{};
	cin >> Q;
	cin.ignore();
	while (Q--) {
		string s;
		getline(cin, s);
		int t{};
		bool yes{};
		for (int i = 0; i < s.size(); ++i) {
			int j = s[i] - 'a';
			while (t && node(t).go[j] == 0) {
				t = node(t).fail;
			}
			t = node(t).go[j];
			if (node(t).end) {
				yes = true;
				break;
			}
		}
		cout << (yes ? "YES" : "NO") << "\n";
	}
	return 0;
}
