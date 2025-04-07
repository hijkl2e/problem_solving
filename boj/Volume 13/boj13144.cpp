#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	vector<int> B(100001);
	ll ans{};
	for (int i = 0, j = -1; i < N; ++i) {
		while (j + 1 < N && B[A[j + 1]] == 0) {
			++B[A[++j]];
		}
		ans += j - i + 1;
		--B[A[i]];
	}
	cout << ans << "\n";
	return 0;
}
