#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<ll> fibo(N + 1);
	fibo[0] = 1, fibo[1] = 2;
	for (int i = 2; i <= N; ++i) {
		fibo[i] = fibo[i - 1] + fibo[i - 2];
	}
	ll ans = 2 * fibo[N];
	cout << ans << "\n";
	return 0;
}
