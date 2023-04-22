#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using iii = tuple<int, int, ll>;

int solve(ll x, ll y) {
	int ret{};
	while (x % y == 0) {
		x /= y;
		++ret;
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<iii> A(N);
	for (auto &[a, b, c] : A) {
		cin >> c;
		a = -solve(c, 3);
		b = solve(c, 2);
	}
	sort(A.begin(), A.end());
	for (int i = 0; i < N; ++i) {
		cout << get<2>(A[i]) << (i == N - 1 ? "\n" : " ");
	}
	return 0;
}
