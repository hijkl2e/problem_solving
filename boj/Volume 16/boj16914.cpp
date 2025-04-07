#include <bits/stdc++.h>

using namespace std;

using ll = long long;

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
	assert(s.back() == '$');
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
	assert(s.back() == '$');
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
	string S;
	getline(cin, S);
	int n = S.size();
	S += "$";
	vector<int> sa = get_sa(S);
	vector<int> lcp = get_lcp(S, sa);
	vector<ll> A(n + 1);
	for (int i = 1; i <= n; ++i) {
		A[i] = n - sa[i] - lcp[i];
	}
	partial_sum(A.begin(), A.end(), A.begin());
	int Q{};
	cin >> Q;
	while (Q--) {
		int k{};
		cin >> k;
		int p = lower_bound(A.begin(), A.end(), k) - A.begin();
		if (p == n + 1) {
			cout << "-1\n";
		} else {
			cout << S.substr(sa[p], n - sa[p] - A[p] + k) << "\n";
		}
	}
	return 0;
}
