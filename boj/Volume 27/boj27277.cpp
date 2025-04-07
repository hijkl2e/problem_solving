#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(N + 1);
	for (int i = 1; i <= N; ++i) {
		cin >> A[i];
	}
	sort(A.begin(), A.end());
	int ans{};
	for (int i = 0; i < (N + 1) / 2; ++i) {
		ans += A[N - i] - A[i];
	}
	cout << ans << "\n";
	return 0;
}
