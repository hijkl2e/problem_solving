#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	while (true) {
		vector<int> A;
		while (true) {
			int x{};
			cin >> x;
			if (x <= 0) {
				break;
			}
			A.push_back(x);
		}
		if (A.empty()) {
			break;
		}
		int ans{};
		for (int i = 0; i < A.size(); ++i) {
			if (find(A.begin(), A.end(), 2 * A[i]) != A.end()) {
				++ans;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
