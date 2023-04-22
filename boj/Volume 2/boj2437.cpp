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
	int ans = 1;
	for (int i = 0; i < N; ++i) {
		if (ans < A[i]) {
			break;
		}
		ans += A[i];
	}
	cout << ans << "\n";
	return 0;
}
