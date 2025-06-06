#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	int sum = accumulate(A.begin(), A.end(), 0);
	string ans;
	if (sum < 0) {
		ans = "Left";
	} else if (sum > 0) {
		ans = "Right";
	} else {
		ans = "Stay";
	}
	cout << ans << "\n";
	return 0;
}
