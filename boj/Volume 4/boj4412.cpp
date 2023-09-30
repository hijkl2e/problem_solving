#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> G;

struct Trie {
	Trie() {
		str_id = -1;
		memset(next, -1, sizeof next);
	}
	void insert(string &s, int i, int id) {
		if (i == s.size()) {
			str_id = id;
			return;
		}
		int j = s[i] - 'a';
		if (next[j] == -1) {
			next[j] = trie_cnt++;
		}
		node[next[j]].insert(s, i + 1, id);
	}
	void make_edge(string &s, int i, int id, bool f) {
		if (i == s.size()) {
			if (f && str_id != -1) {
				G[id].push_back(str_id);
				G[str_id].push_back(id);
			}
			return;
		}
		int j = s[i] - 'a';
		for (int k = f ? j : 0; k < (f ? j + 1 : 26); ++k) {
			if (next[k] != -1) {
				node[next[k]].make_edge(s, i + 1, id, f || (k != j));
			}
		}
	}
	int find(string &s, int i) {
		if (i == s.size()) {
			return str_id;
		}
		int j = s[i] - 'a';
		return next[j] == -1 ? -1 : node[next[j]].find(s, i + 1);
	}
	int str_id{};
	int next[26]{};
	static int trie_cnt;
	static vector<Trie> node;
};

int Trie::trie_cnt;
vector<Trie> Trie::node;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	Trie::trie_cnt = 1;
	Trie::node.resize(444444);
	Trie &root = Trie::node[0];
	string S;
	vector<string> A;
	while (getline(cin, S), S != "") {
		A.push_back(S);
	}
	G.resize(A.size());
	for (int i = 0; i < A.size(); ++i) {
		root.insert(A[i], 0, i);
		root.make_edge(A[i], 0, i, false);
	}
	string T;
	vector<int> D(A.size());
	vector<int> par(A.size());
	for (int tc = 0; cin >> S >> T; ++tc) {
		if (tc) {
			cout << "\n";
		}
		if (S.size() != T.size()) {
			cout << "No solution.\n";
			continue;
		}
		int s = root.find(S, 0);
		int t = root.find(T, 0);
		if (s == -1 || t == -1) {
			cout << "No solution.\n";
			continue;
		}
		fill(D.begin(), D.end(), -1);
		queue<int> q;
		D[s] = 0;
		q.push(s);
		while (q.size()) {
			int x = q.front(); q.pop();
			for (int y : G[x]) {
				if (D[y] == -1) {
					D[y] = D[x] + 1;
					par[y] = x;
					q.push(y);
				}
			}
		}
		if (D[t] == -1) {
			cout << "No solution.\n";
			continue;
		}
		stack<int> st;
		st.push(t);
		while (s != t) {
			t = par[t];
			st.push(t);
		}
		while (st.size()) {
			cout << A[st.top()] << "\n";
			st.pop();
		}
	}
	return 0;
}
