#include <bits/stdc++.h>

using namespace std;

using iii = tuple<int, int, int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, K{};
	cin >> N >> K;
	vector<iii> A(N);
	for (int i = 0; i < N; ++i) {
		int k{}, x{}, y{}, z{};
		cin >> k >> x >> y >> z;
		A[k - 1] = {-x, -y, -z};
	}
	vector<iii> B(A.begin(), A.end());
	sort(A.begin(), A.end());
	int ans = lower_bound(A.begin(), A.end(), B[K - 1]) - A.begin() + 1;
	cout << ans << "\n";
	return 0;
}
