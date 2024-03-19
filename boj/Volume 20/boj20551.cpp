#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	sort(A.begin(), A.end());
	while (M--) {
		int x{};
		cin >> x;
		int k = lower_bound(A.begin(), A.end(), x) - A.begin();
		cout << (k < N && A[k] == x ? k : -1) << "\n";
	}
	return 0;
}
