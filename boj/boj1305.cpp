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

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int L{};
	cin >> L;
	cin.ignore();
	string S;
	getline(cin, S);
	vector<int> pi = get_pi(S);
	int ans = L - pi.back();
	cout << ans << "\n";
	return 0;
}
