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
	int ans{};
	for (int i = N; i > 1; --i) {
		int x = find(A.begin(), A.end(), i) - A.begin();
		int maxv = max(x ? A[x - 1] : -1, x + 1 < A.size() ? A[x + 1] : -1);
		ans += i - maxv;
		A.erase(A.begin() + x);
	}
	cout << ans << "\n";
	return 0;
}
