#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	deque<bool> A(730);
	while (N > 1 && (N >= A.size() || !A[N])) {
		if (N < A.size()) {
			A[N] = true;
		}
		int sum{};
		while (N) {
			int r = N % 10;
			sum += r * r;
			N /= 10;
		}
		N = sum;
	}
	cout << (N == 1 ? "HAPPY" : "UNHAPPY") << "\n";
	return 0;
}
