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
		vector<int> A(N + 1);
		for (int i = 1; i <= N; ++i) {
			int x{};
			cin >> x;
			A[x] = i;
		}
		vector<int> B;
		int maxv = A[1];
		for (int i = 2; i <= N; ++i) {
			if (A[i] < maxv) {
				B.push_back(i);
			}
			maxv = max(maxv, A[i]);
		}
		cout << B.size() << "\n";
		for (int x : B) {
			cout << x << "\n";
		}
	}
	return 0;
}
