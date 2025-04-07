#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<int> A(3);
	vector<int> B(3);
	for (int i = 0; i < 3; ++i) {
		cin >> A[i];
	}
	for (int i = 0; i < 3; ++i) {
		cin >> B[i];
	}
	int ans{};
	for (int i = 0; i < 3; ++i) {
		ans += max(B[i] - A[i], 0);
	}
	cout << ans << "\n";
	return 0;
}
