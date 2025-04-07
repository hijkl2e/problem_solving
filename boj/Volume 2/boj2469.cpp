#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int K{}, N{};
	cin >> K >> N;
	cin.ignore();
	string S(K, 'x');
	for (int i = 0; i < K; ++i) {
		S[i] = 'A' + i;
	}
	string T;
	getline(cin, T);
	vector<string> A(N);
	for (int i = 0; i < N; ++i) {
		getline(cin, A[i]);
	}
	int q{};
	while (A[q][0] != '?') {
		++q;
	}
	for (int i = 0; i < q; ++i) {
		for (int j = 0; j < K - 1; ++j) {
			if (A[i][j] == '-') {
				swap(S[j], S[j + 1]);
			}
		}
	}
	for (int i = N - 1; i > q; --i) {
		for (int j = 0; j < K - 1; ++j) {
			if (A[i][j] == '-') {
				swap(T[j], T[j + 1]);
			}
		}
	}
	string ans(K - 1, '*');
	for (int i = 0; i < K - 1; ++i) {
		if (S[i] == T[i]) {
			continue;
		} else if (S[i] == T[i + 1] && S[i + 1] == T[i]) {
			swap(S[i], S[i + 1]);
			ans[i] = '-';
		} else {
			ans = string(K - 1, 'x');
			break;
		}
	}
	cout << ans << "\n";
	return 0;
}
