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
	ll sum = accumulate(A.begin(), A.end(), 0);
	ll ans{};
	for (int i = 0; i < N; ++i) {
		sum -= A[i];
		ans += A[i] * sum;
	}
	cout << ans << "\n";
	return 0;
}
