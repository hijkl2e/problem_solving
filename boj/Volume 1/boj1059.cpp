#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int L{};
	cin >> L;
	vector<int> A(L + 1);
	for (int i = 0; i < L; ++i) {
		cin >> A[i];
	}
	sort(A.begin(), A.end());
	int N{};
	cin >> N;
	int p = lower_bound(A.begin(), A.end(), N) - A.begin();
	int ans = max((N - A[p - 1]) * (A[p] - N) - 1, 0);
	cout << ans << "\n";
	return 0;
}
