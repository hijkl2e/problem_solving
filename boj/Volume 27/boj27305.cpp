#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void print(ll n, ll d, char c) {
	ll g = gcd(n, d);
	n /= g, d /= g;
	cout << n;
	if (d > 1) {
		cout << "/" << d;
	}
	cout << c;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		ll N{}, M{};
		cin >> N >> M;
		if (N == 0 || M == 0) {
			cout << "1 0 1 0\n";
			continue;
		} else if (N + M == 2) {
			cout << "2 0 2 0\n";
			continue;
		}
		ll n = 2 * N * M + N + M;
		ll d = N + M;
		print(n, d, ' ');
		n = N * M * (2 * N * M - N - M);
		d = (N + M) * (N + M - 1) / 2 * (N + M);
		print(n, d, ' ');
		n = 2 * N * M;
		d = N + M - 1;
		print(n, d, ' ');
		n = 2 * N * M * (N * M - N - M + 1);
		d = (N + M - 1) * (N + M - 2) / 2 * (N + M - 1);
		print(n, d, '\n');
	}
	return 0;
}
