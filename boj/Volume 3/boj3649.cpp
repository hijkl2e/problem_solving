#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int x{};
	while (cin >> x) {
		x *= 10000000;
		int N{};
		cin >> N;
		vector<int> A(N);
		for (int i = 0; i < N; ++i) {
			cin >> A[i];
		}
		sort(A.begin(), A.end());
		int s = 0, e = N - 1;
		while (s < e) {
			if (A[s] + A[e] < x) {
				++s;
			} else if (A[s] + A[e] > x) {
				--e;
			} else {
				break;
			}
		}
		if (s < e) {
			cout << "yes " << A[s] << " " << A[e] << "\n";
		} else {
			cout << "danger\n";
		}
	}
	return 0;
}
