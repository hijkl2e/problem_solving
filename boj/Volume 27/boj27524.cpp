#include <bits/stdc++.h>

using namespace std;

using ll = long long;

struct Trie {
	Trie() {
		memset(next, -1, sizeof next);
	}
	void insert(string &s, int i, ll X) {
		if (i == s.size()) {
			maxv += X - x;
			minv += X - x;
			x = X;
			return;
		}
		int j = s[i] - 'a';
		if (next[j] == -1) {
			next[j] = trie_cnt++;
		}
		node[next[j]].insert(s, i + 1, X);
		maxv = minv = 0;
		for (int j = 0; j < 26; ++j) {
			if (next[j] != -1) {
				maxv = max(maxv, node[next[j]].maxv);
				minv = min(minv, node[next[j]].minv);
			}
		}
		maxv += x;
		minv += x;
	}
	ll x{}, maxv{}, minv{};
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
	Trie::node.resize(1000005);
	Trie &pre = Trie::node[0];
	Trie &suf = Trie::node[1];
	int Q{};
	cin >> Q;
	while (Q--) {
		char q{};
		cin >> q;
		if (q == '+' || q == '-') {
			ll ans{};
			if (q == '+') {
				ans = pre.maxv + suf.maxv;
			} else {
				ans = pre.minv + suf.minv;
			}
			cout << ans << "\n";
			continue;
		}
		string S;
		ll X{};
		cin >> S >> X;
		if (q == '<') {
			pre.insert(S, 0, X);
		} else {
			reverse(S.begin(), S.end());
			suf.insert(S, 0, X);
		}
	}
	return 0;
}
