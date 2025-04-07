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
	pi.insert(pi.begin(), -1);
	vector<ii> A;
	for (int i = 1; i < pi.size(); ++i) {
		if (i % (i - pi[i]) == 0 && i / (i - pi[i]) > 1) {
			A.push_back({i, i / (i - pi[i])});
		}
	}
	for (auto &[u, v] : A) {
		cout << u << " " << v << "\n";
	}
	return 0;
}
