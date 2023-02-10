#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> fibo(N + 2);
	fibo[1] = 1;
	for (int i = 2; i <= N; ++i) {
		fibo[i] = (fibo[i - 1] + fibo[i - 2]) % MOD;
	}
	cout << fibo[N] << "\n";
	return 0;
}
