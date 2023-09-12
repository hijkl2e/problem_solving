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

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	string S;
	for (int i = 0; i < N; ++i) {
		char c{};
		cin >> c;
		S += c;
	}
	string T = S;
	reverse(T.begin(), T.end());
	S += "$" + T + "#";
	vector<int> sa = get_sa(S);
	vector<int> ra(sa.size());
	for (int i = 0; i < ra.size(); ++i) {
		ra[sa[i]] = i;
	}
	T.clear();
	int p1 = 0, p2 = N + 1;
	while (T.size() < N) {
		if (ra[p1] < ra[p2]) {
			T += S[p1++];
		} else {
			T += S[p2++];
		}
	}
	for (int i = 0; i < N; ++i) {
		if (i && i % 80 == 0) {
			cout << "\n";
		}
		cout << T[i];
	}
	cout << "\n";
	return 0;
}
