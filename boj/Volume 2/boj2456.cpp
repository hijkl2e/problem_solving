#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(3);
	vector<int> B(3);
	while (N--) {
		for (int i = 0; i < 3; ++i) {
			int x{};
			cin >> x;
			A[i] += x;
			if (x == 3) {
				++B[i];
			}
		}
	}
	int p{}, cnt{};
	for (int i = 0; i < 3; ++i) {
		if (A[p] < A[i] || (A[p] == A[i] && B[p] < B[i])) {
			p = i, cnt = 1;
		} else if (A[p] == A[i] && B[p] == B[i]) {
			++cnt;
		}
	}
	cout << (cnt == 1 ? p + 1 : 0) << " " << A[p] << "\n";
	return 0;
}
