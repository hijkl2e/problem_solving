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
	if (N < 3) {
		int ans = A[0] + (N == 2 ? A[1] - 1 : 0);
		cout << ans << "\n";
		return 0;
	}
	sort(A.rbegin(), A.rend());
	int p1{}, p2 = (N + 2) / 3, p3 = 2 * p2 - (N % 3 == 1);
	int ans = A[p1] + A[p2] + A[p3] - 3;
	cout << ans << "\n";
	return 0;
}
