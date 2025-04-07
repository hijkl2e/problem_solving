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
		A[i] = abs(A[i]);
	}
	int ans = 2 * accumulate(A.begin(), A.end(), 0);
	cout << ans << "\n";
	return 0;
}
