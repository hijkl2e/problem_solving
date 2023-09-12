#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;

struct Trie {
	void insert(string &s, int i) {
		if (i == s.size()) {
			end = min<int>(end, s.size());
			return;
		}
		int j = s[i] - 32;
		if (go[j] == 0) {
			go[j] = trie_cnt++;
		}
		node[go[j]].insert(s, i + 1);
	}
	int end = INF;
	int go[101]{};
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
	int N{}, M{};
	while (cin >> N >> M, N) {
		cin.ignore();
		Trie::trie_cnt = 1;
		Trie::node.assign(2001, {});
		Trie &root = Trie::node[0];
		while (N--) {
			string s;
			getline(cin, s);
			root.insert(s, 0);
		}
		queue<int> q;
		for (int i = 0; i < 101; ++i) {
			if (root.go[i]) {
				q.push(root.go[i]);
			}
		}
		while (q.size()) {
			Trie &t = node(q.front()); q.pop();
			for (int i = 0; i < 101; ++i) {
				if (t.go[i] == 0) {
					continue;
				}
				int &f = node(t.go[i]).fail;
				f = t.fail;
				while (f && node(f).go[i] == 0) {
					f = node(f).fail;
				}
				f = node(f).go[i];
				int &e = node(t.go[i]).end;
				e = min(e, node(f).end);
				q.push(t.go[i]);
			}
		}
		int ans{};
		while (M--) {
			string s;
			getline(cin, s);
			int t{}, p = -1;
			for (int i = 0; i < s.size(); ++i) {
				int j = s[i] - 32;
				while (t && node(t).go[j] == 0) {
					t = node(t).fail;
				}
				t = node(t).go[j];
				int e = node(t).end;
				if (e < INF && p < i - e + 1) {
					p = i;
					++ans;
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
