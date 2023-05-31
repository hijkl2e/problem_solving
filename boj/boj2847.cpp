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
	for (int i = N - 2; i >= 0; --i) {
		int x = A[i] - A[i + 1] + 1;
		if (x > 0) {
			ans += x;
			A[i] = A[i + 1] - 1;
		}
	}
	cout << ans << "\n";
	return 0;
}
