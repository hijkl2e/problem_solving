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
	sort(A.begin(), A.end());
	int ans{};
	while (A.size() > 1) {
		int x = A.back();
		A.pop_back();
		ans += x * A.back();
		A.back() += x;
	}
	cout << ans << "\n";
	return 0;
}
