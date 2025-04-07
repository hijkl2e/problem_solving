#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(N);
	vector<int> B(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	for (int i = 0; i < N; ++i) {
		cin >> B[i];
	}
	int ans{};
	for (int i = 0; i < N; ++i) {
		ans += max(A[i] - B[i], 0);
	}
	cout << ans << "\n";
	return 0;
}
