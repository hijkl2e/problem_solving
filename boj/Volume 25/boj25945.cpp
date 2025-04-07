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
	int M = accumulate(A.begin(), A.end(), 0);
	int x = M / N, y = M % N;
	int ans{};
	for (int i = 0; i < N; ++i) {
		ans += max(A[i] - x, 0);
		if (A[i] > x && y-- > 0) {
			--ans;
		}
	}
	cout << ans << "\n";
	return 0;
}
