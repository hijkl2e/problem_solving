#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll ans;
vector<int> A, U;

void solve(int n, int v, int c, int l) {
	if (n == U.size()) {
		if (l == 0) {
			return;
		}
		for (int i = 2; i < A.size(); ++i) {
			if (A[i - 2] == A[i - 1] && A[i - 1] == A[i]) {
				return;
			}
		}
		ll res = 1;
		while (v--) {
			res *= 5;
		}
		while (c--) {
			res *= 20;
		}
		ans += res;
		return;
	}
	A[U[n]] = 0;
	solve(n + 1, v + 1, c, l);
	A[U[n]] = 1;
	solve(n + 1, v, c + 1, l);
	solve(n + 1, v, c, l + 1);
	A[U[n]] = -1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	set<char> vowel{'A', 'E', 'I', 'O', 'U'};
	string S;
	getline(cin, S);
	A.resize(S.size());
	for (int i = 0; i < A.size(); ++i) {
		A[i] = S[i] == '_' ? -1 : (vowel.find(S[i]) == vowel.end());
	}
	for (int i = 0; i < S.size(); ++i) {
		if (S[i] == '_') {
			U.push_back(i);
		}
	}
	solve(0, 0, 0, count(S.begin(), S.end(), 'L'));
	cout << ans << "\n";
	return 0;
}
