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
	int ans = -1;
	for (int i = 1; N / i > 1; ++i) {
		bool yes = true;
		for (int j = 2; i * j <= N; ++j) {
			if (A[i * (j - 1)] >= A[i * j]) {
				yes = false;
				break;
			}
		}
		if (yes) {
			ans = i;
			break;
		}
	}
	if (ans == -1) {
		cout << "ABORT!\n";
	} else {
		cout << ans << "\n";
	}
	return 0;
}
