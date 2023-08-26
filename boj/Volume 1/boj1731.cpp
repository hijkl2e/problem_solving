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
	int ans{};
	if (A[1] - A[0] == A[2] - A[1]) {
		ans = A[N - 1] + (A[1] - A[0]);
	} else {
		ans = A[N - 1] * (A[1] / A[0]);
	}
	cout << ans << "\n";
	return 0;
}
