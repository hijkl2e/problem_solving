#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<int> A{2, 3, 5, 7, 11, 13, 17, 19};
	vector<int> B(8);
	for (int i = 0; i < 8; ++i) {
		cin >> B[i];
	}
	int ans{};
	while (true) {
		++B[0];
		for (int i = 0; i < 7; ++i) {
			if (B[i] == A[i]) {
				++B[i + 1];
				B[i] = 0;
			}
		}
		if (B[7] == 19) {
			break;
		}
		++ans;
	}
	cout << ans << "\n";
	return 0;
}
