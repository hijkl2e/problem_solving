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
	sort(A.begin(), A.end());
	ll ans{};
	for (int i = 0; i < N; ++i) {
		ans += abs(A[i] - i - 1);
	}
	cout << ans << "\n";
	return 0;
}
