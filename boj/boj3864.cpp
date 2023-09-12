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
	int M{};
	while (cin >> M, M) {
		cin.ignore();
		string S;
		getline(cin, S);
		if (M == 1) {
			cout << S.size() << " 0\n";
			continue;
		}
		S += "$";
		vector<int> sa = get_sa(S);
		vector<int> lcp = get_lcp(S, sa);
		int ans{}, p{};
		priority_queue<int, vector<int>, greater<int>> pq1, pq2;
		priority_queue<int> pq3, pq4;
		pq3.push(sa[1]);
		for (int i = 2; i < M; ++i) {
			pq1.push(lcp[i]);
			pq3.push(sa[i]);
		}
		for (int i = M; i < lcp.size(); ++i) {
			pq1.push(lcp[i]);
			pq3.push(sa[i]);
			int minv = pq1.top();
			if (ans < minv) {
				ans = minv;
				p = pq3.top();
			} else if (ans == minv) {
				p = max(p, pq3.top());
			}
			pq2.push(lcp[i - M + 2]);
			pq4.push(sa[i - M + 1]);
			while (pq1.size() && pq2.size() && pq1.top() == pq2.top()) {
				pq1.pop();
				pq2.pop();
			}
			while (pq3.size() && pq4.size() && pq3.top() == pq4.top()) {
				pq3.pop();
				pq4.pop();
			}
		}
		if (ans) {
			cout << ans << " " << p << "\n";
		} else {
			cout << "none\n";
		}
	}
	return 0;
}
