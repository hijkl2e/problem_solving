#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int pow(int x, int y, int M) {
	int ret = 1;
	while (y) {
		if (y % 2) {
			ret = ret * x % M;
		}
		x = x * x % M;
		y /= 2;
	}
	return ret;
}

vector<int> fact;

int nCr(int x, int y, int M) {
	return fact[x] * pow(fact[x - y] * fact[y] % M, M - 2, M) % M;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll N{}, K{}, M{};
	cin >> N >> K >> M;
	fact.resize(M);
	fact[0] = 1;
	for (int i = 1; i < M; ++i) {
		fact[i] = i * fact[i - 1] % M;
	}
	int ans = 1;
	while (N) {
		ans = ans * nCr(N % M, K % M, M) % M;
		N /= M, K /= M;
	}
	cout << ans << "\n";
	return 0;
}
