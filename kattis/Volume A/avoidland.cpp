#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(N + 1);
	vector<int> B(N + 1);
	for (int i = 1; i <= N; ++i) {
		cin >> A[i] >> B[i];
	}
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	int ans{};
	for (int i = 1; i <= N; ++i) {
		ans += abs(A[i] - i) + abs(B[i] - i);
	}
	cout << ans << "\n";
	return 0;
}
