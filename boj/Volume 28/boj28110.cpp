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
	if (A[N - 1] - A[0] == N - 1) {
		cout << "-1\n";
		return 0;
	}
	int ans{}, d{};
	for (int i = 0; i < N - 1; ++i) {
		int x = (A[i + 1] - A[i]) / 2;
		if (d < x) {
			ans = A[i] + x;
			d = x;
		}
	}
	cout << ans << "\n";
	return 0;
}
