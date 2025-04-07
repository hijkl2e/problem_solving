#include <bits/stdc++.h>

using namespace std;

void counting_sort(vector<int> &sa, vector<int> &ra, int k) {
	static vector<int> fr, tsa;
	int n = sa.size();
	fr.assign(n + 1, 0);
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

vector<int> get_sa(vector<int> &s) {
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
	int N{}, K{};
	cin >> N >> K;
	vector<int> A(2 * N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	reverse(A.begin(), A.begin() + N);
	copy(A.begin(), A.begin() + N - 1, A.begin() + N);
	vector<int> sa = get_sa(A);
	int p{};
	while (K--) {
		++p;
		while (sa[p] >= N || sa[p] == 0) {
			++p;
		}
	}
	rotate(A.begin(), A.begin() + sa[p], A.end());
	for (int i = 0; i < N; ++i) {
		cout << A[i] << (i == N - 1 ? "\n" : " ");
	}
	return 0;
}
