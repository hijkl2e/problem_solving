#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<ll> fibo(N + 1);
	fibo[1] = 1;
	for (int i = 2; i <= N; ++i) {
		fibo[i] = fibo[i - 2] + fibo[i - 1];
	}
	cout << fibo[N] << "\n";
	return 0;
}
