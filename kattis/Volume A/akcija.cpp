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
	sort(A.rbegin(), A.rend());
	ll ans = accumulate(A.begin(), A.end(), 0LL);
	for (int i = 2; i < N; i += 3) {
		ans -= A[i];
	}
	cout << ans << "\n";
	return 0;
}
