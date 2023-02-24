#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<int> A(5);
	for (int i = 0; i < 5; ++i) {
		cin >> A[i];
	}
	int sum{};
	for (int i = 0; i < 5; ++i) {
		sum += max(A[i], 40);
	}
	int ans = sum / 5;
	cout << ans << "\n";
	return 0;
}
