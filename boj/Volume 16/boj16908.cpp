#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;

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
	int N{};
	cin >> N;
	cin.ignore();
	string S;
	getline(cin, S);
	vector<string> A(--N);
	for (int i = 0; i < N; ++i) {
		getline(cin, A[i]);
	}
	vector<int> B(S.size(), INF);
	vector<int> C(S.size());
	for (int i = 0; i < N; ++i) {
		string T = S + "$" + A[i] + "#";
		vector<int> sa = get_sa(T);
		vector<int> lcp = get_lcp(T, sa);
		fill(C.begin(), C.end(), 0);
		int minv = INF;
		for (int i = 2; i < T.size(); ++i) {
			if (sa[i] < sa[1]) {
				minv = min(minv, lcp[i]);
				C[sa[i]] = max(C[sa[i]], minv);
			} else {
				minv = INF;
			}
		}
		minv = 0;
		for (int i = T.size() - 1; i > 1; --i) {
			if (sa[i] < sa[1]) {
				C[sa[i]] = max(C[sa[i]], minv);
				minv = min(minv, lcp[i]);
			} else {
				minv = lcp[i];
			}
		}
		for (int i = 0; i < C.size(); ++i) {
			B[i] = min(B[i], C[i]);
		}
	}
	int ans = *max_element(B.begin(), B.end());
	cout << ans << "\n";
	return 0;
}
