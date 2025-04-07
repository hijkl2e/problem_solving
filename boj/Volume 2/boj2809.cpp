#include <bits/stdc++.h>

using namespace std;

struct Trie {
	void insert(string &s, int i) {
		if (i == s.size()) {
			end = s.size();
			return;
		}
		int j = s[i] - 'a';
		if (go[j] == 0) {
			go[j] = trie_cnt++;
		}
		node[go[j]].insert(s, i + 1);
	}
	int end{}, fail{};
	int go[26]{};
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
	int N{};
	cin >> N;
	cin.ignore();
	string S;
	getline(cin, S);
	int M{};
	cin >> M;
	cin.ignore();
	vector<string> A(M);
	for (int i = 0; i < M; ++i) {
		getline(cin, A[i]);
	}
	vector<int> B(N + 1);
	for (int i = 0; i < M; i += 100) {
		Trie::trie_cnt = 1;
		Trie::node.assign(500007, {});
		Trie &root = Trie::node[0];
		for (int j = 0; j < 100 && i + j < M; ++j) {
			root.insert(A[i + j], 0);
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
				int &end = node(t.go[i]).end;
				end = max(end, node(f).end);
				q.push(t.go[i]);
			}
		}
		int t{};
		for (int i = 0; i < S.size(); ++i) {
			int j = S[i] - 'a';
			while (t && node(t).go[j] == 0) {
				t = node(t).fail;
			}
			t = node(t).go[j];
			++B[i - node(t).end + 1];
			--B[i + 1];
		}
	}
	partial_sum(B.begin(), B.end(), B.begin());
	int ans = count(B.begin(), B.end() - 1, 0);
	cout << ans << "\n";
	return 0;
}
