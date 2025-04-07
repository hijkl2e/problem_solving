#include <bits/stdc++.h>

using namespace std;

void solve(int n, int a, int b) {
	if (n == 0) {
		return;
	}
	solve(n - 1, a, a ^ b);
	cout << a << " " << b << "\n";
	solve(n - 1, a ^ b, b);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	cout << (1 << N) - 1 << "\n";
	solve(N, 1, 3);
	return 0;
}
