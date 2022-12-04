#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

class UF {
public:
	UF(int N) : par(N), sz(N, 1) {
		for (int i = 0; i < N; ++i) {
			par[i] = i;
		}
	}
	int root(int x) {
		return par[x] == x ? x : (par[x] = root(par[x]));
	}
	bool same(int x, int y) {
		return root(x) == root(y);
	}
	bool unite(int x, int y) {
		x = root(x);
		y = root(y);
		if (x == y) {
			return false;
		}
		if (sz[x] < sz[y]) {
			swap(x, y);
		}
		par[y] = x;
		sz[x] += sz[y];
		return true;
	}
	int size(int x) {
		return sz[root(x)];
	}
private:
	vector<int> par, sz;
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	UF uf(2 * N);
	map<string, int> w2i;
	vector<ii> A;
	while (N--) {
		string s1, s2, s3;
		cin >> s1 >> s3 >> s2;
		reverse(s1.begin(), s1.end());
		reverse(s2.begin(), s2.end());
		int x = w2i.insert({s1, w2i.size()}).first->second;
		int y = w2i.insert({s2, w2i.size()}).first->second;
		if (s3 == "is") {
			uf.unite(x, y);
		} else {
			A.push_back({x, y});
		}
	}
	for (auto it1 = w2i.begin(); it1 != w2i.end();) {
		auto it2 = it1;
		++it2;
		while (it2 != w2i.end()) {
			int len = min(it1->first.size(), it2->first.size());
			len = min(len, 3);
			if (it1->first.substr(0, len) == it2->first.substr(0, len)) {
				uf.unite(it1->second, it2->second);
				++it2;
			} else {
				break;
			}
		}
		it1 = it2;
	}
	bool yes = true;
	for (auto &p : A) {
		if (uf.same(p.first, p.second)) {
			yes = false;
			break;
		}
	}
	cout << (yes ? "yes" : "wait what?") << "\n";
	return 0;
}
