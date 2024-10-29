#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	for (int tc = 1; tc <= T; ++tc) {
		vector<int> A(5);
		for (int i = 0; i < 5; ++i) {
			cin >> A[i];
		}
		int ans = *max_element(A.begin(), A.end());
		cout << "Case #" << tc << ": " << ans << "\n";
	}
	return 0;
}
