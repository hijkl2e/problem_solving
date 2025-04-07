#include <bits/stdc++.h>

using namespace std;

using si = pair<string, int>;

vector<int> get_sa(string &s) {
	assert(s.back() == '$');
	int n = s.size();
	vector<si> A(n);
	for (int i = 0; i < n; ++i) {
		A[i] = {s.substr(i), i};
	}
	sort(A.begin(), A.end());
	vector<int> sa(n);
	for (int i = 0; i < n; ++i) {
		sa[i] = A[i].second;
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
	string S, A, B;
	getline(cin, S);
	getline(cin, A);
	getline(cin, B);
	deque<bool> C(S.size());
	vector<int> D;
	int p = -1;
	while ((p = S.find(A, p + 1)) != -1) {
		C[p] = true;
	}
	while ((p = S.find(B, p + 1)) != -1) {
		D.push_back(p + B.size());
	}
	S += "$";
	vector<int> sa = get_sa(S);
	vector<int> lcp = get_lcp(S, sa);
	int min_len = max(A.size(), B.size()), ans{};
	for (int i = 1; i < S.size(); ++i) {
		if (C[sa[i]]) {
			ans += D.end() - lower_bound(D.begin(), D.end(), sa[i] + max(lcp[i] + 1, min_len));
		}
	}
	cout << ans << "\n";
	return 0;
}
