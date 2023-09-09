#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<int> A(N);
	vector<string> B(N);
	for (int i = 0; i < N; ++i) {
		cin >> B[i] >> A[i];
	}
	while (M--) {
		int x{};
		cin >> x;
		int p = lower_bound(A.begin(), A.end(), x) - A.begin();
		cout << B[p] << "\n";
	}
	return 0;
}
