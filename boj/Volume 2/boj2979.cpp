#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<int> A(4);
	for (int i = 1; i < 4; ++i) {
		cin >> A[i];
		A[i] *= i;
	}
	vector<int> B(101);
	for (int i = 0; i < 3; ++i) {
		int x{}, y{};
		cin >> x >> y;
		for (int j = x; j < y; ++j) {
			++B[j];
		}
	}
	int ans{};
	for (int x : B) {
		ans += A[x];
	}
	cout << ans << "\n";
	return 0;
}
