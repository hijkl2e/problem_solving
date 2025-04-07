#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	int M = abs(N);
	vector<int> fibo(M + 1);
	fibo[1] = 1;
	for (int i = 2; i <= M; ++i) {
		fibo[i] = (fibo[i - 1] + fibo[i - 2]) % MOD;
	}
	cout << (N < 0 && N % 2 == 0 ? -1 : N == 0 ? 0 : 1) << "\n";
	cout << fibo[M] << "\n";
	return 0;
}
