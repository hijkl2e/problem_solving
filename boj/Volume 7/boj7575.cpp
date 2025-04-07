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

vector<int> kmp(vector<int> &s, vector<int> &p, vector<int> &pi) {
	vector<int> ret;
	for (int i = 0, j = 0; i < s.size(); ++i) {
		while (j && s[i] != p[j]) {
			j = pi[j - 1];
		}
		if (s[i] == p[j] && ++j == p.size()) {
			ret.push_back(i - j + 1);
			j = pi[j - 1];
		}
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, K{};
	cin >> N >> K;
	vector<vector<int>> A(N);
	for (int i = 0; i < N; ++i) {
		int M{};
		cin >> M;
		A[i].resize(M);
		for (int j = 0; j < M; ++j) {
			cin >> A[i][j];
		}
	}
	bool yes{};
	for (int i = 0; i + K <= A[0].size(); ++i) {
		vector<int> s1, s2;
		copy(A[0].begin() + i, A[0].begin() + i + K, back_inserter(s1));
		s2 = s1;
		reverse(s2.begin(), s2.end());
		vector<int> pi1 = get_pi(s1);
		vector<int> pi2 = get_pi(s2);
		yes = true;
		for (int j = 0; j < N; ++j) {
			if (kmp(A[j], s1, pi1).empty() && kmp(A[j], s2, pi2).empty()) {
				yes = false;
				break;
			}
		}
		if (yes) {
			break;
		}
		yes = false;
	}
	cout << (yes ? "YES" : "NO") << "\n";
	return 0;
}
