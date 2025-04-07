#include <bits/stdc++.h>

using namespace std;

struct Trie {
	void insert(string &s, int i) {
		if (i == s.size()) {
			end = true;
			return;
		}
		int j = s[i] == 'A' ? 0 : s[i] == 'G' ? 1 : s[i] == 'T' ? 2 : 3;
		if (go[j] == 0) {
			go[j] = trie_cnt++;
		}
		node[go[j]].insert(s, i + 1);
	}
	bool end{};
	int go[4]{};
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
	int T{};
	cin >> T;
	while (T--) {
		Trie::trie_cnt = 1;
		Trie::node.assign(500005, {});
		Trie &root = Trie::node[0];
		int N{}, M{};
		cin >> N >> M;
		cin.ignore();
		string S, T;
		getline(cin, S);
		getline(cin, T);
		root.insert(T, 0);
		for (int i = 0; i < T.size(); ++i) {
			for (int j = i + 1; j < T.size(); ++j) {
				reverse(T.begin() + i, T.begin() + j + 1);
				root.insert(T, 0);
				reverse(T.begin() + i, T.begin() + j + 1);
			}
		}
		queue<int> q;
		for (int i = 0; i < 4; ++i) {
			if (root.go[i]) {
				q.push(root.go[i]);
			}
		}
		while (q.size()) {
			Trie &t = node(q.front()); q.pop();
			for (int i = 0; i < 4; ++i) {
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
		int ans{}, t{};
		for (int i = 0; i < S.size(); ++i) {
			int j = S[i] == 'A' ? 0 : S[i] == 'G' ? 1 : S[i] == 'T' ? 2 : 3;
			while (t && node(t).go[j] == 0) {
				t = node(t).fail;
			}
			t = node(t).go[j];
			if (node(t).end) {
				++ans;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
