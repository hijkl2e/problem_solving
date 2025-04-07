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
	ll ans = accumulate(A.begin(), A.end(), 0LL) + *max_element(A.begin(), A.end());
	cout << ans / 2 << "." << (ans % 2 ? 5 : 0) << "\n";
	return 0;
}
