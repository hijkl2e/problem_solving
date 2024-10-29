#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(5);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	int ans{};
	ans += (A[0] > A[2] ? 508 : 108) * abs(A[0] - A[2]);
	ans += (A[1] > A[3] ? 212 : 305) * abs(A[1] - A[3]);
	ans += 707 * A[4];
	ans *= 4763;
	cout << ans << "\n";
	return 0;
}
