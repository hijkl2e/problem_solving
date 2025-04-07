#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S;
	getline(cin, S);
	int N{};
	cin >> N;
	cin.ignore();
	vector<int> A(26);
	while (N--) {
		string s;
		getline(cin, s);
		++A[s[0] - 'A'];
	}
	ll ans = 1;
	for (char c : S) {
		ans *= A[c - 'A']--;
	}
	if (S[0] == S[1] && S[1] == S[2]) {
		ans /= 6;
	} else if (S[0] == S[1] || S[1] == S[2] || S[2] == S[0]) {
		ans /= 2;
	}
	cout << ans << "\n";
	return 0;
}
