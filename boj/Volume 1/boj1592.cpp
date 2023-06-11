#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{}, L{};
	cin >> N >> M >> L;
	vector<int> A(N);
	int p{};
	while (++A[p] < M) {
		p = (p + (A[p] % 2 ? L : (N - L))) % N;
	}
	int ans = accumulate(A.begin(), A.end(), 0) - 1;
	cout << ans << "\n";
	return 0;
}
