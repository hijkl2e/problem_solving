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
	for (int i = 0; i < N; ++i) {
		if (i == 0 || A[i - 1] + 1 < A[i]) {
			ans += A[i];
		}
	}
	cout << ans << "\n";
	return 0;
}
