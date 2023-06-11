#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;
using iii = tuple<int, int, int>;

const int INF = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, K{};
	cin >> N >> K;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	vector<ii> B(N);
	for (int i = 0; i < N; ++i) {
		B[i] = {A[i], i};
	}
	sort(B.rbegin(), B.rend());
	vector<int> L(N, -1);
	vector<int> C(N, 1);
	for (int i = 0; i < N; ++i) {
		int x = B[i].second;
		L[x] = 1;
		for (int j = x + 1; j < N; ++j) {
			if (L[j] == -1) {
				continue;
			}
			if (L[x] < L[j] + 1) {
				L[x] = L[j] + 1;
				C[x] = 0;
			}
			if (L[x] == L[j] + 1) {
				C[x] = min(C[x] + C[j], INF);
			}
		}
	}
	int maxl = *max_element(L.begin(), L.end());
	vector<vector<iii>> D(maxl + 1);
	for (int i = 0; i < N; ++i) {
		D[L[i]].push_back({A[i], i, C[i]});
	}
	for (int i = 1; i < D.size(); ++i) {
		sort(D[i].begin(), D[i].end());
	}
	vector<int> E;
	for (int i = maxl; i > 0; --i) {
		for (auto &[a, b, c] : D[i]) {
			if (E.size() && A[E.back()] > a) {
				continue;
			} else if (K > c) {
				K -= c;
			} else {
				E.push_back(b);
				break;
			}
		}
	}
	if (E.size() == maxl) {
		for (int i = 0; i < maxl; ++i) {
			cout << A[E[i]] << (i == maxl - 1 ? "\n" : " ");
		}
	} else {
		cout << "-1\n";
	}
	return 0;
}
