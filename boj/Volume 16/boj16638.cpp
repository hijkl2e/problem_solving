#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll INF = 4e18;

ll N, ans;
vector<ll> A;
vector<char> B;
deque<bool> C;

ll calc(ll x, char op, ll y) {
	if (op == '+') {
		return x + y;
	} else if (op == '-') {
		return x - y;
	} else {
		return x * y;
	}
}

void solve(int n) {
	if (n == N / 2) {
		vector<ll> D = A;
		vector<char> E = B;
		for (int i = N / 2 - 1; i >= 0; --i) {
			if (C[i]) {
				D[i + 1] = calc(D[i], E[i], D[i + 1]);
				D.erase(D.begin() + i);
				E.erase(E.begin() + i);
			}
		}
		for (int k = 0; k < 2; ++k) {
			for (int i = 0; i < E.size(); ++i) {
				if (k || E[i] == '*') {
					D[i + 1] = calc(D[i], E[i], D[i + 1]);
					D.erase(D.begin() + i);
					E.erase(E.begin() + i);
					--i;
				}
			}
		}
		ans = max(ans, D[0]);
		return;
	}
	if (B[n] != '*' && (n == 0 || !C[n - 1])) {
		C[n] = true;
		solve(n + 1);
		C[n] = false;
	}
	solve(n + 1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N;
	cin.ignore();
	string S;
	getline(cin, S);
	A.resize((N + 1) / 2);
	B.resize(N / 2);
	for (int i = 0; i < N; ++i) {
		if (i % 2) {
			B[i / 2] = S[i];
		} else {
			A[i / 2] = S[i] - '0';
		}
	}
	C.resize(N / 2);
	ans = -INF;
	solve(0);
	cout << ans << "\n";
	return 0;
}
