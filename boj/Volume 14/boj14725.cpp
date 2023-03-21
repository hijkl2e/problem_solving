#include <bits/stdc++.h>

using namespace std;

struct Trie {
	void insert(vector<string> &A, int i) {
		if (i == A.size()) {
			return;
		}
		auto res = next.insert({A[i], -1});
		int &x = res.first->second;
		if (res.second) {
			x = trie_cnt++;
		}
		node[x].insert(A, i + 1);
	}
	void print(int d) {
		for (auto &p : next) {
			cout << string(2 * d, '-') << p.first << "\n";
			node[p.second].print(d + 1);
		}
	}
	map<string, int> next;
	static int trie_cnt;
	static vector<Trie> node;
};

int Trie::trie_cnt;
vector<Trie> Trie::node;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	Trie::trie_cnt = 1;
	Trie::node.resize(15001);
	Trie &root = Trie::node[0];
	int N{};
	cin >> N;
	while (N--) {
		int K{};
		cin >> K;
		vector<string> A(K);
		for (int i = 0; i < K; ++i) {
			cin >> A[i];
		}
		root.insert(A, 0);
	}
	root.print(0);
	return 0;
}
