#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, L{};
	cin >> N >> L;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	sort(A.begin(), A.end());
	int ans{};
	for (int i = 0, j = 1; i < N; i = j++) {
		while (j < N && A[j] - A[i] < L) {
			++j;
		}
		++ans;
	}
	cout << ans << "\n";
	return 0;
}
