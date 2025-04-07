#include <bits/stdc++.h>

using namespace std;

struct Trie {
	Trie() {
		memset(next, -1, sizeof next);
	}
	void insert(string &s, int i) {
		if (i == s.size()) {
			end = true;
			return;
		}
		int j = s[i] - 'a';
		if (next[j] == -1) {
			next[j] = trie_cnt++;
		}
		node[next[j]].insert(s, i + 1);
	}
	void find(string &s, int i, deque<bool> &A) {
		A[i] = end;
		if (i == s.size()) {
			return;
		}
		int j = s[i] - 'a';
		if (next[j] != -1) {
			node[next[j]].find(s, i + 1, A);
		}
	}
	bool end{};
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
	Trie::node.resize(8000005);
	Trie &pre = Trie::node[0];
	Trie &suf = Trie::node[1];
	int C{}, N{};
	cin >> C >> N;
	cin.ignore();
	while (C--) {
		string s;
		getline(cin, s);
		pre.insert(s, 0);
	}
	while (N--) {
		string s;
		getline(cin, s);
		reverse(s.begin(), s.end());
		suf.insert(s, 0);
	}
	deque<bool> A(2001);
	deque<bool> B(2001);
	int Q{};
	cin >> Q;
	cin.ignore();
	while (Q--) {
		string s;
		getline(cin, s);
		fill(A.begin(), A.begin() + s.size(), false);
		fill(B.begin(), B.begin() + s.size(), false);
		pre.find(s, 0, A);
		reverse(s.begin(), s.end());
		suf.find(s, 0, B);
		bool yes{};
		for (int i = 1; i < s.size(); ++i) {
			if (A[i] && B[s.size() - i]) {
				yes = true;
				break;
			}
		}
		cout << (yes ? "Yes" : "No") << "\n";
	}
	return 0;
}
