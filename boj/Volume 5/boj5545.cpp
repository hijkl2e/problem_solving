#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, a{}, b{}, c{};
	cin >> N >> a >> b >> c;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	sort(A.rbegin(), A.rend());
	partial_sum(A.begin(), A.end(), A.begin());
	int ans = c / a;
	for (int i = 0; i < N; ++i) {
		ans = max(ans, (c + A[i]) / (a + (i + 1) * b));
	}
	cout << ans << "\n";
	return 0;
}
