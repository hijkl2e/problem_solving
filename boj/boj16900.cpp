#include <bits/stdc++.h>

using namespace std;

using ll = long long;

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
	int K{};
	cin >> S >> K;
	vector<int> pi = get_pi(S);
	ll ans = K * (S.size() - pi.back()) + pi.back();
	cout << ans << "\n";
	return 0;
}
