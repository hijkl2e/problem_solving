#include <bits/stdc++.h>

using namespace std;

void counting_sort(vector<int> &sa, vector<int> &ra, int k) {
	static vector<int> fr, tsa;
	int n = sa.size();
	fr.assign(max(n + 1, 128), 0);
	for (int i = 0; i < n; ++i) {
		int x = i + k < n ? ra[i + k] : 0;
		++fr[x + 1];
	}
	partial_sum(fr.begin(), fr.end(), fr.begin());
	tsa.resize(n);
	for (int i = 0; i < n; ++i) {
		int x = sa[i] + k < n ? ra[sa[i] + k] : 0;
		tsa[fr[x]++] = sa[i];
	}
	swap(sa, tsa);
}

vector<int> get_sa(string &s) {
	assert(s.back() == '#');
	int n = s.size();
	vector<int> sa(n);
	vector<int> ra(n);
	for (int i = 0; i < n; ++i) {
		sa[i] = i;
		ra[i] = s[i];
	}
	vector<int> tra(n);
	for (int k = 1;; k *= 2) {
		counting_sort(sa, ra, k);
		counting_sort(sa, ra, 0);
		tra[sa[0]] = 0;
		for (int i = 1; i < n; ++i) {
			int &x = sa[i - 1], &y = sa[i];
			tra[y] = tra[x] + (ra[x] < ra[y] || ra[x + k] < ra[y + k]);
		}
		swap(ra, tra);
		if (ra[sa[n - 1]] == n - 1) {
			break;
		}
	}
	return sa;
}

vector<int> get_lcp(string &s, vector<int> &sa) {
	assert(s.back() == '#');
	int n = s.size();
	vector<int> ra(n);
	for (int i = 0; i < n; ++i) {
		ra[sa[i]] = i;
	}
	vector<int> lcp(n);
	for (int i = 0, k = 0; i < n - 1; ++i, k = max(k - 1, 0)) {
		int j = sa[ra[i] - 1];
		while (s[i + k] == s[j + k]) {
			++k;
		}
		lcp[ra[i]] = k;
	}
	return lcp;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		string A, B;
		cin >> A >> B;
		string S = A + "$" + B + "#";
		vector<int> sa = get_sa(S);
		vector<int> lcp = get_lcp(S, sa);
		int sz = A.size();
		vector<int> C(sz);
		for (int i = 3; i < sa.size(); ++i) {
			if ((sa[i - 1] < sa[1]) ^ (sa[i] < sa[1])) {
				int x = min(sa[i - 1], sa[i]);
				C[x] = max(C[x], lcp[i]);
			}
		}
		vector<int> D(sz);
		int cnt = sz;
		for (int i = 0; i < sz; ++i) {
			D[i] = A[i] == '(' ? ++cnt : cnt--;
		}
		vector<vector<int>> E(2 * sz + 1);
		for (int i = 0; i < sz; ++i) {
			if (A[i] == ')') {
				E[D[i]].push_back(i);
			}
		}
		int ans{};
		for (int i = 0; i < sz; ++i) {
			if (A[i] == ')' || C[i] == 0) {
				continue;
			}
			int e = i + C[i];
			auto &v1 = E[D[i] - 1];
			auto it = upper_bound(v1.begin(), v1.end(), i);
			if (it != v1.end()) {
				e = min(e, *it);
			}
			auto &v2 = E[D[i]];
			it = lower_bound(v2.begin(), v2.end(), e);
			if (it != v2.begin() && i < *--it) {
				ans = max(ans, *it - i + 1);
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
