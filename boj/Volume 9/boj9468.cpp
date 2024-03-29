#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int K{};
		cin >> K;
		vector<int> A(15);
		for (int i = 0; i < 15; ++i) {
			cin >> A[i];
		}
		int ans{};
		for (int i = 1; i < 14; ++i) {
			for (int j = i + 1; j < 15; ++j) {
				int minv = *min_element(A.begin() + i, A.begin() + j);
				if (A[i - 1] < minv && minv > A[j]) {
					++ans;
				}
			}
		}
		cout << K << " " << ans << "\n";
	}
	return 0;
}
