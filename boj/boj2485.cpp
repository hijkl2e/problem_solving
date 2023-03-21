#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	sort(A.begin(), A.end());
	int g{};
	for (int i = 0; i < N - 1; ++i) {
		g = gcd(g, A[i + 1] - A[i]);
	}
	int ans = (A[N - 1] - A[0]) / g - N + 1;
	cout << ans << "\n";
	return 0;
}
