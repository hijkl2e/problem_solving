#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

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

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S;
	getline(cin, S);
	vector<int> pi = get_pi(S);
	vector<int> A(pi.size());
	for (int i = 0; i < pi.size(); ++i) {
		++A[pi[i]];
	}
	for (int i = pi.size() - 1; i > 0; --i) {
		A[pi[i - 1]] += A[i];
	}
	vector<ii> B;
	B.push_back({S.size(), 1});
	for (int i = pi.back(); i > 0; i = pi[i - 1]) {
		B.push_back({i, A[i] + 1});
	}
	reverse(B.begin(), B.end());
	cout << B.size() << "\n";
	for (auto &[u, v] : B) {
		cout << u << " " << v << "\n";
	}
	return 0;
}
