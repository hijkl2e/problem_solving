#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

struct Trie {
	void insert(const vector<int> &A, int i) {
		if (i == A.size()) {
			++cnt;
			return;
		}
		int j = lower_bound(next.begin(), next.end(), make_pair(A[i], -1)) - next.begin();
		if (j == next.size() || A[i] < next[j].first) {
			next.insert(next.begin() + j, {A[i], trie_cnt++});
		}
		node[next[j].second].insert(A, i + 1);
	}
	int find(const vector<int> &A, int i) {
		if (i == A.size()) {
			return cnt;
		}
		int j = lower_bound(next.begin(), next.end(), make_pair(A[i], -1)) - next.begin();
		if (j == next.size() || A[i] < next[j].first) {
			return cnt;
		} else {
			return node[next[j].second].find(A, i + 1) + cnt;
		}
	}
	int cnt{};
	vector<ii> next;
	static int trie_cnt;
	static vector<Trie> node;
};

int Trie::trie_cnt;
vector<Trie> Trie::node;

const vector<int> &s2v(string &s) {
	static vector<int> A;
	A.resize(s.size());
	for (int i = 0; i < A.size(); ++i) {
		A[i] = islower(s[i]) ? (s[i] - 'a') : isupper(s[i]) ? (s[i] - 'A' + 26) : (s[i] - '0' + 52);
	}
	static deque<bool> B(62);
	fill(B.begin(), B.end(), false);
	for (int i = 0; i < A.size(); ++i) {
		if (B[A[i]]) {
			A[i] = 62;
		} else {
			B[A[i]] = true;
		}
	}
	while (A.back() == 62) {
		A.pop_back();
	}
	return A;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	Trie::trie_cnt = 1;
	Trie::node.resize(8000005);
	Trie &root = Trie::node[0];
	int N{}, M{};
	cin >> N >> M;
	cin.ignore();
	while (N--) {
		string s;
		getline(cin, s);
		root.insert(s2v(s), 0);
	}
	while (M--) {
		string s;
		getline(cin, s);
		cout << root.find(s2v(s), 0) << "\n";
	}
	return 0;
}
