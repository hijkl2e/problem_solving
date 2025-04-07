#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, X{};
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	sort(A.begin(), A.end());
	cin >> X;
	int p1 = 0, p2 = N - 1;
	int ans{};
	while (p1 < p2) {
		if (A[p1] + A[p2] < X) {
			++p1;
		} else if (A[p1] + A[p2] > X) {
			--p2;
		} else {
			++p1, --p2, ++ans;
		}
	}
	cout << ans << "\n";
	return 0;
}
