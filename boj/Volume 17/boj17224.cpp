#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, L{}, K{};
	cin >> N >> L >> K;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		int a{}, b{};
		cin >> a >> b;
		A[i] = b <= L ? 140 : a <= L ? 100 : 0;
	}
	sort(A.rbegin(), A.rend());
	int ans = accumulate(A.begin(), A.begin() + K, 0);
	cout << ans << "\n";
	return 0;
}
