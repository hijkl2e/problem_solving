#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll INF = 4e18;

ll ans;

ll calc(ll x, char op, ll y) {
	if (op == '+') {
		return x + y;
	} else if (op == '-') {
		return x - y;
	} else {
		return x * y;
	}
}

void solve(vector<ll> &A, vector<char> &B) {
	if (A.size() == 1) {
		ans = max(ans, A[0]);
		return;
	}
	for (int i = 0; i < B.size(); ++i) {
		vector<ll> C = A;
		vector<char> D = B;
		C[i + 1] = calc(C[i], D[i], C[i + 1]);
		C.erase(C.begin() + i);
		D.erase(D.begin() + i);
		solve(C, D);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	cin.ignore();
	string S;
	getline(cin, S);
	vector<ll> A((N + 1) / 2);
	vector<char> B(N / 2);
	for (int i = 0; i < N; ++i) {
		if (i % 2) {
			B[i / 2] = S[i];
		} else {
			A[i / 2] = S[i] - '0';
		}
	}
	ans = -INF;
	solve(A, B);
	cout << ans << "\n";
	return 0;
}
