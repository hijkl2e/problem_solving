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
		vector<int> A(6);
		for (int i = 0; i < 6; ++i) {
			cin >> A[i];
		}
		int t = 1;
		while (true) {
			int sum = accumulate(A.begin(), A.end(), 0);
			if (N < sum) {
				break;
			}
			vector<int> B(A.begin(), A.end());
			for (int i = 0; i < 6; ++i) {
				for (int j = 1; j < 6; j += 2) {
					B[i] += A[(i + j) % 6];
				}
			}
			A = B;
			++t;
		}
		cout << t << "\n";
	}
	return 0;
}
