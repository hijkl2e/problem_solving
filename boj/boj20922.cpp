#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, K{};
	cin >> N >> K;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	vector<int> B(100001);
	int ans{}, p{};
	for (int i = 0; i < N; ++i) {
		++B[A[i]];
		while (B[A[i]] == K + 1) {
			--B[A[p++]];
		}
		ans = max(ans, i - p + 1);
	}
	cout << ans << "\n";
	return 0;
}
