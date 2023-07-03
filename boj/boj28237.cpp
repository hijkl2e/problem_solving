#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(4);
	for (int i = 1; i * i <= N; ++i) {
		if (N % i) {
			continue;
		}
		int a = i, c = N / i;
		for (int j = 1; j * j <= N + 2; ++j) {
			if ((N + 2) % j) {
				continue;
			}
			int b = j, d = (N + 2) / j;
			if (abs(a * d - b * c) == N + 1) {
				A[0] = a, A[1] = b, A[2] = c, A[3] = d;
				if (a * d - b * c > 0) {
					A[1] *= -1;
				} else {
					A[3] *= -1;
				}
				i = sqrt(N);
				break;
			}
		}
	}
	if (A[0]) {
		for (int i = 0; i < 4; ++i) {
			cout << A[i] << (i == 3 ? "\n" : " ");
		}
	} else {
		cout << "-1\n";
	}
	return 0;
}
