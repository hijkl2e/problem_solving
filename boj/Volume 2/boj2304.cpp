#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(1005);
	while (N--) {
		int x{}, y{};
		cin >> x >> y;
		A[x] = y;
	}
	vector<int> L(1005);
	vector<int> R(1005);
	for (int i = 1; i < L.size(); ++i) {
		L[i] = max(L[i - 1], A[i]);
	}
	for (int i = R.size() - 2; i > 0; --i) {
		R[i] = max(R[i + 1], A[i]);
	}
	int ans{};
	for (int i = 1; i < L.size(); ++i) {
		ans += min(L[i], R[i]);
	}
	cout << ans << "\n";
	return 0;
}
