#include <bits/stdc++.h>

using namespace std;

struct Trie {
	void insert(string &s, int i, int x) {
		if (i == s.size()) {
			end = x;
			return;
		}
		int j = s[i] == 'o';
		if (go[j] == 0) {
			go[j] = trie_cnt++;
		}
		node[go[j]].insert(s, i + 1, x);
	}
	int end = -1, fail{};
	int go[2]{};
	static int trie_cnt;
	static vector<Trie> node;
};

int Trie::trie_cnt;
vector<Trie> Trie::node;

Trie &node(int x) {
	return Trie::node[x];
}

vector<int> get_pi(vector<int> &s) {
	vector<int> pi(s.size());
	for (int i = 1; i < pi.size(); ++i) {
		int j = pi[i - 1];
		while (j && s[i] != s[j]) {
			j = pi[j - 1];
		}
		if (s[i] == s[j]) {
			pi[i] = ++j;
		}
	}
	return pi;
}

vector<int> kmp(vector<int> &s, vector<int> &p, vector<int> &pi) {
	vector<int> ret;
	for (int i = 0, j = 0; i < s.size(); ++i) {
		while (j && s[i] != p[j]) {
			j = pi[j - 1];
		}
		if (s[i] == p[j] && ++j == p.size()) {
			ret.push_back(i - j + 1);
			j = pi[j - 1];
		}
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	Trie::trie_cnt = 1;
	Trie::node.resize(4000004);
	Trie &root = Trie::node[0];
	int hp{}, wp{}, hm{}, wm{};
	cin >> hp >> wp >> hm >> wm;
	cin.ignore();
	vector<string> A(hp);
	for (int i = 0; i < hp; ++i) {
		getline(cin, A[i]);
	}
	vector<string> B(hm);
	for (int i = 0; i < hm; ++i) {
		getline(cin, B[i]);
	}
	vector<string> C(A.begin(), A.end());
	sort(C.begin(), C.end());
	C.resize(unique(C.begin(), C.end()) - C.begin());
	vector<int> D(hp);
	for (int i = 0; i < hp; ++i) {
		D[i] = lower_bound(C.begin(), C.end(), A[i]) - C.begin();
	}
	for (int i = 0; i < C.size(); ++i) {
		root.insert(C[i], 0, i);
	}
	queue<int> q;
	for (int i = 0; i < 2; ++i) {
		if (root.go[i]) {
			q.push(root.go[i]);
		}
	}
	while (q.size()) {
		Trie &t = node(q.front()); q.pop();
		for (int i = 0; i < 2; ++i) {
			if (t.go[i] == 0) {
				continue;
			}
			int &f = node(t.go[i]).fail;
			f = t.fail;
			while (f && node(f).go[i] == 0) {
				f = node(f).fail;
			}
			f = node(f).go[i];
			q.push(t.go[i]);
		}
	}
	vector<vector<int>> E(wm, vector<int>(hm, -1));
	for (int i = 0; i < hm; ++i) {
		int t{};
		for (int j = 0; j < wm; ++j) {
			int k = B[i][j] == 'o';
			while (t && node(t).go[k] == 0) {
				t = node(t).fail;
			}
			t = node(t).go[k];
			if (node(t).end != -1) {
				E[j - wp + 1][i] = node(t).end;
			}
		}
	}
	vector<int> pi = get_pi(D);
	int ans{};
	for (int i = 0; i < wm; ++i) {
		ans += kmp(E[i], D, pi).size();
	}
	cout << ans << "\n";
	return 0;
}
