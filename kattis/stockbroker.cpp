#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	ll x = 100;
	for (int i = 1; i < N; ++i) {
		x += max(A[i] - A[i - 1], 0) * min(x / A[i - 1], 100000LL);
	}
	cout << x << "\n";
	return 0;
}
