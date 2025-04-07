#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	while (cin >> N, N != -1) {
		vector<int> A;
		for (int i = 1; i * i <= N; ++i) {
			if (N % i == 0) {
				A.push_back(i);
				if (i * i < N) {
					A.push_back(N / i);
				}
			}
		}
		if (accumulate(A.begin(), A.end(), 0) == 2 * N) {
			sort(A.begin(), A.end());
			A.erase(--A.end());
			cout << N << " = ";
			for (int i = 0; i < A.size(); ++i) {
				cout << A[i] << (i == A.size() - 1 ? "\n" : " + ");
			}
		} else {
			cout << N << " is NOT perfect.\n";
		}
	}
	return 0;
}
