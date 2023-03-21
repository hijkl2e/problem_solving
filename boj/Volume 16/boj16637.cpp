#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll INF = 4e18;

ll N, ans;
string S;

ll calc(ll x, char op, ll y) {
	if (op == '+') {
		return x + y;
	} else if (op == '-') {
		return x - y;
	} else {
		return x * y;
	}
}

void solve(ll n, ll x) {
	if (n == N) {
		ans = max(ans, x);
		return;
	}
	solve(n + 2, calc(x, S[n], S[n + 1] - '0'));
	if (n + 2 < N) {
		solve(n + 4, calc(x, S[n], calc(S[n + 1] - '0', S[n + 2], S[n + 3] - '0')));
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N;
	cin.ignore();
	getline(cin, S);
	ans = -INF;
	solve(1, S[0] - '0');
	cout << ans << "\n";
	return 0;
}
