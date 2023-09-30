#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, K{}, M{};
	cin >> N >> K >> M;
	deque<int> A(N);
	for (int i = 0; i < N; ++i) {
		A[i] = i + 1;
	}
	vector<int> B;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < K - 1; ++j) {
			A.push_back(A.front());
			A.pop_front();
		}
		B.push_back(A.front());
		A.pop_front();
		if (i % M == M - 1) {
			reverse(A.begin(), A.end());
		}
	}
	for (int i = 0; i < N; ++i) {
		cout << B[i] << "\n";
	}
	return 0;
}
