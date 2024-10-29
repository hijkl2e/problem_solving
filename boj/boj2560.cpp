#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int a{}, b{}, d{}, N{};
	cin >> a >> b >> d >> N;
	vector<int> A(N + 1);
	A[0] = 1;
	int x{};
	for (int i = 1; i <= N; ++i) {
		if (i >= a) {
			x = (x + A[i - a]) % 1000;
		}
		if (i >= b) {
			x = (x - A[i - b] + 1000) % 1000;
		}
		A[i] = x;
	}
	int ans = accumulate(A.begin() + max(N - d + 1, 0), A.end(), 0) % 1000;
	cout << ans << "\n";
	return 0;
}
