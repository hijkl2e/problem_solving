#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int N{};
		cin >> N;
		vector<int> A(N);
		for (int i = 0; i < N; ++i) {
			cin >> A[i];
		}
		sort(A.begin(), A.end());
		int M{};
		cin >> M;
		while (M--) {
			int x{};
			cin >> x;
			cout << binary_search(A.begin(), A.end(), x) << "\n";
		}
	}
	return 0;
}
