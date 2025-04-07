#include <bits/stdc++.h>

using namespace std;

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
	int ans = N;
	for (int i = 0; i < N; ++i) {
		if (A[i] < i + 1) {
			ans = i;
			break;
		}
	}
	cout << ans << "\n";
	return 0;
}
