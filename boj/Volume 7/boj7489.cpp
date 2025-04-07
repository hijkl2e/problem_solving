#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<int> A(1001);
	vector<int> B(1001);
	vector<int> C(1001);
	A[0] = 1;
	for (int i = 1; i < 1001; ++i) {
		B[i] = B[i - 1];
		C[i] = C[i - 1];
		int j = i;
		while (j % 2 == 0) {
			++B[i];
			j /= 2;
		}
		while (j % 5 == 0) {
			++C[i];
			j /= 5;
		}
		while (B[i] && C[i]) {
			--B[i], --C[i];
		}
		A[i] = j * A[i - 1] % 10;
	}
	int T{};
	cin >> T;
	while (T--) {
		int N{};
		cin >> N;
		int ans = A[N];
		for (int i = 0; i < B[N]; ++i) {
			ans = 2 * ans % 10;
		}
		for (int i = 0; i < C[N]; ++i) {
			ans = 5 * ans % 10;
		}
		cout << ans << "\n";
	}
	return 0;
}
