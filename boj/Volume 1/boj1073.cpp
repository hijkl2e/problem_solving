#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(10);
	for (int i = 0; i < N; ++i) {
		int x{};
		cin >> x;
		++A[x / 10];
		++A[x % 10];
	}
	vector<int> B{
		1, 0, 1, 0, 3, 0, 15, 0, 105, 0
	};
	ll ans = 1;
	for (int i = 0; i < 10; ++i) {
		ans *= B[A[i]];
	}
	cout << ans << "\n";
	return 0;
}
