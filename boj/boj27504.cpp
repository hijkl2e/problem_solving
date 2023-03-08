#include <bits/stdc++.h>

using namespace std;

vector<int> get_pi(vector<int> &s) {
	vector<int> pi(s.size());
	for (int i = 1; i < pi.size(); ++i) {
		int j = pi[i - 1];
		while (j && s[i] != s[j]) {
			j = pi[j - 1];
		}
		if (s[i] == s[j]) {
			pi[i] = ++j;
		}
	}
	return pi;
}

bool kmp(vector<int> &s, vector<int> &p, vector<int> &pi) {
	for (int i = 0, j = 0; i < s.size(); ++i) {
		while (j && s[i] != p[j]) {
			j = pi[j - 1];
		}
		if (s[i] == p[j] && ++j == p.size()) {
			return true;
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<vector<int>> A(N);
	for (int i = 0; i < N; ++i) {
		int K{}, x{};
		cin >> K >> x;
		A[i].resize(K - 1);
		for (int j = 0; j < K - 1; ++j) {
			int y{};
			cin >> y;
			A[i][j] = x - y;
			x = y;
		}
	}
	int L{}, x{};
	cin >> L >> x;
	vector<int> B(L - 1);
	for (int i = 0; i < L - 1; ++i) {
		int y{};
		cin >> y;
		B[i] = x - y;
		x = y;
	}
	vector<int> pi = get_pi(B);
	vector<int> C;
	for (int i = 0; i < N; ++i) {
		if (kmp(A[i], B, pi)) {
			C.push_back(i + 1);
		}
	}
	if (C.empty()) {
		cout << "-1\n";
	} else {
		for (int i = 0; i < C.size(); ++i) {
			cout << C[i] << (i == C.size() - 1 ? "\n" : " ");
		}
	}
	return 0;
}
