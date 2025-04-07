#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int MOD = 1e6;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll N{};
	cin >> N;
	N %= 1500000;
	vector<int> fibo(N + 2);
	fibo[1] = 1;
	for (int i = 2; i <= N; ++i) {
		fibo[i] = (fibo[i - 1] + fibo[i - 2]) % MOD;
	}
	cout << fibo[N] << "\n";
	return 0;
}
