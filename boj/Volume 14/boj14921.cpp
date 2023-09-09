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
	int s = 0, e = N - 1;
	int ans = 1e9;
	while (s < e) {
		if (abs(ans) > abs(A[s] + A[e])) {
			ans = A[s] + A[e];
		}
		if (A[s] + A[e] < 0) {
			++s;
		} else if (A[s] + A[e] > 0) {
			--e;
		} else {
			break;
		}
	}
	cout << ans << "\n";
	return 0;
}
