#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<int> A(5001);
	deque<bool> B(5001, true);
	for (int i = 1; i < A.size(); ++i) {
		int sum{};
		for (int j = 1; j < i; ++j) {
			if (i % j == 0) {
				sum += j;
				B[i] &= A[j] < 1;
			}
		}
		A[i] = sum < i ? -1 : sum > i ? 1 : 0;
		B[i] &= A[i] == 1;
	}
	int T{};
	cin >> T;
	while (T--) {
		int N{};
		cin >> N;
		cout << (B[N] ? "Good Bye" : "BOJ 2022") << "\n";
	}
	return 0;
}
