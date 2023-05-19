#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, B{};
	while (cin >> N >> B, N != -1) {
		vector<int> A(N);
		for (int i = 0; i < N; ++i) {
			cin >> A[i];
		}
		int lo = 0, hi = 5e6;
		while (lo + 1 < hi) {
			int mid = (lo + hi) / 2;
			int cnt{};
			for (int i = 0; i < N; ++i) {
				cnt += (A[i] - 1) / mid + 1;
			}
			if (cnt > B) {
				lo = mid;
			} else {
				hi = mid;
			}
		}
		cout << hi << "\n";
	}
	return 0;
}
