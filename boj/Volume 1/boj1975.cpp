#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<int> A(1001);
	for (int i = 1; i < A.size(); ++i) {
		for (int j = 2; j <= i; ++j) {
			int x = i;
			while (x % j == 0) {
				++A[i];
				x /= j;
			}
		}
	}
	int T{};
	cin >> T;
	while (T--) {
		int N{};
		cin >> N;
		cout << A[N] << "\n";
	}
	return 0;
}
