#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	cin.ignore();
	vector<ll> A(10);
	deque<bool> B(10, true);
	while (N--) {
		string S;
		getline(cin, S);
		B[S[0] - 'A'] = false;
		reverse(S.begin(), S.end());
		ll x = 1;
		for (char c : S) {
			A[c - 'A'] += x;
			x *= 10;
		}
	}
	int p = -1;
	for (int i = 0; i < 10; ++i) {
		if (B[i] && (p == -1 || A[p] > A[i])) {
			p = i;
		}
	}
	swap(A[p], A[9]);
	sort(A.rbegin() + 1, A.rend());
	ll ans{};
	for (int i = 0; i < 10; ++i) {
		ans += (9 - i) * A[i];
	}
	cout << ans << "\n";
	return 0;
}
