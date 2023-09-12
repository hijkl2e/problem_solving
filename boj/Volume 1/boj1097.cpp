#include <bits/stdc++.h>

using namespace std;

vector<int> get_pi(string &s) {
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

vector<int> kmp(string &s, string &p) {
	vector<int> ret;
	vector<int> pi = get_pi(p);
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
	int N{};
	cin >> N;
	cin.ignore();
	vector<string> A(N);
	for (int i = 0; i < N; ++i) {
		getline(cin, A[i]);
	}
	int K{};
	cin >> K;
	vector<int> B(N);
	for (int i = 0; i < N; ++i) {
		B[i] = i;
	}
	int ans{};
	do {
		string S;
		for (int i = 0; i < N; ++i) {
			S += A[B[i]];
		}
		string T = S + S.substr(0, S.size() - 1);
		if (kmp(T, S).size() == K) {
			++ans;
		}
	} while (next_permutation(B.begin(), B.end()));
	cout << ans << "\n";
	return 0;
}
