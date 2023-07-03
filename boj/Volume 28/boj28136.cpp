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
	int p = min_element(A.begin(), A.end()) - A.begin();
	rotate(A.begin(), A.begin() + p, A.end());
	int ans = 1;
	for (int i = 0; i < N - 1; ++i) {
		if (A[i] >= A[i + 1]) {
			++ans;
		}
	}
	cout << ans << "\n";
	return 0;
}
