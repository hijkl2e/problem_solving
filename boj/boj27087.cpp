#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		vector<int> A(3);
		for (int i = 0; i < 3; ++i) {
			cin >> A[i];
		}
		int p{};
		cin >> p;
		int cnt{};
		for (int i = 0; i < 3; ++i) {
			if (A[i] % p == 0) {
				++cnt;
			}
		}
		cout << cnt / 2 << "\n";
	}
	return 0;
}
