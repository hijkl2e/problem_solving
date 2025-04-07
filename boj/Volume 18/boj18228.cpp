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
	auto it = find(A.begin(), A.end(), -1);
	int ans = *min_element(A.begin(), it) + *min_element(it + 1, A.end());
	cout << ans << "\n";
	return 0;
}
