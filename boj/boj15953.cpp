#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<int> A{0, 1, 2, 4, 7, 11, 16, 22};
	vector<int> B{0, 1, 2, 4, 8, 16, 32};
	vector<int> C{0, 500, 300, 200, 50, 30, 10, 0};
	vector<int> D{0, 512, 256, 128, 64, 32, 0};
	int T{};
	cin >> T;
	while (T--) {
		int a{}, b{};
		cin >> a >> b;
		int ans{};
		ans += C[upper_bound(A.begin(), A.end(), a) - A.begin() - 1];
		ans += D[upper_bound(B.begin(), B.end(), b) - B.begin() - 1];
		ans *= 10000;
		cout << ans << "\n";
	}
	return 0;
}
